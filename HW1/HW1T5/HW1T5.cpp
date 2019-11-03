// HW1T5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <string.h>
#include <stdio.h>

void GetStr(char *Str, int MaxLen)
{
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n')
		if (Str != NULL && i < MaxLen - 1)
			Str[i++] = ch;
	if (Str != NULL && i < MaxLen)
		Str[i] = 0;
}

int main()
{	
	int counter = 0;
	const int sizeOfString = 9;
	bool isBalance = true;
	char string[] = "()()(())";
	for (int i = 0; i < sizeOfString; i++)
	{
		if (counter < 0)
		{
			isBalance = false;
		}
		switch (string[i])
		{
		case '(':
			counter++;
			break;
		case ')':
			counter--;
			break;
		default:
			break;
		}
	}
	if (counter == 0 && isBalance)
	{
		printf("The string is balanced");
	}
	else
	{
		printf("The string is not balanced");
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
