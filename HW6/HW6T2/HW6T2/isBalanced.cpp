#include "pch.h"
#include <stdio.h>
#include "isBalanced.h"
#include "stackFunctions.h"

bool isBalanced(char *expr, int size)
{
	bool isBalanced = true;
	int index = 0;
	Stack *stack = nullptr;
	while (expr[index] != '\0')
	{
		int bracket = 0;
		switch (expr[index])
		{
		case '[':
		case '(':
		case '{':
			push(&stack, expr[index]);
			break;
		case ')':
			if (!pop(&stack, &bracket))
			{
				isBalanced = false;
			}
			if (bracket != '(')
			{
				isBalanced = false;
			}
			break;
		case '}':
			if (!pop(&stack, &bracket))
			{
				isBalanced = false;
			}
			if (bracket != '{')
			{
				isBalanced = false;
			}
			break;
		case ']':
			if (!pop(&stack, &bracket))
			{
				isBalanced = false;
			}
			if (bracket != '[')
			{
				isBalanced = false;
			}
			break;
		default:
			printf("Unrecognised char: %c\n", expr[index]);
			isBalanced = false;
		}
		if (!isBalanced)
		{
			deleteStack(stack);
			return isBalanced;
		}
		index++;
	}
	if (!isEmpty(stack))
	{
		deleteStack(stack);
		return false;
	}
	return isBalanced;
}
