// 14.10.2019

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

int dipRand(int minValue = 5, int maxValue = 15)
{
	return rand() % (maxValue - minValue + 1) + minValue;
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


bool testRandomValues()
{
	bool isCorrect = false;
	int size = dipRand();
	return isCorrect;
}

bool isIncluded(int array[], int head, int tail, int element)
{
	if (array[head] == element || array[tail] == element)
	{
		return true;
	}
	const int dip = (head + tail) / 2;
	int step = (tail - head + 1) / 2;
	if (step > 0)
	{
		if (element > array[dip])
		{
			head = step + head;
			return isIncluded(array, head, tail, element);
		}
		if (element < array[dip])
		{
			return isIncluded(array, head, tail - step, element);
		}	
		return true;
	}
	return false;
}

int main()
{
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
	quickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "\nSorted Array: %i, " : "%i, ", array[i]);
	}
	for (int i = 0; i < countOfRandNumbers; i++)
	{
		const int element = dipRand();
		if (isIncluded(array, 0, size - 1, element))
		{
			printf("\n%i is included\n", element);
		}
		else
		{
			printf("\n%i is not included\n", element);
		}
	}
    delete[] array;  
	return 0;
}