#include <stdio.h>
#include "scanner.h"

bool test()
{
	char example1[] = "1234.5678E-45";
	char example2[] = "1234.5678E-45";
	char example3[] = "E542765";
	char example4[] = "4321.567.34";
	char example5[] = "7834";
	char example6[] = "0.12E+90";
	return scanner(example1) && scanner(example2) && !scanner(example3) && !scanner(example4) && scanner(example5) && scanner(example6);
}

int main()
{
	if (!test())
	{
		return -1;
	}
	char expr[100]{};
	printf("Input expr:\n");
	scanf("%s", expr);
	printf(scanner(expr) ? "Is number" : "Is not number");
	getchar();
	getchar();
	return 0;
}