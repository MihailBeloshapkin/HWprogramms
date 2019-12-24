#include <stdio.h>
#include <ctype.h>
#include "utils.h"

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

void load(FILE *file, char *outExpr)
{
	int index = 0;
	while (!feof(file))
	{
		outExpr[index] = fgetc(file);
		index++;
	}
}

bool isOperation(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int digitScanner(char *str)
{
	int answer = 0;
	const int maxSize = 100;
	int index = 0;
	while (str[index] != '\0' && index < maxSize  && isdigit(str[index]))
	{
		answer = answer * 10 + str[index] - '0';
		index++;
	}
	return answer;
}

bool isNumber(char *string)
{
	int index = 0;
	while (string[index] != '\0')
	{
		if (!isdigit(string[index]))
		{
			return false;
		}
		index++;
	}
	return true;
}

bool isExpression(char *string)
{
	bool operationIincluded = false;
	bool numberIncluded = true;
	int index = 0;
	while (string[index] != '\0')
	{
		if (operationIincluded == true && numberIncluded == true)
		{
			return true;
		}
		if (isOperation(string[index]))
		{
			operationIincluded = true;
		}
		if (isdigit(string[index]))
		{
			numberIncluded = true;
		}
		index++;
	}
	return false;
}