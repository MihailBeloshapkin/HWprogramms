#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackFunctions.h"

int push(Stack **stack, char newData)
{
	Stack *newElement = nullptr;
	if ((newElement = (Stack *)malloc(sizeof(Stack))) == nullptr)
	{
		return -1;
	}
	newElement->data = newData;
	newElement->next = *stack;
	*stack = newElement;
	return 1;
}

bool pop(Stack **stack, int *result)
{
	if (isEmpty(*stack))
	{
		return false;
	}
	Stack *oldElement = *stack;
	*result = (*stack)->data;
	*stack = (*stack)->next;
	delete oldElement;
	return true;
}

bool isEmpty(Stack *stack)
{
	return stack == nullptr;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
	{
		int answer = 0;
		pop(&stack, &answer);
	}
}
