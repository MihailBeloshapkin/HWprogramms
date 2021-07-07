#include <stdio.h>
#include "list.h"

void scanner(FILE *file, List **list)
{
	while (!feof(file))
	{
		int value = 0;
		fscanf(file, "%i", &value);
		addToListBack(list, value);
	}
}

bool test()
{
	const int testArraySize1 = 7;
	const int testArraySize2 = 6;
	const int testArraySize3 = 8;
	int testArray1[testArraySize1] = { 1, 3, 7, 2, 7, 3, 1 };
	int testArray2[testArraySize2] = { 1, 2, 3, 2, 5, 1 };
	int testArray3[testArraySize3] = { 1, 4, 2, 7, 7, 2, 4, 1 };
	List *testList1 = nullptr;
	List *testList2 = nullptr;
	List *testList3 = nullptr;
	for (int i = 0; i < testArraySize1; i++)
	{
		addToListBack(&testList1, testArray1[i]);
	}
	for (int i = 0; i < testArraySize2; i++)
	{
		addToListBack(&testList2, testArray2[i]);
	}
	for (int i = 0; i < testArraySize3; i++)
	{
		addToListBack(&testList3, testArray3[i]);
	}
	if (!checkThatSymmetric(testList1) || !checkThatSymmetric(testList3))
	{
		deleteList(&testList1);
		deleteList(&testList2);
		deleteList(&testList3);
		return false;
	}
	if (checkThatSymmetric(testList2))
	{
		deleteList(&testList1);
		deleteList(&testList2);
		deleteList(&testList3);
		return false;
	}
	deleteList(&testList1);
	deleteList(&testList2);
	deleteList(&testList3);
	return true;
}

int main()
{
	if (!test())
	{
		printf("Incorrect work\n");
		return -1;
	}
	List *list = nullptr;
	FILE *file = fopen("data.txt", "r");
	scanner(file, &list);
	fclose(file);
	display(list);
	printf(checkThatSymmetric(list) ? "\nIs symmetric\n" : "\nIs not symmetric\n");
	deleteList(&list);
	getchar();
	return 0;
}