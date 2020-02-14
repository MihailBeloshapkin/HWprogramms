#include "list.h"
#include <stdio.h>

struct List
{
	int vertex;
	List* next = nullptr;
};

List* createList()
{
	return new List;
}

int returnVertex(List* list)
{
	return list->vertex;
}

void shiftNext(List** list)
{
	*list = (*list)->next;
}

bool isEmpty(List* list)
{
	return list == nullptr;
}

int sizeOfList(List* list)
{
	int size = 0;
	while (list != nullptr)
	{
		size++;
		list = list->next;
	}
	return size;
}

bool compareLists(List* list1, List* list2)
{
	if (sizeOfList(list1) != sizeOfList(list2))
	{
		return false;
	}
	while (list1 != nullptr)
	{
		if (list1->vertex != list2->vertex)
		{
			return false;
		}
		list1 = list1->next;
		list2 = list2->next;
	}
	return true;
}

void addFront(List** list, int newDistance, int newVertex)
{
	List* newList = new List;
	newList->vertex = newVertex;
	newList->next = *list;
	*list = newList;
}

void addBack(List** list, int newVertex)
{
	List* newList = new List;
	newList->vertex = newVertex;
	(*list)->next = newList;
}

void addToListBack(List** list, int newData)
{
	List* newElement = new List{newData, nullptr};
	while (*list != nullptr)
	{
		list = &(*list)->next;
	}
	*list = newElement;
}

int delFromListFront(List** list)
{
	List* oldData = *list;
	int deletedVertex = oldData->vertex;
	*list = (*list)->next;
	delete oldData;
	return deletedVertex;
}

void deleteVertex(List** list, int deleteVertex)
{
	if (isEmpty(*list))
	{
		return;
	}
	while (*list != nullptr)
	{
		if ((*list)->vertex == deleteVertex)
		{
			List* oldElement = *list;
			*list = (*list)->next;
			delete oldElement;
		}
		if (*list == nullptr)
		{
			return;
		}
		list = &(*list)->next;
	}
}

void deleteList(List** list)
{
	while (!isEmpty(*list))
	{
		delFromListFront(list);
	}
}

void displayList(List* list)
{
	while (list != nullptr)
	{
		printf("%i ", list->vertex);
		list = list->next;
	}
}