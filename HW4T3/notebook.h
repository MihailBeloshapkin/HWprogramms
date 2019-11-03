#pragma once
#include <stdio.h>

struct note
{
	char phoneNumber[30]{};
	char name[30]{};
};

void getString(char *str, int maxSize);
void clearInput();
void displayData(note *data, int count);
bool isSimilar(char *string1, char *string2, int size);
int searchPhone(note *data, char *name, int size);
int searchName(note *data, char *phone, int size);
void saveData(note *data, int size, FILE *file);
int loadData(note *data, FILE *file);