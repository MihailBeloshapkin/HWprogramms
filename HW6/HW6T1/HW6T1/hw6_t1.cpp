#include "pch.h"
#include <stdio.h>
#include "evaluator.h"

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
		printf("eval function works incorrectly\n");
		return -1;
	}
	char expression[100]{};
	printf("Input expression:\n");
	getString(expression, 100);
	printf("Resuilt is %i\n", eval(expression));
	return 0;
}