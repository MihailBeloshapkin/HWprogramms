#include <stdio.h>
#include "list.h"
#include "test.h"

void clearInput()
{
	while (getchar() != '\n')
	{
	}
}

int main()
{
	if (!test())
	{
		printf("List functions work incorrectly\n");
		getchar();
		return -1;	
	}  
	List *list = nullptr;
	bool run = true;
	while (run)
	{
		printf("\n0 - exit\n"
			   "1 - add data\n"
			   "2 - delete data\n"
			   "3 - display data\n");
		const char choice = getchar();
		switch (choice)
		{
		case '0':
			run = false;
			break;
		case '1':
		{
			int newData = 0;
			printf("Input new data\n");
			scanf_s("%i", &newData);
			add(&list, newData);
			break;
		}
		case '2':
		{
			int deleteElement = 0;
			printf("Input element: ");
			scanf_s("%i", &deleteElement);
			deleteData(&list, deleteElement);
			break;
		}
		case '3':
			display(list);
			break;
		case '\n':
			printf("slash n\n");
			break;
		default:
			printf("\nUnrecognised command: %c\n", choice);
			break;
		}
		clearInput();
	}
	return 0;
}