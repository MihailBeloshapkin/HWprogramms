#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

void quickSort(int *array, int head, int tail);

int dipRand(int minValue = 5, int maxValue = 15)
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

bool testOneElArray()
{
	int testArray[1] = { 77 };
	quickSort(testArray, 0, 0);
	return testArray[0] == 77;
}

void quickSort(int *array, int head, int tail)
{
	if (tail - head < 10)
	{
		insertionSort(array, head - 1, tail + 1);
		return;
	}
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
	quickSort(testArray, 0, size - 1);
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
	delete[] testArray;
	delete[] testValueArray1;
	delete[] testValueArray2;
	return isCorrectly;
}
	
bool testHugeArray()
{
	bool isCorrect = true;
	const int size = 1000;
	int hugeArray[size];
	for (int i = 0; i < size; i++)
	{
		hugeArray[i] = dipRand(-1000, 1000);
	}
	quickSort(hugeArray, 0, size - 1);
	for (int i = 0; i < size - 1; i++)
	{
		if (hugeArray[i] > hugeArray[i + 1])
		{
			printf("Incorrect work: %i, %i\n", hugeArray[i], hugeArray[i + 1]);
			isCorrect = false;
		}
	}
	if (!isCorrect)
	{
		printf("Incorrect work with huge array:\n");
		for (int i = 0; i < size; i++)
		{
			printf("%i, ", hugeArray[i]);
		}
	}
	return isCorrect;
}

bool testSimElArray()
{
	int simElement = dipRand(-100, 150);
	int size = dipRand(50, 500);
	int *testArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		testArray[i] = simElement;
	}
	quickSort(testArray, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		if (testArray[i] != simElement)
		{
			printf("Incorrect work with sim element array\n");
			return false;
		}
	}
	return true;
}

int main()
{
	if (!testHugeArray() || !testQuickSort() || !testSimElArray() || !testOneElArray())
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
	quickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "Sorted array: %i, " : "%i, ", array[i]);
	}
	delete[] array;
	return 0;
 }
