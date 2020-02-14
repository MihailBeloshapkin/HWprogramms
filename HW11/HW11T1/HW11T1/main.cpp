#include <stdio.h>
#include "alg.h"
#include "test.h"

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

void displayArrayOfLists(List** arrayOfLists, int sizeOfArray)
{
	for (int index = 0; index < sizeOfArray; index++)
	{
		printf("%i: ", index);
		displayList(arrayOfLists[index]);
		printf("\n");
	}
}

int main()
{
	if (!test())
	{
		return -1;
	}
	FILE* file = fopen("data.txt", "r");
	int countOfCities = 0;
	fscanf(file, "%i", &countOfCities);
	int** graph = createMatrix(countOfCities);
	int countOfRoads = 0;
	fscanf(file, "%i", &countOfRoads);
	for (int index = 0; index < countOfRoads; index++)
	{
		int firstVertex = 0;
		int secondVertex = 0;
		int lengthOfRoad = 0;
		fscanf(file, "%i", &firstVertex);
		fscanf(file, "%i", &secondVertex);
		fscanf(file, "%i", &lengthOfRoad);
		graph[firstVertex][secondVertex] = lengthOfRoad;
		graph[secondVertex][firstVertex] = lengthOfRoad;
	}
	int countOfCapitals = 0;
	fscanf(file, "%i", &countOfCapitals);
	int* capitals = new int[countOfCapitals] {};
	for (int index = 0; index < countOfCapitals; index++)
	{
		int capital = 0;
		fscanf(file, "%i", &capital);
		capitals[index] = capital;
	}
	fclose(file);
	List** listsOfCities = game(graph, countOfCities, capitals, countOfCapitals);
	displayArrayOfLists(listsOfCities, countOfCapitals);
	deleteArrayOfLists(listsOfCities, countOfCapitals);
	deleteMatrix(graph, countOfCities);
	delete[] capitals;
	return 0;
}