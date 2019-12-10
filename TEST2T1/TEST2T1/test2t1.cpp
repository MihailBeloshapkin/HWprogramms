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
	List *testList = nullptr;
	FILE *testFile = fopen("test.txt", "r");
	scanner(testFile, &testList);
	fclose(testFile);
	List *answer = turnOverList(testList);
	List *rightAnswer = createList();
	rightAnswer = nullptr;
	addToListBack(&rightAnswer, 5);
	addToListBack(&rightAnswer, 4);
	addToListBack(&rightAnswer, 3);
	addToListBack(&rightAnswer, 2);
	addToListBack(&rightAnswer, 1);
	if (!compareLists(answer, rightAnswer))
	{
		deleteList(&answer);
		deleteList(&rightAnswer);
		deleteList(&testList);
		return false;
	}
	deleteList(&answer);
	deleteList(&rightAnswer);
	deleteList(&testList);
	return true;
}

int main()
{
	if (!test())
	{
		printf("Incorrect work\n");
		getchar();
		return -1;
	}
	List *list = nullptr;
	List *turnedList = nullptr;
	FILE *file = fopen("data.txt", "r");
	scanner(file, &list);
	fclose(file);
	display(list);
	printf("\n");
	turnedList = turnOverList(list);
	display(turnedList);
	deleteList(&list);
	deleteList(&turnedList);
	getchar();
	return 0;
}
