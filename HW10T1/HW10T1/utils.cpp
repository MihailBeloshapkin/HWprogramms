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

char *copy(char *string)
{
	char *str = new char[100]{};
	for (int i = 0; string[i] != '\0'; i++)
	{
		str[i] = string[i];
	}
	return str;
}

bool isLetter(char symbol)
{
	return (('a' <= symbol) && (symbol <= 'z')) || (('A' <= symbol) && (symbol <= 'Z'));
}

