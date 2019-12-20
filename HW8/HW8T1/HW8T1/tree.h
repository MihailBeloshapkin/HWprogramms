#pragma once

struct Tree;

// Return key from tree element.
int returnKey(Tree *tree);

// Return key from more.
int returnKeyFromMore(Tree *tree);

// Return key from less.
int returnKeyFromLess(Tree *tree);

// Return more.
Tree *returnMore(Tree *tree);

// Return less.
Tree *returnLess(Tree *tree);

// Add new data and key.
void add(Tree **tree, int key, char *newData);

// Display all data from tree.
void displayTree(Tree *tree, int level);

// Search data on the given key.
char *searchByKey(Tree *tree, int key);

// Check the inclusion.
bool checkInclusion(Tree *tree, int key);

// Delete element from tree.
void deleteElement(Tree **tree, int key);

// Delete tree.
void deleteTree(Tree **tree);
