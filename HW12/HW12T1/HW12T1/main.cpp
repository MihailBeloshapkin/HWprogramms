#include <stdio.h>
#include <string.h>
#include "alg.h"
#include "test.h"

void loadData(FILE* file, char *string, int maxSize)
{
	int index = 0;
	char symbol = '\0';
	while ((symbol = fgetc(file)) != EOF && !feof(file))
	{
		string[index] = symbol;
		index++;
	}
}

void getString(char* str, int maxSize)
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
		return -1;
	}
	FILE* file = fopen("data.txt", "r");
	char string[100]{};
	loadData(file, string, 100);
	fclose(file);
	printf("Input substring:\n");
	char subString[100]{};
	getString(subString, 100);
	int position = searchCoincidence(string, subString, strlen(string), strlen(subString));
	if (position < 0)
	{
		printf("String doesn't contain this substring\n");
	}
	else
	{
		printf("Position of coincidence is %i\n", position - strlen(subString));
	}
	return 0;
}