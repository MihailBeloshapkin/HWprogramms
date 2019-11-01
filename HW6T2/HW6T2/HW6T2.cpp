#include "pch.h"
#include "HW6T2.h"
#include <stdio.h>

void getString(char *str, int maxSize)
{
	int i = 0;
	char symbol = ' ';
	while ((symbol = getchar()) != '\n')
	{
		if (str != nullptr && i < maxSize - 1)
		{
			str[i++] = symbol;
		}
	}
	if (str != nullptr && i < maxSize)
	{
		str[i] = 0;
	}
}

bool isBalanced(char *expr, int size)
{
	int index = 0;
	Stack *stack = nullptr;
	while (expr[index] != '\0')
	{
		switch (expr[index])
		{
		case '(':
			push(&stack, '(');
			break;
		case ')':
			if (pop(&stack) != '(')
			{
				return false;
			}
			break;
		case '{':
			push(&stack, '{');
			break;
		case '}':
			if (pop(&stack) != '{')
			{
				return false;
			}
			break;
		case '[':
			push(&stack, '[');
			break;
		case ']':
			if (pop(&stack) != '[')
			{
				return false;
			}
			break;
		}
		index++;
	}
	return true;
}

int main()
{
	if (!test())
	{
		printf("isBalanced function works incorrectly\n");
		return -1;
	}
	const int size = 100;
	char expr[size];
	printf("Input exptession:\n");
	getString(expr, size);
	if (isBalanced(expr, size))
	{
		printf("Is balanced\n");
	}
	else
	{
		printf("Is not balanced\n");
	}
	return 0;
}