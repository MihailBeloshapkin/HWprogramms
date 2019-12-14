#include "list.h"
#include <stdio.h>

struct List
{
	int data;
	List *next;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return list == nullptr;
}

void addToListFront(List **list, int newData)
{
	List *newElement = new List{ newData, *list };
	*list = newElement;
}

void addToListBack(List **list, int newData)
{
	List *newElement = new List{ newData, nullptr };
	while (*list != nullptr)
	{
		list = &(*list)->next;
	}
	*list = newElement;
}

void display(List *list)
{
	while (list != nullptr)
	{
		printf("%i, ", list->data);
		list = list->next;
	}

}

void deleteFront(List **list)
{
	List *oldElement = *list;
	*list = (*list)->next;
	delete oldElement;
}

void deleteList(List **list)
{
	while (!isEmpty(*list))
	{
		deleteFront(list);
	}
}

int sizeOfList(List *list)
{
	int size = 0;
	while (list != nullptr)
	{
		size++;
		list = list->next;
	}
	return size;
}

bool compareLists(List *firstList, List *secondList)
{
	if (sizeOfList(firstList) != sizeOfList(secondList))
	{
		return false;
	}
	while (firstList != nullptr)
	{
		if (firstList->data != secondList->data)
		{
			return false;
		}
		firstList = firstList->next;
		secondList = secondList->next;
	}
	return true;
}

List *turnOverList(List *list)
{
	List *turnedList = createList();
	turnedList = nullptr;
	while (list != nullptr)
	{
		addToListFront(&turnedList, list->data);
		list = list->next;
	}
	return turnedList;
}
