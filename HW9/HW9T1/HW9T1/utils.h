#pragma once
#include "tree.h"

// Get string from console.
void getString(char *str, int maxSize);

// Copy data.
char *copy(char *string);

// Load data from file.
void loadData(Tree **tree, FILE *file);

// Clear input.
void clearInput();

// Return module of random integer value.
int module(int value);

// Load data from file.
void loadData(Tree** tree, FILE* file);

// Return max value.
int max(int number1, int number2);