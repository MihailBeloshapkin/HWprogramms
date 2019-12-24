#include <stdio.h>
#include "tree.h"
#include "utils.h"
#include "test.h"

int main()
{
	if (!test())
	{
		printf("Incorrecct work");
		getchar();
		return -1;
	}
	char expr[100]{};
	FILE *file = fopen("data.txt", "r");
	load(file, expr);
	fclose(file);

	int answer = getAnswer(expr);
	printf("\nAnswer is %i", answer);
	getchar();
	return 0;
}