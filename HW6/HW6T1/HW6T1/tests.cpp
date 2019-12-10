#include "pch.h"
#include "evaluator.h"
#include <stdio.h>

bool test()
{
	char test1[100] = "2 2 + 7 4 - * 5 *";
	if (eval(test1) != 60)
	{
		return false;
	}
	char test2[100] = "9 1 + 7 * 9 +";
	if (eval(test2) != 79)
	{
		return false;
	}
	char test3[100] = "4 3 * 1 5 + /";
	if (eval(test3) != 2)
	{
		return false;
	}
	return true;
}
