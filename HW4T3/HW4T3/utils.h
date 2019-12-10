#pragma once
#include <stdio.h>

// Scan string from console.
void getString(char *str, int maxSize);

// Clear input.
void clearInput();

// Displaying all content. 
void displayData(Note *data, int count);

// Check the similarity of two strings.
bool isSimilar(char *string1, const char *string2);

// Save all content if file.
void saveData(Note *data, int size, FILE *file);

// Load all content from file.
int loadData(Note *data, FILE *file);