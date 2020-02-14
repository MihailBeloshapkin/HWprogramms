#include "list.h"
#include "alg.h"

bool isTrueArray(bool* array, int size)
{
	for (int index = 0; index < size; index++)
	{
		if (!array[index])
		{
			return false;
		}
	}
	return true;
}

List** createArrayOfLists(int size)
{
	List** list = new List * [size];
	for (int index = 0; index < size; index++)
	{
		list[index] = nullptr;
	}
	return list;
}

void deleteArrayOfLists(List** arrayOfLists, int sizeOfArray)
{
	for (int index = 0; index < sizeOfArray; index++)
	{
		deleteList(&arrayOfLists[index]);
	}
	delete[] arrayOfLists;
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

int occupation(int* graph[], int size, List* listOfCities, bool* isOccupated)
{
	int minDistance = -1;
	int minDistanceVertex = -1;
	while (listOfCities != nullptr)
	{
		for (int index = 0; index < size; index++)
		{
			if (!isOccupated[index] && graph[returnVertex(listOfCities)][index] > 0)
			{
				if (minDistance == -1 || graph[returnVertex(listOfCities)][index] < minDistance)
				{
					minDistance = graph[returnVertex(listOfCities)][index];
					minDistanceVertex = index;
				}	
			}
		}
		shiftNext(&listOfCities);
	}
	if (minDistanceVertex > -1)
	{
		isOccupated[minDistanceVertex] = true;
	}
	return minDistanceVertex;
}

List** game(int* graph[], int size, int* capitals, int countOfCapitals)
{
	bool* isOccupied = new bool[size] {};
	List** listOfCountries = createArrayOfLists(countOfCapitals);
	for (int index = 0; index < countOfCapitals; index++)
	{
		isOccupied[capitals[index]] = true;
		addToListBack(&listOfCountries[index], capitals[index]);
	}
	int indexOfCountry = 0;
	while (!isTrueArray(isOccupied, size))
	{
		int minDistanceVertex = occupation(graph, size, listOfCountries[indexOfCountry], isOccupied);
		if (minDistanceVertex > -1)
		{
			addToListBack(&listOfCountries[indexOfCountry], minDistanceVertex);
		}
		indexOfCountry == countOfCapitals - 1 ? indexOfCountry = 0 : indexOfCountry++;
	}
	delete[] isOccupied;
	return listOfCountries;
}