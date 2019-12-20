#include <stdio.h>
#include <string.h>
#include "list.h"
#include "utils.h"
#include "hash.h"

struct Hash
{
	float fillCoef;
	int hashTableSize;
	List **list = new List *[hashTableSize];
};

float returnFillCoef(Hash *table)
{
	return table->fillCoef;
}

void changeFillCoef(Hash **table, float newFillCoef)
{
	(*table)->fillCoef = newFillCoef;
}

void addToHashTable(Hash **table, char *newData);

Hash *createHash(int sizeOfHash)
{
	Hash *table = new Hash{ 0.0, sizeOfHash };
	for (int i = 0; i < table->hashTableSize; i++)
	{
		table->list[i] = nullptr;
	}
	return table;
}

void deleteHash(Hash *table)
{
	for (int i = 0; i < table->hashTableSize; i++)
	{
		deleteList(&table->list[i]);
	}
	delete table->list;
	delete table;
}

int hashFunction(char *value, Hash *table)
{
	int result = 0;
	for (int i = 0; value[i] != '\0'; i++)
	{
		result = (result + value[i]) % table->hashTableSize;
	}
	return result;
}

void displayHashTable(Hash *table)
{
	for (int i = 0; i < table->hashTableSize; i++)
	{
		printf(i < 10 ? "0%i: " : "%i: ", i);
		displayList(table->list[i]);
	}
	printf("\n\nHash table size: %i\n\n", table->hashTableSize);
	printf("Fill coef: %f\n\n", table->fillCoef);
	printf("\n\n\n");
}

void displayData(Hash *table, FILE *file)
{
	for (int i = 0; i < table->hashTableSize; i++)
	{
		if (table->list[i] != nullptr)
		{
			displayListToFile(table->list[i], file);
		}
	}
	printf("\n\nHash table size: %i\n\n", table->hashTableSize);
	printf("Fill coef: %f\n\n", table->fillCoef);
	printf("\n\n\n");
}

void displayToFile(Hash *table, FILE *file)
{
	for (int i = 0; i < table->hashTableSize; i++)
	{
		fprintf(file, i < 10 ? "0%i: " : "%i: ", i);
		displayListToFile(table->list[i], file);
	}
	fprintf(file, "\n\nHash table size: %i\n\n", table->hashTableSize);
	fprintf(file, "Fill coef: %f\n\n", table->fillCoef);
	fprintf(file, "\n\n\n");
}

int sizeOfList(List *list)
{
	int count = 0;
	while (list != nullptr)
	{
		count++;
		shiftNext(&list);
	}
	return count;
}

float countFillCoef(Hash *table)
{
	int numberOfElements = 0;
	for (int i = 0; i < table->hashTableSize; i++)
	{
		numberOfElements += sizeOfList(table->list[i]);
	}
	return (float)numberOfElements / table->hashTableSize;
}

Hash *expansion(Hash *oldTable)
{
	Hash *newTable = createHash(oldTable->hashTableSize * 2);
	for (int i = 0; i < oldTable->hashTableSize; i++)
	{
		List *current = oldTable->list[i];
		while (current != nullptr)
		{
			addToHashTable(&newTable, returnData(current));
			shiftNext(&current);
		}
		deleteList(&oldTable->list[i]);
	}
	deleteHash(oldTable);
	return newTable;
}

void addToHashTable(Hash **table, char *newData)
{
	if ((*table)->fillCoef > 1.1)
	{
		*table = expansion(*table);
	}
	addToList(&(*table)->list[hashFunction(newData, *table)], newData);
}

void loadData(Hash **table, FILE *file)
{
	while (!feof(file))
	{
		char symbol = '\0';
		char newData[100]{};
		int i = 0;
		while (isLetter(symbol = fgetc(file)) && !feof(file))
		{
			newData[i] = symbol;
			i++;
		}
		if (strlen(newData) != 0)
		{
			addToHashTable(table, newData);
		}
		(*table)->fillCoef = countFillCoef(*table);
	}
}

void countMaxAndMidLength(Hash *table, float *midLength, int *maxLength)
{
	int sumOfLength = 0;
	*maxLength = sizeOfList(table->list[0]);
	for (int index = 1; index < table->hashTableSize; index++)
	{
		int currentLength = sizeOfList(table->list[index]);
		if (currentLength > *maxLength)
		{
			*maxLength = currentLength;
		}
		sumOfLength += currentLength;
	}
	*midLength = (float)sumOfLength / table->hashTableSize;
}

void displayStatisticToFile(Hash *table, FILE *file)
{
	int maxLen = 0;
	float midLen = 0;
	countMaxAndMidLength(table, &midLen, &maxLen);
	fprintf(file, "\nFill coef: %f", table->fillCoef);
	fprintf(file, "\nMid len: %f", midLen);
	fprintf(file, "\nMax len: %i", maxLen);

}

bool isIncluded(Hash *table, char *data)
{
	List *current = table->list[hashFunction(data, table)];
	while (current != nullptr)
	{
		if (strcmp(returnData(current), data) == 0)
		{
			return true;
		}
		shiftNext(&current);
	}
	return false;
}