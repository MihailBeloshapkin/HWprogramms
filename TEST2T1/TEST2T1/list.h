#pragma once

struct List;

// Create new list.
List *createList();

// Add to list back.
void addToListBack(List **list, int newData);

// Delete list.
void deleteList(List **list);

// Compare two lists.
bool compareLists(List *firstList, List *secondList);

// Display all data from list.
void display(List *list);

// Turn the input list.
List *turnOverList(List *list);


