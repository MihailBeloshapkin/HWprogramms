#include <stdio.h>
#include "utils.h"
#include "tree.h"
#include "test.h"

int main()
{
	if (!test())
	{
		printf("Incorrect work\n");
		return -1;
	}
	Tree *tree = nullptr;
	bool run = true;
	int key = 0;
	while (run)
	{
		printf("0 - exit\n"
			   "1 - add data by key\n"
			   "2 - get data\n"
			   "3 - check inclusion of the key\n"
		       "4 - delete data by key\n"
		       "5 - display\n"
		       "6 - delete tree\n"
		       "7 - load data from file\n");
		const char choice = getchar();
		clearInput();
		switch (choice)
		{
		case '0':
			run = false;
			break;
		case '1':
		{
			char newData[100]{};
			printf("Input new key:\n");
			scanf("%i", &key);
			printf("Input new data:\n");
			clearInput();
			getString(newData, 100);
			add(&tree, key, newData);
			break;
		}
		case '2':
		{
			printf("Input key:\n");
			scanf("%i", &key);
			char *data = searchByKey(tree, key);
			printf((data != nullptr) ? "Data: %s" : "No data on the given key\n", data);
			break;
		}
		case '3':
		{
			printf("Input key:\n");
			scanf("%i", &key);
			printf(checkInclusion(tree, key) ? "Key %i is included" : "Key %i is not included", key);
			break;
		}
		case '4':
		{
			printf("Input key:\n");
			scanf("%i", &key);
			deleteElement(&tree, key);
			break;
		}
		case '5':
			printf("\n\n");
			displayTree(tree, 0);
			break;
		case '6':
			deleteTree(&tree);
			break;
		case '7':
		{
			FILE *file = fopen("data.txt", "r");
			loadData(&tree, file);
			fclose(file);
			printf("\nThe tree is filled\n");
			break;
		}
		}
		printf("\n\n\n");
	}
	deleteTree(&tree);
	return 0;
}