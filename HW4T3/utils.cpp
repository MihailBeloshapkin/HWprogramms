#include "pch.h"
#include <stdio.h>
#include "notebook.h"
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

void clearInput()
{
	while (getchar() != '\n')
	{
	}
}

void displayData(Note *data, int count)
{
	int index = 0;
	while (index < count)
	{
		printf("%s -> %s\n", data[index].name, data[index].phoneNumber);
		index++;
	}
}

bool isSimilar(char *string1, char *string2)
{
	int index = 0;
	while (string1[index + 1] != '\0'|| string2[index + 1] != '\0')
	{
		if (string1[index] != string2[index])
		{
			return false;
		}
		index++;
	}
	return true;
}

void saveData(Note *data, int size, FILE *file)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s -> %s\n", data[i].name, data[i].phoneNumber);
	}
}

int loadData(Note *data, FILE *file)
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