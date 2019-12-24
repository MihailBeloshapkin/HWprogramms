#include <ctype.h>
#include "scanner.h"


bool scanner(char *expr)
{
	int index = 0;
	int state = 0;

	while (true)
	{
		switch (state)
		{
		case 0:
			if (isdigit(expr[index]))
			{
				state = 1;
				break;
			}
			if (expr[index] == '+' || expr[index] == '-')
			{
				state = -1;
				break;
			}
			return false;
		case -1:
			if (isdigit(expr[index]))
			{
				state = 1;
				break;
			}
			return false;
		case 1:
			if (isdigit(expr[index]))
			{
				break;
			}
			if (expr[index] == '.')
			{
				state = 2;
				break;
			}
			if (expr[index] == '\0')
			{
				return true;
			}
			if (expr[index] == 'E')
			{
				state = 3;
				break;
			}
			return false;
		case 2:
			if (isdigit(expr[index]))
			{
				state = 4;
				break;
			}
			return false;
		case 3:
			if (expr[index] == '+' || expr[index] == '-')
			{
				state = 5;
				break;
			}
			if (isdigit(expr[index]))
			{
				state = 6;
				break;
			}
			return false;
		case 4:
			if (isdigit(expr[index]))
			{
				break;
			}
			if (expr[index] == 'E')
			{
				state = 3;
				break;
			}
			if (expr[index] == '\0')
			{
				return true;
			}
			return false;
		case 5:
			if (isdigit(expr[index]))
			{
				state = 6;
				break;
			}
			return false;
		case 6:
			if (isdigit(expr[index]))
			{
				break;
			}
			if (expr[index] == '\0')
			{
				return true;
			}
			return false;
		}
		index++;
	}
}