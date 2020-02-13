#include <string.h>
#include "test.h"
#include "alg.h"

bool test()
{
	char testString[] = "abcdgacdeabeabde";
	char testSubString[] = "acde";
	return searchCoincidence(testString, testSubString, strlen(testString), strlen(testSubString)) == 8;
}