// HW1T4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	int array[28] = {};
	int counter = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
			{
				array[i + j + k]++;
		
			}
	for (int i = 0; i < 28; i++)
	{
		counter += array[i] * array[i];
	}
	printf("Count of happy tickets: %i", counter);
	return 0;
}
