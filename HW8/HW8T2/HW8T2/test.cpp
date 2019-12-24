#include "tree.h"
#include "test.h"

bool test()
{

	char expr1[] = "+ (- 9 (* 2 3)) (/ 8 2)";
	int answer1 = getAnswer(expr1);
	char expr2[] = "* (+ 5 4) (- 8 2)";
	int answer2 = getAnswer(expr2);
	char expr3[] = "- 7 4";
	int answer3 = getAnswer(expr3);
	if (answer1 == 7 && answer2 == 54 && answer3 == 3)
	{
		return true;
	}
	return false;
}