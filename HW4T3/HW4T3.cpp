#include "pch.h"
#include "notebook.h"
#include <stdio.h>

int main()
{
	note data[100];
	bool run = true;
	FILE *file = fopen("data.txt", "a+");
	int index = loadData(data, file);
	char name[30]{};
	char phone[30]{};
	fclose(file);
	while (run)
	{
		printf("\n0 - exit\n"
			"1 - add data\n"
		   "2 - display data\n"
		   "3 - search phone\n"
		   "4 - search name\n"
		   "5 - save data\n");
		char choise = getchar();
		clearInput();
		switch (choise)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("\nInput name:\n");
			getString(data[index].name, 30);
			printf("\nInput number:\n");
			getString(data[index].phoneNumber, 30);
			index++;
			break;
		case '2':
			printf("\n");
			displayData(data, index);
			break;
		case '3':
			printf("Input name:\n");
			getString(name, 30);
			printf("Phone Number: %s", data[searchPhone(data, name, index)].phoneNumber);
			break;
		case '4':
			printf("Input phone number:\n");
			getString(phone, 30);
			printf("Name: %s", data[searchName(data, phone, index)].name);
			break;
		case '5':
			FILE *file = fopen("data.txt", "w");
			printf("Data saved");
			saveData(data, index, file);
			fclose(file);
			break;
		}
	}
	return 0;
}
