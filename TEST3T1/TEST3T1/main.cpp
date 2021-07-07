#include <stdio.h>
#include "list.h"
#include "test.h"

int main()
{
	if (!test())
	{
		printf("Incorrect work\n");
		getchar();
		return -1;
	}
	List *list = nullptr;
	int currentData = 1;
	printf("Input data:\n");
	while (true)
	{
		scanf_s("%i", &currentData);
		if (currentData == 0)
		{
			break;
		}
		add(&list, currentData);
	}
	display(list);
	deleteList(&list);
	getchar();
	getchar();
	return  0;
}