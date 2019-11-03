// HW1T6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

void GetStr(char *Str, int MaxLen)
{
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n')
		if (Str != NULL && i < MaxLen - 1)
			Str[i++] = ch;
	if (Str != NULL && i < MaxLen)
		Str[i] = 0;
}

int main()
{
	int counter = 0;
	int operationCounter = 0;
	bool isSimilar = true;
	const int stringSize1 = 13;
	const int stringSize2 = 4;
	char string1[stringSize1] = "bckbcdbqbckc";
	char string2[stringSize2] = "bck";

	for (int i = 0; i < stringSize1 - stringSize2 + 1; i++) {
		while (isSimilar && operationCounter < stringSize2 - 1) {
			if (string1[i + operationCounter] != string2[operationCounter]) {
				isSimilar = false;
			}
			operationCounter++;
		}
		if (isSimilar) {
			counter++;
		}
		operationCounter = 0;
		isSimilar = true;
	}
	printf("Answer:%i", counter);
}
