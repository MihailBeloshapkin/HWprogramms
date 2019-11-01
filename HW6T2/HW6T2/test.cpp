#include "pch.h"
#include "HW6T2.h"
#include <stdio.h>

bool test()
{
	char test1[100] = "[{(})]";
	if (isBalanced(test1, 100))
	{
		return false;
	}
	char test2[100] = "{}()[{}]";
	if (!isBalanced(test2, 100))
	{
		return false;
	}
	char test3[100] = "{[}]{}{{}";
	if (isBalanced(test3, 100))
	{
		return false;
	}
	return true;
}