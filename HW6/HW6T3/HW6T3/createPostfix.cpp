#include "pch.h"
#include "stack.h"
#include <stdio.h>

int getPriority(char operation)
{
	switch (operation)
	{
	case '+':
	case '-':
		return 0;
	case '*':
	case '/':
		return 1;
	default:
		break;
	}
	return -1;
}

void input(char array[], int *index, char data)
{
	array[*index] = data;
	array[(*index) + 1] = ' ';
	(*index) += 2;
}

void createPostfix(char *expr, char *answer)
{
	int index = 0;
	int indexAnswer = 0;
	Stack *stackOfOperations = nullptr;
	bool run = true;
	while (expr[index] != '\0')
	{
		switch (expr[index])
		{
		case '(':
			push(&stackOfOperations, expr[index]);
			break;
		case ')':
			if (isEmpty(stackOfOperations))
			{
				printf("Missed bracket\n");
				return;
			}
			while (stackOfOperations->data != '(')
			{
				input(answer, &indexAnswer, pop(&stackOfOperations));
			}
			pop(&stackOfOperations);
			break;
		case ' ':
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		{
			while (!isEmpty(stackOfOperations) && getPriority(stackOfOperations->data) >= getPriority(expr[index]))
			{
				input(answer, &indexAnswer, pop(&stackOfOperations));
			}
			push(&stackOfOperations, expr[index]);
			break;
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			input(answer, &indexAnswer, expr[index]);
			break;
		default:
			printf("Unrecognised char: %c\n", expr[index]);
			deleteStack(stackOfOperations);
			return;
		}
		index++;
	}
	while (!isEmpty(stackOfOperations))
	{
		input(answer, &indexAnswer, pop(&stackOfOperations));
	}
}