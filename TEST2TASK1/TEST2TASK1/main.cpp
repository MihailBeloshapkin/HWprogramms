#include "list.h"
#include <stdio.h>
#include "test.h"

void getString(char *str, int maxSize)
{
	int i = 0;
	char symbol = ' ';
	while ((symbol = getchar()) != '\n')
	{
		if (str != nullptr && i < maxSize - 1)
		{
			str[i++] = symbol;
		}
	}
	if (str != nullptr && i < maxSize)
	{
		str[i] = 0;
	}
}

int main()
{
	if (!test())
	{
		printf("Incorrect work of search function\n");
		getchar();
		return -1;
	}
	char input[100]{};
	List *list = nullptr;
	printf("Input list:\n");
	getString(input, 100);
	scanner(input, &list);
	display(list);
	printf("\nAnswer list: ");
	display(searchLongest(list));
	getchar();
	return 0;
}