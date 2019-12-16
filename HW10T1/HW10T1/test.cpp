#include <stdio.h>
#include "hash.h"
#include "list.h"
#include "utils.h"

bool test()
{
	Hash *testTable = createHash(5);
	FILE *testFile = fopen("test.txt", "r");
	while (!feof(testFile))
	{
		char symbol = '\0';
		char newData[100]{};
		int i = 0;
		while (isLetter(symbol = fgetc(testFile)) && !feof(testFile))
		{
			newData[i] = symbol;
			i++;
		}
		addToHashTable(&testTable, newData);
		changeFillCoef(&testTable, countFillCoef(testTable));
	}
	fclose(testFile);
	char word1[] = "information";
	char word2[] = "hash";
	char word3[] = "does";
	char word4[] = "exists";
	if (!isIncluded(testTable, word1))
	{
		deleteHash(testTable);
		return false;
	}
	if (!isIncluded(testTable, word2))
	{
		deleteHash(testTable);
		return false;
	}
	if (!isIncluded(testTable, word3))
	{
		deleteHash(testTable);
		return false;
	}
	if (!isIncluded(testTable, word4))
	{
		deleteHash(testTable);
		return false;
	}
	deleteHash(testTable);
	return true;
}