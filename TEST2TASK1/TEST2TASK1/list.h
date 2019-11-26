#pragma once

struct List
{
	int data;
	List *next;
 };

// Add to list back.
void addToListBack(List **list, int newData);

// Scan the expression and put numbers to list.
void scanner(char *input, List **list);

// Search most longes list.
List *searchLongest(List *list);

// Display all data from list.
void display(List *list);