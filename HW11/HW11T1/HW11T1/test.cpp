#include "test.h"
#include "list.h"
#include "alg.h"
#include <stdio.h>

List** arrayWithRightValues()
{
	List** rightArray = createArrayOfLists(3);
	List* firstList = nullptr;
	List* secondList = nullptr;
	List* thirdList = nullptr;
	addToListBack(&firstList, 0);
	addToListBack(&firstList, 3);
	addToListBack(&firstList, 6);
	addToListBack(&secondList, 2);
	addToListBack(&secondList, 1);
	addToListBack(&thirdList, 4);
	addToListBack(&thirdList, 5);
	rightArray[0] = firstList;
	rightArray[1] = secondList;
	rightArray[2] = thirdList;
	return rightArray;
}

bool compareArraysOfList(List** firstArray, List** secondArray, int sizeOfArray)
{
	for (int index = 0; index < sizeOfArray; index++)
	{
		if (!compareLists(firstArray[index], secondArray[index]))
		{
			return false;
		}
	}
	return true;
}

bool test()
{
	FILE* testFile = fopen("test.txt", "r");
	int countOfCities = 0;
	fscanf(testFile, "%i", &countOfCities);
	int** testGraph = createMatrix(countOfCities);
	int countOfRoads = 0;
	fscanf(testFile, "%i", &countOfRoads);
	for (int index = 0; index < countOfRoads; index++)
	{
		int firstVertex = 0;
		int secondVertex = 0;
		int lengthOfRoad = 0;
		fscanf(testFile, "%i", &firstVertex);
		fscanf(testFile, "%i", &secondVertex);
		fscanf(testFile, "%i", &lengthOfRoad);
		testGraph[firstVertex][secondVertex] = lengthOfRoad;
		testGraph[secondVertex][firstVertex] = lengthOfRoad;
	}
	int countOfCapitals = 0;
	fscanf(testFile, "%i", &countOfCapitals);
	int* capitals = new int[countOfCapitals] {};
	for (int index = 0; index < countOfCapitals; index++)
	{
		int capital = 0;
		fscanf(testFile, "%i", &capital);
		capitals[index] = capital;
	}
	fclose(testFile);
	List** listsOfCities = game(testGraph, countOfCities, capitals, countOfCapitals);
	List** rightArray = arrayWithRightValues();
	bool resuilt = compareArraysOfList(listsOfCities, rightArray, countOfCapitals);
	deleteArrayOfLists(listsOfCities, countOfCapitals);
	deleteArrayOfLists(rightArray, countOfCapitals);
	deleteMatrix(testGraph, countOfCities);
	delete[] capitals;
	return resuilt;
}