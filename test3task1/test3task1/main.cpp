#include <stdio.h>

const int countRows = 5;
const int countColumns = 6;

bool isTrueArray(bool isIncl[countRows])
{
	for (int i = 0; i < countRows; i++)
	{
		if (!isIncl[i])
		{
			return false;
		}
	}
	return true;
}

void analyse(int array[countRows][countColumns], int vertex, bool isAnalysed[countRows])
{
	if (isTrueArray(isAnalysed))
	{
		return;
	}
	isAnalysed[vertex] = true;
	bool newVertex[countRows]{};
	newVertex[vertex] = true;
	for (int i = 0; i < countColumns; i++)
	{
		if (array[vertex][i] == 1)
		{
			for (int j = 0; j < countRows; j++)
			{
				if (array[j][i] == -1)
				{
					newVertex[j] = true;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < countRows; i++)
	{
		if (newVertex[i] && !isAnalysed[i])
		{
			analyse(array, i, isAnalysed);
		}
	}
	
}

void findConditionVertex(int array[countRows][countColumns])
{
	for (int i = 0; i < countRows; i++)
	{
		bool isAnalysed[countRows]{};
		analyse(array, i, isAnalysed);
		if (isTrueArray(isAnalysed))
		{
			printf("%i, ", i);
		}
	}
}

int main()
{
	int array[countRows][countColumns] = { {-1, 0, 0, -1, 0, 0},
										   {1, -1, 0, 0, 0, 0},
	                                       {0, 1, 1, 0, 0, -1}, 
	                                       {0, 0, -1, 1, 1, 0}, 
	                                       {0, 0, 0, 0, -1, 1} };

	bool isAnalysed[countRows]{};
	
	findConditionVertex(array);

	getchar();
	return 0;
}