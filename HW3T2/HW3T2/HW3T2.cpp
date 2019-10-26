// 14.10.2019

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

bool isIncluded(int array[], int head, int tail, int element, int size);

int dipRand(int minValue = 5, int maxValue = 15)
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


bool test()
{
	bool isCorrect = true;
	const int size = 5;
	int testArray[5] = { 8, 0, 5, -9, 4 };
	quickSort(testArray, 0, size);
	if (!isIncluded(testArray, 0, size - 1, testArray[0], size))
	{
		isCorrect = false;
	}
	if (!isIncluded(testArray, 0, size - 1, testArray[1], size))
	{
		isCorrect = false;
	}
	if (!isIncluded(testArray, 0, size - 1, testArray[2], size))
	{
		isCorrect = false;
	}
	if (!isIncluded(testArray, 0, size - 1, testArray[3], size))
	{
		isCorrect = false;
	}
	if (!isIncluded(testArray, 0, size - 1, testArray[4], size))
	{
		isCorrect = false;
	}
	if (!isCorrect)
	{
		printf("Incorrect work with test array value\n");
	}
	return isCorrect;
}

bool isIncluded(int array[], int head, int tail, int element, int size)
{
	bool isIncl = false;
	if (array[head] == element || array[tail] == element)
	{
		isIncl = true;
		return isIncl;
	}
	int dip = (head + tail) / 2;
	int step = size / 2;
	if (step > 0)
	{
		if (element > array[(head + tail) / 2])
		{
			head = step + head;
			return isIncluded(array, head, tail, element, step);
		}
		if (element < array[(head + tail) / 2])
		{
			tail = tail - step;
			return isIncluded(array, head, tail, element, step);
		}
		if (element == array[(head + tail) / 2])
		{
			isIncl = true;
			return isIncl;
		}
	}
	return isIncl;
}

int main()
{
	if (!test())
	{
		return -1;
	}
	int size = 7;
	int countOfRandNumbers = 0;
	printf("Input n:\n");
	scanf_s("%i", &size);
	printf("Input k:\n");
	scanf_s("%i", &countOfRandNumbers);
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = dipRand();
	}
	quickSort(array, 0, size);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "\nSorted Array: %i, " : "%i, ", array[i]);
	}
	for (int i = 0; i < countOfRandNumbers; i++)
	{
		int element = dipRand();
		if (isIncluded(array, 0, size - 1, element, size))
		{
			printf("\n%i is included\n", element);
		}
		else
		{
			printf("\n%i is not included\n", element);
		}
	} 
	return 0;
}


