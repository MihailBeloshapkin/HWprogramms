#pragma once

// Description of structure.
struct Stack
{
	char data;
	Stack *next;
};

// Push data into stack. 
int push(Stack **stack, char newData);

// Delete data from stack.
int pop(Stack **stack);

// Check if stack is empty.  
bool isEmpty(Stack *S);

// Delete stack.
void deleteStack(Stack *stack);