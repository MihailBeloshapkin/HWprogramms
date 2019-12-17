#include <stdio.h>

const int countStrings = 3;
const int countColumns = 4;

void dislpay(float array[countStrings][countColumns])
{
	for (int i = 0; i < countStrings; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			float current = array[countStrings][countColumns];
			printf((j == countColumns - 1) ? "%f\n" : "%f  ", array[i][j]);
		}
	}
}

bool checkThatBiggestInColumn(float array[countStrings][countColumns], float element, int columnNumber)
{
	for (int j = 0; j < countColumns; j++)
	{
		if (array[j][columnNumber] > element)
		{
			return false;
		}
	}
	return true;
}

bool checkThatSmallestInString(float array[countStrings][countColumns], float element, int stringNumber)
{
	for (int j = 0; j < countStrings; j++)
	{
		if (array[stringNumber][j] < element)
		{
			return false;
		}
	}
	return true;
}

void search(float array[countStrings][countColumns])
{
	for (int i = 0; i < countStrings; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			if (checkThatSmallestInString(array, array[i][j], i) && checkThatBiggestInColumn(array, array[i][j], j))
			{
				printf("%f; ", array[i][j]);
			}
		}
	}
}

int main()
{
	float array[countStrings][countColumns] = { { 1.4, 1.6, 1.0, 5.7 }, 
	                                            { 1.2, 1.9, 1.1, 5.3 }, 
	                                            { 0.9, 6.8, 0.9, 5.6 } };
	search(array);
	getchar();
	return 0;
}