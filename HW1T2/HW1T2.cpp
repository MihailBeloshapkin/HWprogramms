#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath> 

int dipRand(int minValue = 2, int maxValue = 15)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

int divide(int dividend, int divider)
{
	int answer = 0; 
	int modDividend = fabs(dividend);
	int modDivider = fabs(divider);
	int quotient = modDivider;
	bool isBalance = true;
	while (quotient <= modDividend)
	{
		if (quotient == modDividend)
		{
			isBalance = false;
		}
		answer++;
		quotient += modDivider;
	}
    
	if ((dividend >= 0 && divider > 0) || (dividend <= 0 && divider < 0))
	{
		return answer;
	}
	if (dividend >= 0 && divider < 0)
	{
		return -answer;
	}
	if (dividend < 0 && divider > 0)
	{
		if (!isBalance)
		{
			return -answer;
		}
		return -(answer + 1);
	}
	return 0;
}

bool test()
{
	bool isCorrectly = true;
	int testDividend = dipRand(10, 20);
	int testDivider = dipRand(2, 9);
	if (divide(testDividend, testDivider) != (int)((float)testDividend / testDivider))
	{
		printf("Incorrect work with random values\n");
		isCorrectly = false;
	}
	if (divide(-7, 3) != -3)
	{
		printf("Incorrect work with (-7, 3) arguments\n");
		isCorrectly = false;
	}
	if (divide(7, -3) != -2)
	{
		printf("Incorrect work with (7, -3) arguments\n");
		isCorrectly = false;
	}
	if (divide(10, 3) != 3)
	{
		printf("Incorrect work with (10, 3) arguments\n");
		isCorrectly = false;
	}
	if (divide(-10, -3) != 3)
	{
		printf("Incorrect work with (-10, -3) arguments\n");
		isCorrectly = false;
	}
	if (divide(9, 3) != 3)
	{
		printf("Incorrect work with (9, 3) arguments\n");
		isCorrectly = false;
	}
	if (divide(9, -3) != -3)
	{
		printf("Incorrect work with (9, -3) arguments\n");
		isCorrectly = false;
	}
	return isCorrectly;
}

int main() 
{ 
	if (!test())
	{
		printf("Incorrect work divide function\n");
		return -1;
	}
	int dividend = 0; 
	int divider = 0; 
	printf("Input dividend:\n"); 
	scanf_s("%d", &dividend); 
	printf("Input divider:\n");
	scanf_s("%d", &divider); 
	if (divider == 0)
	{
		printf("Incorrect value of divider\n");
		return 0;
	}
	printf("Answer is: %i\n", divide(dividend, divider));
	return 0;
}