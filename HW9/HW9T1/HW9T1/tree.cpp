#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "utils.h"

struct Tree
{
	int key;
	char *data;
	int height = 0;
	Tree *less;
	Tree *more;
};

Tree* returnMore(Tree* tree)
{
	return tree->more;
}

Tree* returnLess(Tree* tree)
{
	return tree->less;
}

void display(Tree *tree, int level)
{
	if (tree == nullptr)
	{
		return;
	}
	display(tree->more, level + 1);
	printf("%*c%i(%s)\n", level * 8, ' ', tree->key, tree->data);
	display(tree->less, level + 1);
}

void deleteTree(Tree **tree)
{
	if (*tree == nullptr)
	{
		return;
	}
	deleteTree(&(*tree)->more);
	deleteTree(&(*tree)->less);
	Tree *oldData = *tree;
	*tree = nullptr;
	delete oldData->data;
	delete oldData;
}

int height(Tree* tree)
{
	return tree != nullptr ? tree->height : 0;
}

int balanceFactor(Tree* tree)
{
	return height(tree->more) - height(tree->less);
}

void updateHeight(Tree** tree)
{
	int heightLeft = height((*tree)->less);
	int heightRight = height((*tree)->more);
	(*tree)->height = max(heightLeft, heightRight) + 1;
}

Tree *search(Tree *tree, int key)
{
	while (tree != nullptr)
	{
		if (tree->key == key)
		{
			return tree;
		}
		if (tree->key > key)
		{
			tree = tree->less;
		}
		else if (tree->key < key)
		{
			tree = tree->more;
		}
	}
	return tree;
}

char *searchByKey(Tree *tree, int key)
{
	Tree *keyElement = search(tree, key);
	if (keyElement == nullptr)
	{
		return nullptr;
	}
	return keyElement->data;
}

bool checkInclusion(Tree *tree, int key)
{
	return search(tree, key) != nullptr;
}

Tree* smallLeftTurn(Tree **tree)
{
	Tree *rightSubTree = (*tree)->more;
	(*tree)->more = rightSubTree->less;
	rightSubTree->less = *tree;
	updateHeight(tree);
	updateHeight(&rightSubTree);
	return rightSubTree;
}

Tree* smallRightTurn(Tree **tree)
{
	Tree* leftSubTree = (*tree)->less;
	(*tree)->less = leftSubTree->more;
	leftSubTree->more = *tree;
	updateHeight(tree);
	updateHeight(&leftSubTree);
	return leftSubTree;
}

Tree* balancingVertex(Tree** tree)
{
	updateHeight(tree);
	if (balanceFactor(*tree) == 2)
	{
		if (balanceFactor((*tree)->more) < 0)
		{
			(*tree)->more = smallRightTurn(&(*tree)->more);
		}
		return smallLeftTurn(tree);
	}
	if (balanceFactor(*tree) == -2)
	{
		if (balanceFactor((*tree)->less) > 0)
		{
			(*tree)->less = smallLeftTurn(&(*tree)->less);
		}
		return smallRightTurn(tree);
	}
	return *tree;
}

Tree* addition(Tree** tree, int key, char* newData)
{
	if (*tree == nullptr)
	{
		Tree* newElement = new Tree{ key, copy(newData), 1, nullptr };
		return newElement;
	}
	if ((*tree)->key == key)
	{
		strcpy((*tree)->data, newData);
		return *tree;
	}
	if ((*tree)->key > key)
	{
		(*tree)->less = addition(&(*tree)->less, key, newData);
	}
	else
	{
		(*tree)->more = addition(&(*tree)->more, key, newData);
	}
	return balancingVertex(tree);
}

Tree* searchMin(Tree *tree)
{
	while (tree->less != nullptr)
	{
		tree = tree->less;
	}
	return tree;
}

Tree* deleteMin(Tree** tree)
{
	if (*tree == nullptr)
	{
		return nullptr;
	}
	if ((*tree)->less == nullptr)
	{
		return (*tree)->more;
	}
	(*tree)->less = deleteMin(&(*tree)->less);
	return balancingVertex(tree);
}

Tree* deleteElement(Tree** tree, int key)
{
	if (*tree == nullptr)
	{
		return nullptr;
	}
	if (key < (*tree)->key)
	{
		(*tree)->less = deleteElement(&(*tree)->less, key);
	}
	if (key > (*tree)->key)
	{
		(*tree)->more = deleteElement(&(*tree)->more, key);
	}
	if (key == (*tree)->key)
	{
		Tree* rightSubTree = (*tree)->more;
		Tree* leftSubTree = (*tree)->less;
		delete (*tree)->data;
		delete* tree;
		if (rightSubTree == nullptr)
		{
			return leftSubTree;
		}
		Tree* minInRightSubTree = searchMin(rightSubTree);
		minInRightSubTree->more = deleteMin(&rightSubTree);
		minInRightSubTree->less = leftSubTree;
		return balancingVertex(&minInRightSubTree);
	}
	return balancingVertex(tree);
}