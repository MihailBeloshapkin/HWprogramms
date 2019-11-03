#include "pch.h"
#include "notebook.h"
#include <stdio.h>

int searchPhone(note *data, char *name, int size)
{
	for (int index = 0; index < size; index++)
	{
		if (isSimilar(data[index].name, name, 30))
		{
			return index;
		}
	}
}

int searchName(note *data, char *phone, int size)
{
	bool isIncluded = false;
	for (int index = 0; index < size; index++)
	{
		if (isSimilar(data[index].phoneNumber, phone, 30))
		{
			isIncluded = true;
			return index;
		}
	}
	if (!isIncluded)
	{
		return -1;
	}
}