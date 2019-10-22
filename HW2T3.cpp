#include "pch.h"
#include <iostream>

int dipRand(int minValue = 5, int maxValue = 10)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void countSort(int array[], int size)
{
	int maxNumber = array[0];
	int minNumber = array[0];
	
	for (int i = 0; i < size; i++)
	{
		if (array[i] > maxNumber)
		{
			maxNumber = array[i];
		}
		if (array[i] < minNumber)
		{
			minNumber = array[i];
		}
	}	
	int shift = -minNumber;	
	int *valueArray = new int[maxNumber + shift + 1] {};
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		valueArray[array[i] + shift]++;
	}
	for (int i = 0; i < maxNumber + shift + 1; i++)
	{
		int operCounter = valueArray[i];
		while (operCounter > 0)
		{
			array[counter] = i - shift;
			counter++;
			operCounter--;
		}
	}
	delete[] valueArray;
}

bool testCountSort()
{
	bool isCorrectly = true;
	int size = dipRand(9000, 11000);
	int *testArray = new int[size];
	int oneElement = dipRand();
	int oneElementArray[1] = { oneElement };
	int simElementsArray[100];
	int simElement = dipRand(10, 1000);
	int maxNumber = 0;
	for (int i = 0; i < size; i++)
	{
		testArray[i] = dipRand(1, 100);
		if (testArray[i] > maxNumber)
		{
			maxNumber = testArray[i];          
		}
	}
	for (int i = 0; i < 100; i++)
	{
		simElementsArray[i] = simElement;
	}
	int hugeValuesArray[] = { 10000002, 10000001, 10000009 };
	int *testValueArray1 = new int[maxNumber + 1]{};
	int *testValueArray2 = new int[maxNumber + 1]{};
	for (int i = 0; i < size; i++)
	{
		testValueArray1[testArray[i]]++;
	}

	countSort(hugeValuesArray, 3);     //  sorting all
	countSort(testArray, size);        //  test arrays
	countSort(oneElementArray, 1);     
	countSort(simElementsArray, 100);

	for (int i = 0; i < 2; i++)
	{
		if (hugeValuesArray[i] > hugeValuesArray[i + 1])
		{
			isCorrectly = false;
		}
	}
	for (int i = 0; i < size; i++)
	{
		testValueArray2[testArray[i]]++;
	}

	for (int i = 0; i < maxNumber + 1; i++)
	{
		if (testValueArray1[i] != testValueArray2[i])      //test value array compare
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
	if (oneElementArray[0] != oneElement)
	{
		isCorrectly = false;
	}
	for (int i = 0; i < 100; i++)
	{
		if (simElementsArray[i] != simElement)
		{
			isCorrectly = false;
		}
	}

	delete[] testValueArray1;
	delete[] testValueArray2;
	return isCorrectly;
}

bool testBubbleSort()
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
	bubbleSort(testArray, size);
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
	delete[] testValueArray1;
	delete[] testValueArray2;
	return isCorrectly;
}

int main()
{
	if (!testBubbleSort() || !testCountSort())
	{
		if (!testBubbleSort())
		{
			printf("Bubble sort work incorrectly\n");
		}
		if (!testCountSort())
		{
			printf("Count sort work incorrectly\n");
		}
		return 0;
	}
	int size = 0;
	printf("Input size of array:\n");
	scanf_s("%i", &size);
	if (size <= 0)
	{
		printf("Incorrect value of size\n");
		return 0;
	}
	int *array1 = new int[size];
	int *array2 = new int[size];
	printf("Input array:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%i", &array1[i]);
		array2[i] = array1[i];
	}
	countSort(array1, size);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "Count sort: %i" : "%i", array1[i], array1[i]);
		printf((i == size - 1) ? "\n" : ", ");
	}
	bubbleSort(array2, size);
	for (int i = 0; i < size; i++)
	{
		printf((i == 0) ? "Bubble sort: %i" : "%i", array2[i], array2[i]);
		printf((i == size - 1) ? "\n" : ", ");
	}
	delete[] array1;
	delete[] array2;
	return 0;
}

