#include <stdio.h>
#include "list.h"

struct List
{
	int data;
	List *next;
};

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

bool checkThatSymmetric(List *list)
{
	List *firstList = nullptr;
	List *secondList = nullptr;
	int size = sizeOfList(list);
	for (int i = 0; i < size; i++)
	{
		if (size % 2 != 0 && i == size / 2)
		{
			list = list->next;
		}
		else
		{
			if (i <= size / 2 - 1)
			{
				addToListBack(&firstList, list->data);
			}
			if ((i >= size / 2))
			{
				addToListFront(&secondList, list->data);
			}
			list = list->next;
		}
	}
	bool isSymmetric = compareLists(firstList, secondList);
	deleteList(&firstList);
	deleteList(&secondList);
	return isSymmetric;
}