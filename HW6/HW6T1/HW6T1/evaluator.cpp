#include "pch.h"
#include "evaluator.h"
#include <stdio.h>
#include <ctype.h>

int digitScanner(char *str, int &index)
{
	int answer = 0;
	const int maxSize = 100;
	while (str[index] != '\0' && index < maxSize  && isdigit(str[index]))
	{
		answer = answer * 10 + str[index] - '0';
		index++;
	}
	return answer;
}

int eval(char *expr)
{
	Stack *stack = nullptr;
	int index = 0;
	int firstNum = 0;
	int secondNum = 0;
	while (expr[index] != '\0' && index < 100)
	{
		switch (expr[index])
		{
		case ' ':
		case '\n':
			break;
		case '+':
		{
			if (isEmpty(stack))
			{
				deleteStack(stack);
				return -1;
			}
			int firstNum = pop(&stack);
			int secondNum = pop(&stack);
			push(&stack, firstNum + secondNum);
			break;
		}
		case '-':
			if (isEmpty(stack))
			{
				deleteStack(stack);
				return -1;
			}
			firstNum = pop(&stack);
			secondNum = pop(&stack);
			push(&stack, secondNum - firstNum);
			break;
		case '*':
			if (isEmpty(stack))
			{
				deleteStack(stack);
				return -1;
			}
			firstNum = pop(&stack);
			secondNum = pop(&stack);
			push(&stack, secondNum * firstNum);
			break;
		case '/':
			if (isEmpty(stack))
			{
				deleteStack(stack);
				return -1;
			}
			firstNum = pop(&stack);
			secondNum = pop(&stack);
			push(&stack, secondNum / firstNum);
			break;
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
		{
			int value = digitScanner(expr, index);
			push(&stack, value);
			break;
		}
		default:
			break;
		}
		index++;
	}	
	const int result = pop(&stack);
    return result;

}