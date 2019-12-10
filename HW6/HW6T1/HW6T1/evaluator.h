#pragma once

// structure stack
struct Stack
{
	int data;
	Stack *next;
};

// Push stack.
void push(Stack **stack, int newData);

// Pop stack.
int pop(Stack **stack);

// Display stack.
void display(Stack *stack);

// evaluation of postfix expression.
int eval(char *expr);

// testing evaluator
bool test();

// is empty function
bool isEmpty(Stack *stack);

// delete stack
void deleteStack(Stack *stack);