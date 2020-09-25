#include "pch.h"
#include "notebook.h"
#include "utils.h"
#include "search.h"
#include "test.h"
#include <string.h>
#include <stdio.h>

bool testSearch()
{
	FILE *testFile = fopen("test.txt", "a+");
	Note testData[15];
	loadData(testData, testFile);
	char phone2[] = "775-13-55";
	char name1[] = "Bob";
	char name2[] = "Tatiana";
	char incorrectName[] = "ewyfgww";
	if (searchName(testData, "843-35-12", 15) != 3)
	{
		return false;
	}
	if (searchName(testData, phone2, 15) != 0)
	{
		return false;
	}
	if (searchPhone(testData, name1, 15) != 2)
	{
		return false;
	}
	if (searchPhone(testData, name2, 15) != 1)
	{
		return false;
	}
	if (searchPhone(testData, incorrectName, 15) != -1)
	{
		return false;
	}
	fclose(testFile);
	return true;
}

void fillData(Note *data)
{
	strcpy(data[0].name, "Ilya");
	strcpy(data[1].name, "Tatiana");
	strcpy(data[2].name, "Bob");
	strcpy(data[3].name, "John");
	strcpy(data[0].phoneNumber, "775-13-55");
	strcpy(data[1].phoneNumber, "243-18-94");
	strcpy(data[2].phoneNumber, "138-46-89");
	strcpy(data[3].phoneNumber, "843-35-12");
}

bool testLoadData()
{
	FILE *testFile = fopen("test.txt", "a+");
	const int sizeOfNote = 4;
	Note testData[sizeOfNote];
	Note filledData[sizeOfNote];
	loadData(testData, testFile);
	fillData(filledData);
	for (int index = 0; index < sizeOfNote; index++)
	{
		if (!isSimilar(testData[index].name, filledData[index].name))
		{
			return false;
		}
	}
	fclose(testFile);
	return true;
}