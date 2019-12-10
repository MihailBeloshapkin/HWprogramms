#include "pch.h"
#include "evaluator.h"
#include <stdio.h>
#include <stdlib.h>

void push(Stack **stack, int newData)
{
	Stack *newElement = new Stack;
	newElement->data = newData;
	newElement->next = *stack;
	*stack = newElement;
}

int pop(Stack **stack)
{
	Stack *oldElement = *stack;
	int oldData = (*stack)->data;
	*stack = (*stack)->next;
	delete oldElement;
	return oldData;
}

bool isEmpty(Stack *stack)
{
	return stack == nullptr;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
	{
		pop(&stack);
	}
}

void display(Stack *stack)
{
	if (stack == nullptr)
	{
		printf("STACK is empty\n");
	}
	while (stack != nullptr)
	{
		printf("%i, ", stack->data);
		stack = stack->next;
	}
}
