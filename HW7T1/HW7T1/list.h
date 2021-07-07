#pragma once

struct List;

// Create new list.
List *createList();

// Return data from list pointer.
int returnData(List *list);

// Shift to next element from list pointer.
void shiftNext(List **list);

// Add new data.
void add(List **list, int newData);

// Delete element from list.
void deleteData(List **list, int deleteData);

// Display all data.
void display(List *list);