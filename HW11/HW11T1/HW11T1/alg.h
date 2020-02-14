#pragma once
#include "list.h"

// Create array of lists.
List** createArrayOfLists(int size);

// Delete array of lists.
void deleteArrayOfLists(List** arrayOfLists, int sizeOfArray);

// Create matrix.
int** createMatrix(int size);

// Delete matrix.
void deleteMatrix(int** matrix, int size);

// Accomondation of cities.
List** game(int* graph[], int size, int* capitals, int countOfCapitals);