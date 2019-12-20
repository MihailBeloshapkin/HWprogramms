#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "utils.h"

struct Tree
{
	int key;
	char *data;
	Tree *less;
	Tree *more;
};

int returnKey(Tree *tree)
{
	return tree->key;
}

int returnKeyFromMore(Tree *tree)
{
	return tree->more->key;
}

int returnKeyFromLess(Tree *tree)
{
	return tree->less->key;
}

Tree *returnMore(Tree *tree)
{
	return tree->more;
}

Tree *returnLess(Tree *tree)
{
	return tree->less;
}

void displayTree(Tree *tree, int level)
{
	if (tree == nullptr)
	{
		return;
	}
	displayTree(tree->more, level + 1);
	printf("%*c%i(%s)\n", level * 8, ' ', tree->key, tree->data);
	displayTree(tree->less, level + 1);
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

void add(Tree **tree, int key, char *newData)
{
	Tree *newElement = new Tree{ key, copy(newData), nullptr, nullptr };
	if (*tree == nullptr)
	{
		*tree = newElement;
		return;
	}
	while (true)
	{
		if (key > (*tree)->key)
		{
			if ((*tree)->more == nullptr)
			{
				(*tree)->more = newElement;
				return;
			}
			tree = &(*tree)->more;
		}
		if (key < (*tree)->key)
		{
			if ((*tree)->less == nullptr)
			{
				(*tree)->less = newElement;
				return;
			}
			tree = &(*tree)->less;
		}
		if (key == (*tree)->key)
		{
			(*tree)->data = newData;
			return;
		}
	}
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

void copyDataFromElement(Tree *element1, Tree *element2)
{
	element2->key = element1->key;
	element2->data = element1->data;
}

bool checkThatLeaf(Tree *tree)
{
	return tree->less == nullptr && tree->more == nullptr;
}

void deleteElement(Tree **tree, int key)
{
	while (*tree != nullptr)
	{
		if ((*tree)->key == key)
		{
			break;
		}
		if ((*tree)->key > key)
		{
			tree = &(*tree)->less;
		}
		else if ((*tree)->key < key)
		{
			tree = &(*tree)->more;
		}
	}
	if (*tree == nullptr)
	{
		return;
	}
	Tree *keyElement = *tree;
	if (checkThatLeaf(keyElement))
	{
		*tree = nullptr;
		delete keyElement->data;
		delete keyElement;
		return;
	}
	Tree *oldData = nullptr;
	if ((*tree)->more != nullptr)
	{
		tree = &(*tree)->more;
		while ((*tree)->less != nullptr)
		{
			tree = &(*tree)->less;
		}
		delete keyElement->data;
		copyDataFromElement(*tree, keyElement);
		oldData = *tree;
		*tree = (*tree)->more;
		delete oldData;
		return;
	}
	if ((*tree)->less != nullptr)
	{
		tree = &(*tree)->less;
		while ((*tree)->more != nullptr)
		{
			tree = &(*tree)->more;
		}
		delete keyElement->data;
		copyDataFromElement(*tree, keyElement);
		oldData = *tree;
		*tree = (*tree)->less;
		delete oldData;
	}
}