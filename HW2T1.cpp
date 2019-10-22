#include "pch.h"
#include <iostream>

int recCalculateFib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else {
		return recCalculateFib(n - 1) + recCalculateFib(n - 2);
	}
}

int iterCalculateFib(int n)
{
	int fibArray[3] {1, 1, 0};
	for (int i = 0; i < n - 2; i++)
	{
		fibArray[2] = fibArray[0] + fibArray[1];
		fibArray[0] = fibArray[1];
		fibArray[1] = fibArray[2];
	}
	return fibArray[2];
}
int main()
{
	int n = 0;
	printf("Input value:\n");
	scanf_s("%i", &n);
	int fib1 = recCalculateFib(n);
	int fib2 = iterCalculateFib(n);
	printf("Fibanacci number recursion: %i\nibanacci number iteration: %i\n", fib1, fib2);
	return 0;
}