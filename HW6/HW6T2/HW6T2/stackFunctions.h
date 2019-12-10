#pragma once

struct Stack
{
	int data;
	Stack *next;
};

// Push element into stack.
int push(Stack **stack, char newData);

// Pop element from stack and return this.
bool pop(Stack **stack, int *result);

// Check if stack is empty.
bool isEmpty(Stack *S);

// Delete filled stack.
void deleteStack(Stack *stack);