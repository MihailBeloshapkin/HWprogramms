#pragma once

struct Stack
{
	int data;
	Stack *next;
};


int push(Stack **stack, char newData);
int pop(Stack **stack);
bool isEmpty(Stack *S);