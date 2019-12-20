#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct List
{
	char *data;
	int count = 13;
	List *next;
};

bool isEmpty(List *list)
{
	return list == nullptr;
}

char *returnData(List *list)
{
	return list->data;
}

int returnCount(List *list)
{
	return list->count;
}

void shiftNext(List **list)
{
	*list = (*list)->next;
}

void deleteElement(List **list)
{
	List *oldData = *list;
	*list = (*list)->next;
	delete oldData->data;
	delete oldData;
}

void deleteList(List **list)
{
	while (!isEmpty(*list))
	{
		deleteElement(list);
	}
}

void addToList(List **list, char *newData)
{
	List *newElement = new List{ copy(newData), 1, nullptr };
	while ((*list) != nullptr)
	{
		if (strcmp((*list)->data, newData) == 0)
		{
			(*list)->count++;
			delete newElement->data;
			delete newElement;
			return;
		}
		list = &(*list)->next;
	}
	*list = newElement;
}

void displayList(List *list)
{
	while (list != nullptr)
	{
		printf("%s(%i); ", list->data, list->count);
		list = list->next;
	}
//	printf("\n");
}

void displayListToFile(List *list, FILE *file)
{
	while (list != nullptr)
	{
		fprintf(file, "%s(%i); ", list->data, list->count);
		list = list->next;
	}
	fprintf(file, "\n");
}