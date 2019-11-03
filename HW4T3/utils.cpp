#include "pch.h"
#include <stdio.h>
#include "notebook.h"

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

void clearInput()
{
	while (getchar() != '\n')
	{
	}
}

void displayData(note *data, int count)
{
	int index = 0;
	while (index < count)
	{
		printf("%s -> %s\n", data[index].name, data[index].phoneNumber);
		index++;
	}
}

bool isSimilar(char *string1, char *string2, int size)
{
	bool isSimilar = true;
	for (int i = 0; i < size; i++)
	{
		char ch1 = string1[i];
		char ch2 = string2[i];
		if (string1[i] != string2[i])
		{
			isSimilar = false;
		}
	}
	return isSimilar;
}

void saveData(note *data, int size, FILE *file)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s -> %s\n", data[i].name, data[i].phoneNumber);
	}
}

int loadData(note *data, FILE *file)
{
	int index = -1;
	bool run = true;
	while (!feof(file))
	{
		index++;
		char symbol = 'f';
		int i = 0;
		while ((symbol = fgetc(file)) != '-' && !feof(file))
		{
			if (symbol != ' ')
			{
				data[index].name[i] = symbol;
				i++;
			}
		}
		int j = 0;
		while ((symbol = fgetc(file)) != '\n' && !feof(file))
		{
			if (symbol != ' ' && symbol != '>')
			{
				data[index].phoneNumber[j] = symbol;
				j++;
			}
		}
	}
	return index;
}