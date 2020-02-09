#include <stdio.h>
#include <string.h>
#include "tree.h"
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

char *copy(char *string)
{
	char *str = new char[strlen(string) + 1]{};
	strcpy(str, string);
	return str;
}

void clearInput()
{
	while (getchar() != '\n')
	{
	}
}

bool isLetter(char symbol)
{
	return (('a' <= symbol) && (symbol <= 'z')) || (('A' <= symbol) && (symbol <= 'Z'));
}

int module(int value)
{
	if (value >= 0)
	{
		return value;
	}
	else
	{
		return -value;
	}
}

void loadData(Tree** tree, FILE* file)
{
	bool run = true;
	while (!feof(file))
	{
		char symbol = '\0';
		int i = 0;
		int newKey = 0;
		fscanf(file, "%i", &newKey);
		int j = 0;
		char newData[100]{};
		while ((symbol = fgetc(file)) != '\n' && !feof(file))
		{
			if (isLetter(symbol))
			{
				newData[j] = symbol;
				j++;
			}
		}
		*tree = addition(tree, newKey, newData);
	}
}

int max(int number1, int number2)
{
	return number1 > number2 ? number1 : number2;
}

