#include "pch.h"
#include "stack.h"
#include <stdio.h>
#include "createPostfix.h"
#include "test.h"

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

int main()
{
	if (!test())
	{
		printf("Incorrect work of create postfix function\n");
		return -1;
	}
	const int size = 100;
	char expr[size]{};
	char answer[size]{};
	printf("Input expression:\n");
	getString(expr, size);	
	createPostfix(expr, answer);
	printf("Answer: %s", answer);
	return 0;
}