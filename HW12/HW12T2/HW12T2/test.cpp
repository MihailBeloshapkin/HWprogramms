#include "test.h"
#include "alg.h"
#include <stdio.h>

bool compareMatrix(int* matrix1[], int *matrix2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool test()
{
	int size = 0;
	FILE* file = fopen("test.txt", "r");
	fscanf(file, "%i", &size);
	if (size <= 0)
	{
		return -1;
	}
	int** testGraph = createMatrix(size);
	int** testSubGraph = createMatrix(size);
	int** rightAnswer = createMatrix(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int number = 0;
			fscanf(file, "%i", &number);
			testGraph[i][j] = number;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int number = 0;
			fscanf(file, "%i", &number);
			rightAnswer[i][j] = number;
		}
	}
	fclose(file);

	algorithm(testGraph, testSubGraph, 7);
	bool isCorrect = compareMatrix(testSubGraph, rightAnswer, size);
	deleteMatrix(testGraph, size);
	deleteMatrix(testSubGraph, size);
	deleteMatrix(rightAnswer, size);
	return isCorrect;
}