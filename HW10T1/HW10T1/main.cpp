#include <stdio.h>
#include "utils.h"
#include "hash.h"
#include "test.h"

void clearInput()
{
	while (getchar() != '\n')
	{
	}
}

int main()
{
	if (!test())
	{
		return -1;
	}
	Hash *table = createHash(5);
	int maxLength = 0;     //  Variables to count max and 
	float midLength = 0;   //  mid length of lists into hash table
	bool run = true;
	char newData[100]{};
	char fileName[100]{};
	char displayFileName[100]{};
	while (run)
	{
		printf("0 - exit\n"
			   "1 - display to file\n"
		       "2 - display\n"
			   "3 - load data from file\n");
		const char choice = getchar();
		clearInput();
		switch (choice)
		{
		case '0':
			run = 0;
			deleteHash(table);
			return 0;
		case '1':
		{
			printf("Input file name to save:");
			getString(displayFileName, 100);
			FILE *saveFile = fopen(displayFileName, "w");
			displayData(table, saveFile);
			displayStatisticToFile(table, saveFile);
			fclose(saveFile);
			break;
		}
		case '2':
			displayHashTable(table);
			countMaxAndMidLength(table, &midLength, &maxLength);
			printf("\nMax length of list: %i\nMid length of list: %i\n", maxLength, midLength);
			printf("\n");
			break;
		case '3':
			printf("Input file name:\n");
			getString(fileName, 100);
			FILE *file = fopen(fileName, "r");          // File variables to save
			loadData(&table, file);
			fclose(file);
			break;
		}
	}
	deleteHash(table);
	return 0;
}