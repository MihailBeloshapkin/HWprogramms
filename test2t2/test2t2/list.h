#pragma once

struct List;

// Check that list is symmetric.
bool checkThatSymmetric(List *list);

// Add to list back.
void addToListBack(List **list, int newData);

// Display all data from list.
void display(List *list);

// Delete list.
void deleteList(List **list);
