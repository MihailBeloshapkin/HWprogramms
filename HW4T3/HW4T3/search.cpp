#include "pch.h"
#include "search.h"
#include "utils.h"
#include <stdio.h>

int searchPhone(Note *data, const char *name, int size)
{
	for (int index = 0; index < size; index++)
	{
		if (isSimilar(data[index].name, name))
		{
			return index;
		}
	}
	return -1;
}

int searchName(Note *data, const char *phone, int size)
{
	for (int index = 0; index < size; index++)
	{
		if (isSimilar(data[index].phoneNumber, phone))
		{
			return index;
		}
	}
	return -1;
}