#include <string.h>

void prefixFunction(char* string, int sizeOfString, int* pi)
{
	pi[0] = 0;
	int prefixIndex = 0;
	int suffixIndex = 1;

	while (suffixIndex < sizeOfString)
	{
		if (string[prefixIndex] != string[suffixIndex])
		{
			if (prefixIndex == 0)
			{
				pi[suffixIndex] = 0;
				suffixIndex++;
			}
			else
			{
				prefixIndex = pi[prefixIndex - 1];
			}
		}
		else
		{
			pi[suffixIndex] = prefixIndex + 1;
			suffixIndex++;
			prefixIndex++;
		}
	}
}
	
int searchCoincidence(char* string, char* subString, int stringSize, int subStringSize)
{
	int* pi = new int[subStringSize] {};
	prefixFunction(subString, subStringSize, pi);

	int indexOfString = 0;
	int indexOfSubString = 0;
	while (indexOfString < stringSize)
	{
		if (string[indexOfString] == subString[indexOfSubString])
		{
			if (indexOfSubString == subStringSize - 1)
			{
				return indexOfString;
			}
			indexOfString++;
			indexOfSubString++;
		}
		else
		{
			if (indexOfSubString == 0)
			{
				indexOfString++;
			}
			else
			{
				indexOfSubString = pi[indexOfSubString - 1];
			}
		}
	}
	return -1;
}