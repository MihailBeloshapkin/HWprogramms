#pragma once

struct List;

// Add data to list.
void add(List** list, int newDistance, int newVertex);

// Delete from list fromt.
int delFromListFront(List** list, int* deletedDistance);

// Delete all data from list.
void deleteList(List** list);

// Check that list is empty.
bool isEmpty(List* list);

// Return vertex.
int returnVertex(List* list);

// Delete chosen vertex from list.
void deleteVertex(List** list, int deleteVertex);