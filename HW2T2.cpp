#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int dipRand(int minValue = 3, int maxValue = 10)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

int raiseDegree(int number, int degree)
{
	int answer = number;
	if (degree == 0)
	{
		return 1;
	}
	for (int i = 1; i < degree; i++)
	{
		answer *= number;
	}
	return answer;
}

int logRaiseDegree(int number, int degree)
{
	if (degree == 0)
	{
		return 1;
	}
	int answer = 1;
	while (degree > 0)
	{
		if (degree % 2 == 0)
		{
			number *= number;
			degree /= 2;
		}
		else
		{
			answer *= number;
			degree--;
		}
	}
	return answer;
}

bool testLogDegree()
{
	bool isCorrectly = true;
	if (logRaiseDegree(15, 0) != 1)
	{
		printf("Incorrect work with (15, 0) arguments\n");
		isCorrectly = false;
	}
	if (logRaiseDegree(0, 0) != 1)
	{
		printf("Incorrect work with (0, 0) arguments\n");
		isCorrectly = false;
	}
	int testNumber = dipRand();
	int testDegree = dipRand();
	if (logRaiseDegree(testNumber, testDegree) != pow(testNumber, testDegree))
	{
		printf("Incorrect work with random values\n");
		isCorrectly = false;
	}
	return isCorrectly;
}

bool testLinearDegree()
{
	bool isCorrectly = true;
	if (raiseDegree(15, 0) != 1)
	{
		isCorrectly = false;
		printf("Incorrect work with (15, 0) arguments\n");
	}
	if (raiseDegree(0, 0) != 1)
	{
		isCorrectly = false;
		printf("Incorrect work with (0, 0) arguments\n");
	}
	int testNumber = dipRand();
	int testDegree = dipRand();
	if (raiseDegree(testNumber, testDegree) != pow(testNumber, testDegree))
	{
		printf("Incorrect work with random values\n");
		isCorrectly = false;
	}
	return isCorrectly;
}

int main()
{
	if (!testLinearDegree() || !testLogDegree())
	{
		if (!testLinearDegree())
		{
			printf("linear raise degree works incorrectly\n");
		}
		if (!testLogDegree())
		{
			printf("logariphm raise degree works incorrectly\n");
		}
		return 0;
	}
	int number = 0;
	int degree = 0;
	bool run = true;
	while (run)
	{
		printf("0 - exit\n"
			   "1 - input values\n"
			   "2 - linear calculation\n"
			   "3 - logariphm calculation\n");
		char tip = '0';
		scanf_s("%c", &tip);
		switch (tip)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("Input number:\n");
			scanf_s("%i", &number);
			printf("Input degree:\n");
			scanf_s("%i", &degree);
			break;
		case '2':
			printf("Answer is: %i\n", raiseDegree(number, degree));
			break;
		case '3':
			printf("Anwer is: %i\n", logRaiseDegree(number, degree));
			break;
		}
	}
	return 0;
}