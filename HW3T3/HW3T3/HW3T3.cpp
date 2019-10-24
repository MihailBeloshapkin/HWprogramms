// 26.09.2019 created project
// 5.10.2019  added searchMostFrequent function
// 6.10.2019 added tests
// 12.10.2019 added corrections

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

int dipRand(int minValue = 5, int maxValue = 50)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

void swap(int *firstVar, int *secondVar)
{
	int tmp = *firstVar;
	*firstVar = *secondVar;
	*secondVar = tmp;
}

void quickSort(int array[], int head, int tail)
{
	if (array[head] > array[tail - 1] && tail - head == 2)
	{
		swap(&array[head], &array[tail - 1]);
	}
	int indexOfElement = head;
	int indexHead = 1 + head;
	int indexTail = tail - 1;
	if (head >= tail)
	{
		return;
	}
	while (indexHead < indexTail)
	{
		while (array[indexHead] < array[indexOfElement])
		{
			indexHead++;
		}
		while (array[indexTail] >= array[indexOfElement])
		{
			indexTail--;
		}
		if (indexHead < indexTail)
		{
			const int tmp = array[indexHead];
			array[indexHead] = array[indexTail];
			array[indexTail] = tmp;
			indexHead++;
			indexTail--;
		}
	}
	indexHead--;
	const int tmp = array[head];
	array[head] = array[indexHead];
	array[indexHead] = tmp;
	indexOfElement = indexHead;
	quickSort(array, head, indexOfElement);
	quickSort(array, indexOfElement + 1, tail);
	return;
}

int searchMostFrequent(int array[], int size)
{
	quickSort(array, 0, size);
	int counter = 0;
	int maxCount = 0;
	int mostFrequentElement = array[0];
	int value = array[0];
	for (int i = 1; i < size; i++)
	{
		if (counter > maxCount)
		{
			mostFrequentElement = array[i - 1];
			maxCount = counter;
			counter = 0;
		}
		if (array[i] == array[i - 1])
		{
			counter++;
		}
		else
		{
			counter = 0;
		}
	}
	return mostFrequentElement;
}

bool testRandomArray()
{
	bool isCorrectly = true;
	int sizeOfHugeArray = dipRand(3, 15);
	int *hugeArray = new int[sizeOfHugeArray];
	int mostFrequentElement = dipRand();
	for (int i = 0; i < sizeOfHugeArray; i++)
	{
		if (i % 2 == 0)
		{
			hugeArray[i] = mostFrequentElement;
		}
		else
		{
			hugeArray[i] = dipRand();
		}
	}
	if (searchMostFrequent(hugeArray, sizeOfHugeArray) != mostFrequentElement)
	{
		isCorrectly = false;
	}
	delete[] hugeArray;
	return isCorrectly;
}

bool testHugeValues()
{
	bool isCorrectly = true;
	int hugeValuesArray[] = { 10000003, 10000007, 10000007, 10000004, 10000007 };
	if (searchMostFrequent(hugeValuesArray, 5) != 10000007)
	{
		isCorrectly = false;
	}
	return isCorrectly;
}

int main()
{
	if (!testRandomArray() || !testHugeValues())
	{
		if (!testRandomArray())
		{
			printf("searchMostFrequent function Works incorrectly with big arrays\n");
		}
		if (!testHugeValues())
		{
			printf("searchMostFrequent function Works incorrectly with huge numbers\n");
		}
		return 0;
	}
	int size = 9;
	printf("Input size of array:\n");
	scanf_s("%i", &size);
	int *array = new int[size];
	printf("Input array:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%i", &array[i]);
	}
	printf("Most frequent element is %i\n", searchMostFrequent(array, size));
	for (int i = 0; i < size; i++)
	{
		printf("%i, ", array[i]);
	}	
	delete[] array;
	return 0;
}
