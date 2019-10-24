#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

int dipRand(int minValue = 5, int maxValue = 15)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

void InsertionSort(int array[], int head, int tail)
{
	for (int i = head + 1; i < tail; i++)
	{
		int j = i;
		while (array[j - 1] > array[j] && j > 0)
		{
			int tmp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = tmp;
			j--;
		}
	}
}

void quickSort(int array[], int head, int tail)
{
	if (tail - head < 10)
	{
		InsertionSort(array, head, tail);
		return;
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

bool testQuickSort()
{
	bool isCorrectly = true;
	int size = dipRand();
	int *testArray = new int[size];
	int maxNumber = 0;
	for (int i = 0; i < size; i++)
	{
		testArray[i] = dipRand(1, 100);
		if (testArray[i] > maxNumber)
		{
			maxNumber = testArray[i];
		}
	}
	int *testValueArray1 = new int[maxNumber + 1]{};
	for (int i = 0; i < size; i++)
	{
		testValueArray1[testArray[i]]++;
	}
	quickSort(testArray, 0, size);
	int *testValueArray2 = new int[maxNumber + 1]{};
	for (int i = 0; i < size; i++)
	{
		testValueArray2[testArray[i]]++;
	}
	for (int i = 0; i < maxNumber + 1; i++)
	{
		if (testValueArray1[i] != testValueArray2[i])
		{
			isCorrectly = false;
		}
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (testArray[i] > testArray[i + 1])
		{
			isCorrectly = false;
		}
	}
	if (!isCorrectly)
	{
		for (int i = 0; i < size; i++)
		{
			printf((i == 0) ? "\nAfter sort: %i, " : "%i, ", testArray[i]);
		}
	}
	delete[] testValueArray1;
	delete[] testValueArray2;
	return isCorrectly;

}


int main()
{
	if (!testQuickSort())
	{
		printf("Quick sort works incorrectly\n");
		return -1;
	}
	int size = 7;
	printf("Input size of array:\n");
	scanf_s("%i", &size);
	if (size <= 0)
	{
		printf("Incorrect value of size\n");
		return -1;
	}
	int *array = new int[size];
	printf("Input array:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%i", &array[i]);
	}
	quickSort(array, 0, size);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "Sorted array: %i, " : "%i, ", array[i]);
	}
	delete[] array;
	return 0;
}
