#include "list.h"

struct List
{
	int distance;
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

void addFront(List** list, int newDistance, int newVertex)
{
	List* newList = new List;
	newList->distance = newDistance;
	newList->vertex = newVertex;
	newList->next = *list;
	*list = newList;
}

void addBack(List** list, int newDistance, int newVertex)
{
	List* newList = new List;
	newList->distance = newDistance;
	newList->vertex = newVertex;
	(*list)->next = newList;
}

void add(List** list, int newDistance, int newVertex)
{
	if (*list == nullptr)
	{
		*list = new List{ newDistance, newVertex, nullptr };
		return;
	}

	if ((*list)->distance > newDistance)
	{
		addFront(list, newDistance, newVertex);
		return;
	}
	while ((*list)->next != nullptr && (*list)->next->distance < newDistance)
	{
		list = &(*list)->next;
	}
	if ((*list)->next == nullptr)
	{
		addBack(list, newDistance, newVertex);
		return;
	}
	else
	{
		list = &(*list)->next;
		auto newList = *list;
		addFront(&newList, newDistance, newVertex);
		*list = newList;
	}
}

int delFromListFront(List** list, int *deletedDistance)
{
	List* oldData = *list;
	int deletedVertex = oldData->vertex;
	*deletedDistance = oldData->distance;
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
	int deletedData = 0;
	while (!isEmpty(*list))
	{
		delFromListFront(list, &deletedData);
	}
}
