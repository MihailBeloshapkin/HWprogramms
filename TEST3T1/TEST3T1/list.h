#pragma once

struct List;

// Return data from list pointer.
int returnData(List *list);

// Return count.
int returnCount(List *list);

// Shift to next element from list pointer.
void shiftNext(List **list);

// Return next list element pointer.
List *returnNextPointer(List *list);

// Add new data.
void add(List **list, int newData);

// Delete list.
void deleteList(List **list);

// Display all data.
void display(List *list);
