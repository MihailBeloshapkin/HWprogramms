#include <ctype.h>
#include <stdio.h>
#include "list.h"

void addToListBack(List **list, int newData)
{
	List *newElement = new List{ newData, nullptr };
	while (*list != nullptr)
	{
		list = &(*list)->next;
	}
	*list = newElement;
}

int digitScanner(char *str, int *index)
{
	int answer = 0;
	const int maxSize = 100;
	while (str[*index] != '\0' && *index < maxSize  && isdigit(str[*index]))
	{
		answer = answer * 10 + str[*index] - '0';
		(*index)++;
	}
	return answer;
}

void scanner(char *input, List **list)
{
	int index = 0;
	while (input[index] != '\0')
	{
		if (isdigit(input[index]))
		{
			addToListBack(list, digitScanner(input, &index));
		}
		else
		{
			index++;
		}
	}
}

void display(List *list)
{
	while (list != nullptr)
	{
		printf("%i, ", list->data);
		list = list->next;
	}

}

void deleteBack(List **list)
{
	while ((*list)->next->next != nullptr)
	{
		list = &(*list)->next;
	}
	List *oldData = (*list)->next;
	(*list)->next = nullptr;
	delete oldData;
}

bool isIncreasing(List *list)
{
	while (list->next != nullptr)
	{
		if (list->data >= list->next->data)
		{
			return false;
		}
		list = list->next;
	}
	return true;
}

List *searchLongest(List *list)
{
	List *answer = new List;
	List *currentHead =  list;
	int maxLength = 0;
	int currentLength = 0;
	int prevElement = list->data;
	list = list->next;
	while (list->next != nullptr)
	{
		if (list->data < list->next->data)
		{
			if (prevElement > list->data)
			{
				currentHead = list;
			}
			currentLength++;
		}
		else
		{
			currentLength = 0;
		}
		if (currentLength > maxLength)
		{
			maxLength = currentLength;
			answer = currentHead;
		}
		prevElement = list->data;
		list = list->next;
	}
	while (!isIncreasing(answer))
	{
		deleteBack(&answer);
	}
	return answer;
}