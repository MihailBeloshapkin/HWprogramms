#include "pch.h"
#include <stdio.h>

int main()
{
	int size_of_array, counter = 0;
	printf("Input size of array of integer numbers:\n");
	scanf_s("%i", &size_of_array);
	int *Array = new int [size_of_array];
	printf("Input array:");
	for (int i = 0; i < size_of_array; i++)
	{
		scanf_s("%i", &Array[i]);
		if (Array[i] == 0)
		{
			counter++;
		}
	}
	printf("%i", counter);
	delete []Array;
	return 0;
}
