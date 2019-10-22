// HW1T1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

int main()
{
	int x, x_square;
	scanf_s("%i", &x);
	x_square = x * x;
	
	printf("%i", (x_square + 1)*(x_square + x) + 1);
}

