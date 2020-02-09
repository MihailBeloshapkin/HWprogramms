#include <stdio.h>
#include "alg.h"
#include "test.h"
#include "list.h"

void display(int* array[], int countOfRows, int countOfColumns)
{
	for (int i = 0; i < countOfRows; i++)
	{
		for (int j = 0; j < countOfColumns; j++)
		{
			printf((j == countOfColumns - 1) ? "%i\n" : "%i  ", array[i][j]);
		}
	}
}

int main()
{
	if (!test())
	{
		return -1;
	}
	int size = 0;
	FILE* file = fopen("data.txt", "r");
	fscanf(file, "%i", &size);
	if (size <= 0)
	{
		return -1;
	}
	int** graph = createMatrix(size);
	int** subGraph = createMatrix(size);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int number = 0;
			fscanf(file, "%i", &number);
			graph[i][j] = number;
		}
	}
	fclose(file);
	printf("Answer is:\n\n");
	algorithm(graph, subGraph, size);
	display(subGraph, size, size);
	getchar();
	deleteMatrix(graph, size);
	deleteMatrix(subGraph, size);
	return 0;
}