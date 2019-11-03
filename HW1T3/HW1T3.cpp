// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>



int main()
{
	int tmp, counter = 0;
	const int m = 3, n = 4, N = m + n;
	int Array[N];
	printf("Input array of integer numbers:\n");
    for (int i = 0; i < N; i++)
		scanf_s("%i", &Array[i]);

	for (int i = 0; i < m; i++) {
		tmp = Array[0];
		for (int j = 0; j < m - i; j++) {
			Array[j] = Array[j + 1];
		}
		Array[m - 1 - i] = tmp;
	}
	for (int i = m; i < N; i++) {
		tmp = Array[m];
		for (int j = m; j < N - counter; j++) {
			Array[j] = Array[j + 1];
		}
		Array[N - 1 - counter] = tmp;
		counter++;
	}
	for (int i = 0; i < N; i++) {
		tmp = Array[0];
		for (int j = 0; j < N - i; j++) {
			Array[j] = Array[j + 1];
		}
		Array[N - 1 - i] = tmp;
	}

	
	for (int i = 0; i < N; i++)
		printf("%i, ", Array[i]);

		
}

