#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include "HW6T2.h"


int push(Stack **stack, char newData)
{
	Stack *newElement;
	if ((newElement = (Stack *)malloc(sizeof(Stack))) == nullptr)
		return -1;
	newElement->data = newData;
	newElement->next = *stack;
	*stack = newElement;
	return 1;
}

int pop(Stack **stack)
{
	Stack *oldElement = *stack;
	int oldData = (*stack)->data;
	*stack = (*stack)->next;
	delete oldElement;
	return oldData;
}

bool isEmpty(Stack *S)
{
	return (S == NULL);
}
