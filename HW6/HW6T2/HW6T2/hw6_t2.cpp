#include "pch.h"
#include "isbalanced.h"
#include "stackFunctions.h"
#include "test.h"
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
	printf(isBalanced(expr, size) ? "is balanced" : "is not balanced");
	return 0;
}