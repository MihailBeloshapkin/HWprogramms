#include <stdio.h>
#include <string.h>
#include "test.h"
#include "tree.h"
#include "utils.h"

void checkThatBalance(Tree *tree, bool *isBalanced)
{
	if (tree == nullptr)
	{
		return;
	}
	if (balanceFactor(tree) > 1 || balanceFactor(tree) < -1)
	{
		*isBalanced = false;
	}
	checkThatBalance(returnLess(tree), isBalanced);
	checkThatBalance(returnMore(tree), isBalanced);
}

bool test()
{
	Tree* testTree = nullptr;
	bool isBalanced = true;
	FILE* testFile = fopen("data.txt", "r");
	loadData(&testTree, testFile);
	fclose(testFile);
	checkThatBalance(testTree, &isBalanced);
	if (!isBalanced)
	{
		deleteTree(&testTree);
		return false;
	}

	char rightAnswer1[] = "data";
	char rightAnswer2[] = "list";
	char rightAnswer3[] = "pointer";
	char rightAnswer4[] = "stack";

	if (strcmp(searchByKey(testTree, 40), rightAnswer1) != 0)
	{
		deleteTree(&testTree);
		return false;
	}
	if (strcmp(searchByKey(testTree, 30), rightAnswer2) != 0)
	{
		deleteTree(&testTree);
		return false;
	}
	if (strcmp(searchByKey(testTree, 45), rightAnswer3) != 0)
	{
		deleteTree(&testTree);
		return false;
	}
	if (strcmp(searchByKey(testTree, 10), rightAnswer4) != 0)
	{
		deleteTree(&testTree);
		return false;
	}
	deleteElement(&testTree, 40);
	if (checkInclusion(testTree, 40))
	{
		deleteTree(&testTree);
		return false;
	}
	bool isBalanced1 = true;
	checkThatBalance(testTree, &isBalanced1);
	if (!isBalanced1)
	{
		deleteTree(&testTree);
		return false;
	}
	deleteTree(&testTree);
	return true;
}