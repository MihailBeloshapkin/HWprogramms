#include <stdio.h>
#include <string.h>
#include "test.h"
#include "utils.h"
#include "tree.h"

void testBinaryTree(Tree *tree, bool *isCorrect)
{
	if (tree == nullptr)
	{
		return;
	}
	if (*isCorrect == false)
	{
		return;
	}
	if (returnMore(tree) != nullptr && returnKeyFromMore(tree) < returnKey(tree))
	{
		*isCorrect = false;
		return;
	}
	if (returnLess(tree) != nullptr && returnKeyFromLess(tree) > returnKey(tree))
	{
		*isCorrect = false;
		return;
	}
	testBinaryTree(returnMore(tree), isCorrect);
	testBinaryTree(returnLess(tree), isCorrect);
}

bool test()
{
	Tree *tree = nullptr;
	FILE *testFile = fopen("test.txt", "r");
	loadData(&tree, testFile);
	fclose(testFile);
	bool isCorrect = true;
	testBinaryTree(tree, &isCorrect);
	if (!isCorrect)
	{
		deleteTree(&tree);
		return false;
	}
	char rightAnswer1[] = "data";
	char rightAnswer2[] = "list";
	char rightAnswer3[] = "pointer";
	char rightAnswer4[] = "stack";
	if (strcmp(searchByKey(tree, 40), rightAnswer1) != 0)
	{
		deleteTree(&tree);
		return false;
	}
	if (strcmp(searchByKey(tree, 30), rightAnswer2) != 0)
	{
		deleteTree(&tree);
		return false;
	}
	if (strcmp(searchByKey(tree, 45), rightAnswer3) != 0)
	{
		deleteTree(&tree);
		return false;
	}
	if (strcmp(searchByKey(tree, 10), rightAnswer4) != 0)
	{
		deleteTree(&tree);
		return false;
	}
	bool isCorrect1 = true;	
	deleteElement(&tree, 40);
	testBinaryTree(tree, &isCorrect1);

	bool isCorrect2 = true;
	deleteElement(&tree, 30);
	testBinaryTree(tree, &isCorrect2);

	bool isCorrect3 = true;
	deleteElement(&tree, 10);
	testBinaryTree(tree, &isCorrect3);
	
	if (!isCorrect1 || !isCorrect2 || !isCorrect3)
	{
		deleteTree(&tree);
		return false;
	}
	deleteTree(&tree);
	return true;
}