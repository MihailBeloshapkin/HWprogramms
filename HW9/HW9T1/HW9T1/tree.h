#pragma once

struct Tree;

// Return more.
Tree* returnMore(Tree* tree);

// Return less.
Tree* returnLess(Tree* tree);

// Add data in tree and balance.
Tree* addition(Tree** tree, int key, char* newData);

// Display all data from tree.
void display(Tree *tree, int level);

// Search data on the given key.
char *searchByKey(Tree *tree, int key);

// Check the inclusion.
bool checkInclusion(Tree *tree, int key);

// Delete element from tree.
Tree *deleteElement(Tree **tree, int key);

// Delete tree.
void deleteTree(Tree **tree);

// Return balance factor.
int balanceFactor(Tree* tree);