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

void insertionSort(int array[], int head, int tail)
{
	for (int i = head + 1; i < tail; i++)
	{
		int j = i;
		while (array[j - 1] > array[j] && j > head)
		{
			int tmp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = tmp;
			j--;
		}
	}
}

void quickSort(int *array, int head, int tail)
{
	int indexOfElement = (head + tail) / 2;
	int indexOfHead = head - 1;
	int indexOfTail = tail + 1;
	bool run = true;
	if (head >= tail)
	{
		return;
	}
	while (indexOfHead < indexOfTail)
	{
		indexOfHead++;
		while (array[indexOfHead] < array[indexOfElement])
		{
			indexOfHead++;
		}
		indexOfTail--;
		while (array[indexOfTail] > array[indexOfElement])
		{
			indexOfTail--;
		}

		if (indexOfHead < indexOfTail)
		{
			const int tmp = array[indexOfTail];
			array[indexOfTail] = array[indexOfHead];
			array[indexOfHead] = tmp;

			if (indexOfElement == indexOfHead)
			{
				indexOfElement = indexOfTail;
				indexOfTail++;
			}
			if (indexOfElement == indexOfTail)
			{
				indexOfElement = indexOfHead;
				indexOfHead--;
			}
		}
	}
	quickSort(array, head, indexOfElement - 1);
	quickSort(array, indexOfElement + 1, tail);
}

int searchMostFrequent(int array[], int size)
{
	quickSort(array, 0, size - 1);
	int counter = 1;
	int maxCount = 0;
	int mostFrequentElement = array[0];
	for (int i = 0; i < size - 1; i++)
	{
		if (counter >= maxCount)
		{
			maxCount = counter;
			mostFrequentElement = array[i - 1];
		}
		if (array[i] == array[i + 1])
		{
			counter++;
		}
		else
		{
			counter = 1;
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
	int hugeValuesArray[] = { 1, 2, 2, 3, 3, 3 };
	if (searchMostFrequent(hugeValuesArray, 6) != 3)
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
		return -1;
	}  
	int size = 9;
	printf("Input size of array:\n");
	scanf_s("%i", &size);
	if (size < 0)
	{
		printf("Incorrect value of array size\n");
		return -1;
	}
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
