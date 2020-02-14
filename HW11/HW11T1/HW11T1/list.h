#pragma once

struct List;

// Add to list back.
void addToListBack(List** list, int newData);

// Delete from list fromt.
int delFromListFront(List** list);

// Delete all data from list.
void deleteList(List** list);

// Check that list is empty.
bool isEmpty(List* list);

// Return vertex.
int returnVertex(List* list);

// Delete chosen vertex from list.
void deleteVertex(List** list, int deleteVertex);

// Shift next.
void shiftNext(List** list);

//Display all data from list.
void displayList(List* list);

// Compare two lists and return resuilt of comparison.
bool compareLists(List* list1, List* list2);