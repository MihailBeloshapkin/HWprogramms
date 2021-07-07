#include "list.h"
#include <stdio.h>

struct List
{
	int data;
	List *next = nullptr;
};

List *createList()
{
	return new List;
}

int returnData(List *list)
{
	return list->data;
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
	return;
}

void addBack(List **list, int newData)
{
	List *newList = new List;
	newList->data = newData;
	(*list)->next = newList;
	return;
}

void add(List **list, int newData)
{
	List *newList = new List;
	List *copy = *list;
	if (*list == nullptr)
	{
		newList->data = newData;
		*list = newList;
		return;
	}
	else
	{
		if ((*list)->data > newData)
		{
			addFront(list, newData);
			return;
		}
		while ((*list)->next != nullptr && (*list)->next->data < newData)
		{
			list = &(*list)->next;
		}
		if ((*list)->next == nullptr)
		{
			addBack(list, newData);
			return;
		}
		else
		{
			list = &(*list)->next;
			newList = *list;
			addFront(&newList, newData);
			*list = newList;
		}
	}
}

void deleteData(List **list, int deleteData)
{
	if (isEmpty(*list))
	{
		printf("Emply list");
		return;
	}
	while ((*list)->next != nullptr)
	{
		list = &(*list)->next;
		if ((*list)->data == deleteData)
		{
			List *oldElement = *list;
			*list = (*list)->next;
			delete oldElement;
			return;
		}
	}
	printf("This element isn't included in this list\n");
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
		printf("%i, ", list->data);
		list = list->next;
	}
	printf("\n");
}