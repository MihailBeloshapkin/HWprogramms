#pragma once
#include "list.h"

struct Hash;

// Return fill coef from hash table.
float returnFillCoef(Hash *table);

// change fill coef in hash table.
void changeFillCoef(Hash **table, float newFillCoef);

// Create hash table and return new table pointer.
Hash *createHash(int sizeOfHash);

// Add data to hash table.
void addToHashTable(Hash **table, char *newData);

// Display statistics.
void displayStatisticToFile(Hash *table, FILE *file);

// Display all data from hash table.
void displayHashTable(Hash *table);

// Display data.
void displayData(Hash *table, FILE *file);

// Display hash table data into file.
void displayToFile(Hash *table, FILE *file);

// Load data from file to hash table.
void loadData(Hash **table, FILE *file);

// Count max and middle length of lists in hash table.
void countMaxAndMidLength(Hash *table, float *midLength, int *maxLength);

// Count fill coef.
float countFillCoef(Hash *table);

// Delete all data from hash table.
void deleteHash(Hash *table);

// Check the inclusion of data into has table.
bool isIncluded(Hash *table, char *data);