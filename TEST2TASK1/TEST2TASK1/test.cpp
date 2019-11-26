#include "list.h"

bool test()
{
	List *testList = nullptr;
	List *rightAnswer = nullptr;
	addToListBack(&rightAnswer, 1);  // Fill rigth test list
	addToListBack(&rightAnswer, 2);  // with
	addToListBack(&rightAnswer, 3);  // values

	addToListBack(&testList, 1);
	addToListBack(&testList, 2);
	addToListBack(&testList, 3);
	addToListBack(&testList, 0);
	addToListBack(&testList, 9);
	addToListBack(&testList, 2);

	List *answer = searchLongest(testList);
	while (answer != nullptr || rightAnswer != nullptr)
	{
		if (answer->data != rightAnswer->data)
		{
			return false;
		}
		answer = answer->next;
		rightAnswer = rightAnswer->next;
	}
	return true;
}