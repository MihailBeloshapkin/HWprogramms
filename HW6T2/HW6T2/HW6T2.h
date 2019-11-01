#pragma once

struct Stack
{
	char data;
	Stack *next;
};

int push(Stack **stack, char newData);
int pop(Stack **stack);
bool isBalanced(char *expr, int size);
bool test();