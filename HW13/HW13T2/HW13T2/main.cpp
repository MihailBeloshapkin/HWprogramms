#include <string.h>
#include <stdio.h>

int **createStateTable(int numberOfRows, int numberOfColumns)
{
	int **newTable = new int *[numberOfColumns] {};
	for (int index = 0; index < numberOfColumns; index++)
	{
		newTable[index] = new int[numberOfRows] {};
	}
	return newTable;
}

void deleteStateTable(int **table, int numberOfColumns)
{
	for (int i = 0; i < numberOfColumns; i++)
	{
		delete[] table[i];
	}
	delete[] table;
}

int searchIndex(char *alphabet, char symbol)
{
	int index = 0;
	for (index = 0; alphabet[index] != '%'; index++)
	{
		if (alphabet[index] == symbol)
		{
			return index;
		}
	}
	return index;
}

int **loadDataFromFile(FILE *file, char *alphabet, int *numberOfColumns, int *numberOfRows)
{
	fscanf(file, "%i", numberOfColumns);
	fscanf(file, "%i", numberOfRows);
	int indexForAlph = 0;
	while (indexForAlph < *numberOfColumns)
	{
		char symbol = '\0';
		fscanf(file, "%c", &symbol);
		if (symbol != ' ' && symbol != '\n' && symbol != '\0')
		{
			alphabet[indexForAlph] = symbol;
			indexForAlph++;
		}
	}
	
	int **newTable = createStateTable(*numberOfRows, *numberOfColumns);

	for (int indexOfRows = 0; indexOfRows < *numberOfRows; indexOfRows++)
	{
		for (int indexOfColumns = 0; indexOfColumns < *numberOfColumns; indexOfColumns++)
		{
			int number = 0;
			fscanf(file, "%i", &number);
			newTable[indexOfColumns][indexOfRows] = number;
		}
	}
	return newTable;
}

void searchComments(FILE *file, char *comments)
{ 
	int numberOfColumns = 0;
	int numberOfRows = 0;
	char alphabet[30]{};
	FILE *dataFile = fopen("data.txt", "r");
	int **table = loadDataFromFile(dataFile, alphabet, &numberOfColumns, &numberOfRows);
	fclose(dataFile);

	int state = 0;
	int index = 0;
	while (!feof(file))
	{
		char symbol = '\0';
		symbol = fgetc(file);
		int nextState = table[searchIndex(alphabet, symbol)][state];
		
		if ((state == 1 && nextState == 2) || (state == 3 && nextState == 0))
		{
			comments[index] = '/';
			index++;
		}
		state = nextState;
		if (state == 2 || state == 3)
		{
			comments[index] = symbol;
			index++;
		}		
	}
	deleteStateTable(table, numberOfColumns);
}

bool test()
{
	char testComments[100]{};
	FILE *textFile = fopen("test.txt", "r");
	searchComments(textFile, testComments);
	fclose(textFile);
	char rightAnswer[100] = "/*determine valuable variables*//*Hit discription*//*****//*put pixel*/";
	return strcmp(testComments, rightAnswer) == 0;
}

int main()
{
	if (!test())
	{
		return -1;
	}
	char comments[100]{};
	FILE *textFile = fopen("text.txt", "r");
	searchComments(textFile, comments);
	fclose(textFile);
	printf("%s", comments);
	getchar();
	return 0;
}