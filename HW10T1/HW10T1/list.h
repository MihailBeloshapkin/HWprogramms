#pragma once


struct List;

// Return data from list element.
char *returnData(List *list);

//Return count from list. 
int returnCount(List *list);

// Shift to next element into list.
void shiftNext(List **list);

// Display all data from list. 
void displayList(List *list);

// Display list to file.
void displayListToFile(List *list, FILE *file);

// Add data to list.
void addToList(List **list, char *newData);

// Delete all data from list.
void deleteList(List **list);