#include "alg.h"
#include "list.h"
#include <stdio.h>

bool isTrueArray(bool* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!array[i])
		{
			return false;
		}
	}
	return true;
}

int** createMatrix(int size)
{
	int** newMatrix = new int* [size] {};
	for (int index = 0; index < size; index++)
	{
		newMatrix[index] = new int[size] {};
	}
	return newMatrix;
}

void deleteMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void algorithm(int* graph[], int* subGraph[], int size)
{
	List* list = nullptr;
	int currentVertex = 0;
	bool *isIncluded = new bool [size]{};
	int indexOfIncArray = 0;
	int minDistanceVertex = 0;
	isIncluded[currentVertex] = true;
	while (!isTrueArray(isIncluded, size))
	{
		for (int index = 0; index < size; index++)
		{
			if (graph[index][currentVertex] > 0 && !isIncluded[index])
			{
				add(&list, graph[index][currentVertex], index);
			}
		}
		int minDistance = 0;
		int minIncidentVertex = delFromListFront(&list, &minDistance);
		deleteVertex(&list, minIncidentVertex);
		for (int index = 0; index < size; index++)
		{
			if (graph[index][minIncidentVertex] == minDistance && isIncluded[index])
			{
				subGraph[index][minIncidentVertex] = graph[index][minIncidentVertex];
				subGraph[minIncidentVertex][index] = graph[index][minIncidentVertex];
				break;
			}
		}
		currentVertex = minIncidentVertex;
		isIncluded[currentVertex] = true;
	}
	delete[] isIncluded;
}
