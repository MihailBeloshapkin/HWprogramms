#include "list.h"
#include "test.h"

bool test()
{
	List *testList = nullptr;
	const int size = 5;
	int testArray[size] = { 1, 4, 5, 7, 9 };  // Fill test array with test values for list
	add(&testList, testArray[4]);
	add(&testList, testArray[1]);
	add(&testList, testArray[0]);
	add(&testList, testArray[2]);
	add(&testList, testArray[3]);
	for (int i = 0; i < size; i++)
	{
		if (returnData(testList) != testArray[i])
		{
			return false;
		}
		if (i == size - 1)
		{
			break;
		}
		shiftNext(&testList);
	}
	return true;
}