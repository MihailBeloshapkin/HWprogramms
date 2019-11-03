#include "pch.h"
#include <stdio.h>
int main()
{
	int n = 0;
	printf("Input integer number:");
	scanf_s("%i", &n);
	bool *array = new bool[n] {};
	for (int i = 2; i * i < n; i++)
	{
		if (!array[i])
		{
			for (int j = i * i; j < n; j += i)
			{
				array[j] = true;
			}
		}
	}
	printf("\nSimple numbers:\n");
	for (int i = 2; i < n; i++)
	{
		if (!array[i])
			printf("%i, ", i);
	}
	delete[]array;
	return 0;
}



