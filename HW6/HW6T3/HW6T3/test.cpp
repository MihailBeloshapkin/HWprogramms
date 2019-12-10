#include "pch.h"
#include "test.h"
#include "HW6T3.h"
#include "createPostfix.h"

bool isSimilar(char *string1, const char *string2)
{
	int index = 0;
	while (string1[index + 1] != '\0' || string2[index + 1] != '\0')
	{
		if (string1[index] != string2[index])
		{
			return false;
		}
		index++;
	}
	return true;
}

bool test()
{
	char testExample1[] = "2 * (3 + 5 * 4) - 7 ";
	char rightAnswer1[] = "2 3 5 4 * + * 7 - ";
	char funcAnswer1[100]{};
	createPostfix(testExample1, funcAnswer1);
	if (!isSimilar(funcAnswer1, rightAnswer1))
	{
		return false;
	}
	char testExample2[] = "4 * 7 - 1 * (2 + 3) ";
	char rightAnswer2[] = "4 7 * 1 2 3 + * - ";
	char funcAnswer2[100]{};
	createPostfix(testExample2, funcAnswer2);
	if (!isSimilar(funcAnswer2, rightAnswer2))
	{
		return false;
	}
	char testExample3[] = "(3 + 4 * 7 - 1) * (2 + 5 * 4)";
	char rightAnswer3[] = "3 4 7 * + 1 - 2 5 4 * + * ";
	char funcAnswer3[100]{};
	createPostfix(testExample3, funcAnswer3);
	if (!isSimilar(funcAnswer3, rightAnswer3))
	{
		return false;
	}
	return true;
}
