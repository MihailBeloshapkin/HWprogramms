#include "list.h"
#include <stdio.h>

struct List
{
	int data;
	int count = 1;
	List *next = nullptr;
};

int returnData(List *list)
{
	return list->data;
}

int returnCount(List *list)
{
	return list->count;
}

List *returnNextPointer(List *list)
{
	return list->next;
}

void shiftNext(List **list)
{
	*list = (*list)->next;
}

bool isEmpty(List *list)
{
	return list == nullptr;
}

void addFront(List **list, int newData)
{
	List *newList = new List;
	newList->data = newData;
	newList->next = *list;
	*list = newList;
}

void addBack(List **list, int newData)
{
	List *newList = new List;
	newList->data = newData;
	(*list)->next = newList;
}

void add(List **list, int newData)
{
	if (*list == nullptr)
	{
		*list = new List{ newData, 1 ,nullptr };
		return;
	}

	if ((*list)->data > newData)
	{
		addFront(list, newData);
		return;
	}
	while ((*list)->next != nullptr && (*list)->next->data <= newData)
	{
		list = &(*list)->next;
	}
	if (newData == (*list)->data)
	{
		(*list)->count++;
		return;
	}
	if ((*list)->next == nullptr)
	{
		addBack(list, newData);
		return;
	}
	else
	{
		list = &(*list)->next;
		auto newList = *list;
		addFront(&newList, newData);
		*list = newList;
	}
}

void deleteElement(List **list)
{
	List *oldData = *list;
	*list = (*list)->next;
	delete oldData;
}

void deleteList(List **list)
{
	while (!isEmpty(*list))
	{
		deleteElement(list);
	}
}

void display(List *list)
{
	if (list == nullptr)
	{
		printf("Empty list\n");
		return;
	}
	while (list != nullptr)
	{
		printf("%i(count:%i)\n", list->data, list->count);
		list = list->next;
	}
	printf("\n");
}