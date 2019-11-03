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
/*	printf("Index Head: %i\n", indexHead);
	printf("Index Tail: %i\n", indexTail);
	printf("Head: %i\n", head);
	printf("Tail: %i\n", size);
	printf("Index Sup Element: %i\n", indexOfElement);*/
//	for (int i = head; i < size; i++)
//	{
//		printf((i == size - 1) ? "%i\n" : "%i, ", array[i]);
//	}
//	distribution(array, head, indexOfElement);
//	distribution(array, indexOfElement + 1, size);
	return;
	
}

bool testRandomArray()
{
	bool isCorrect = true;
	int size = 10000;
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

bool testHugeArray()
{
	bool isCorrect = true;
	const int size = 1000;
	int hugeArray[size];
	for (int i = 0; i < size; i++)
	{
		hugeArray[i] = dipRand(-1000, 1000);
	}
	distribution(hugeArray, 0, size);
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

bool testDist()
{
	bool isCorrect = true;
	const int size = 1000;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = dipRand(7, 7000);
	}
	int supEl = array[0];
	int indexEl = 0;
	distribution(array, 0, size);
	for (int i = 0; i < size; i++)
	{
		if (array[i] == supEl)
		{
			indexEl = i;
			break;
		}
	}
	for (int i = 0; i < indexEl; i++)
	{
		if (array[i] >= supEl)
		{
			isCorrect = false;
		}
	}
	for (int i = indexEl; i < size; i++)
	{
		if (array[i] < supEl)
		{
			isCorrect = false;
		}
	}
	return  isCorrect;
}

int main()
{
	if (!testDist() || !testRandomArray())
	{
		printf("\nIncorrect work of distribution function\n");
		return -1;
	}
	int size = 7;
	if (size <= 0)
	{
		printf("Incorrect value of size\n");
		return -1;
	}
	printf("Input size:\n");
	scanf_s("%i", &size);
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = dipRand(5, 500);
	}
	printf("Sup element: %i\n", array[0]);
	distribution(array, 0, size);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "Distributed array: \n%i, " : "\n%i, ", array[i]);
	}
//	delete[] array;
	return 0;
}