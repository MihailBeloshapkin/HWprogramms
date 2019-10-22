// 07.10.2019
#include <stdio.h>
#include <stdlib.h>

int dipRand(int minValue = 3, int maxValue = 15)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

void swap(int *firstVar, int *secondVar)
{
	int tmp = *firstVar;
	*firstVar = *secondVar;
	*secondVar = tmp;
}

void distribution(int array[], int head, int size)
{
	if (array[head] > array[size - 1] && size - head == 2)
	{
		swap(&array[head], &array[size - 1]);
	}
	int indexOfElement = head;
	int indexHead = 1 + head;
	int indexTail = size - 1;
	for (int i = head; i < size; i++)
	{
		printf((i == size - 1) ? "%i\n" : "%i, ", array[i]);
	}
	if (head >= size)
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
	printf("Index Head: %i\n", indexHead);
	printf("Index Tail: %i\n", indexTail);
	printf("Head: %i\n", head);
	printf("Tail: %i\n", size);
	printf("Index Sup Element: %i\n", indexOfElement);
	for (int i = head; i < size; i++)
	{
		printf((i == size - 1) ? "%i\n" : "%i, ", array[i]);
	}
	distribution(array, head, indexOfElement);
	distribution(array, indexOfElement + 1, size);
	return;
	
}

bool testRandomArray()
{
	bool isCorrect = true;
	int size = dipRand(7, 10);
	int *testArray = new int[size];
	int *simTestArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		testArray[i] = dipRand(-50, 100);
		simTestArray[i] = testArray[i];
	}
	int supElement = testArray[0];
	int supIndex = 0;
	distribution(testArray, 0, size);
	while (testArray[supIndex] != supElement)
	{
		supIndex++;
	}
	for (int i = 0; i < supIndex; i++)
	{
		if (testArray[i] > supElement)
		{
			isCorrect = false;
			printf("\nIncorrect work in (0, supIndex)\n");
			break;
		}
	}
	for (int i = supIndex + 1; i < size; i++)
	{
		if (testArray[i] < supElement)
		{
			isCorrect = false;
			printf("\nIncorrect work with (supIndex, size)\n");
			break;
		}
	}
	if (!isCorrect)
	{
		printf("\nsize: %i\n\nsupElement:%i", size, supElement);
		for (int i = 0; i < size; i++)
		{ 
			printf((i == 0) ? "\n\nBefore distribution:\n %i, " : "%i, ", simTestArray[i], simTestArray[i]);
		}
		for (int i = 0; i < size; i++)
		{
			printf((i == 0) ? "\n\nAfter distribution:\n %i, " : "%i, ", testArray[i], testArray[i]);
		}
	}
	delete[] testArray;
	delete[] simTestArray;
	return isCorrect;
}

int main()
{
/*	if (!testRandomArray())
	{
		printf("\nIncorrect work of distribution function\n");
		return -1;
	}*/
	int size = 7;
	if (size <= 0)
	{
		printf("Incorrect value of size\n");
		return -1;
	}
	int array[] = { 5, 1, -91, 7, 9, -90, 111 };
//	int array[] = { 3, 1 };
/*for (int i = 0; i < size; i++)
	{
		array[i] = rand();
	}*/
	printf("Sup element: %i\n", array[0]);
	distribution(array, 0, size);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "Distributed array: %i, " : "%i, ", array[i]);
	}
//	delete[] array;
	return 0;
}