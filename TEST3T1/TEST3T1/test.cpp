#include "list.h"

bool isSorted(List *list)
{
	int prevElement = returnData(list);
	while (returnNextPointer(list) != nullptr)
	{
		shiftNext(&list);
		if (returnData(list) < prevElement)
		{
			return false;
		}
		prevElement = returnData(list);
	}
	return true;
}

bool test()
{
	List *testList = nullptr;
	int testArray[] = {5, 4, 1, 4, 8, 5, 4, 7, 5, 4, 5, 9, 5, 0};
	for (int index = 0; testArray[index] != 0; index++)
	{
		add(&testList, testArray[index]);
	}
	if (!isSorted(testList))
	{
		deleteList(&testList);
		return false;
	}
	deleteList(&testList);
	return true;
}