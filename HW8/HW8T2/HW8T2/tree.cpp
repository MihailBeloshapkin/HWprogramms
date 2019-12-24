#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "utils.h"

typedef enum Id
{
	operation,
	number,
};

struct Tree
{
	Id id;
	char operation;
	int number;
	Tree *more = nullptr;
	Tree *less = nullptr;
};

int returnNumber(Tree *tree)
{
	return tree->number;
}

void deleteTree(Tree **tree)
{
	if (*tree == nullptr)
	{
		return;
	}
	deleteTree(&(*tree)->more);
	deleteTree(&(*tree)->less);
	Tree *oldData = *tree;
	*tree = nullptr;
	delete oldData;
}

void scanExprIntoBrackets(char *expr, int *index , char *outExpr)
{
	int outIndex = 0;
	int bracketCounter = 1;
	(*index)++;
	while (bracketCounter != 0)
	{
		if (!(expr[*index] == ')' && bracketCounter == 1))
		{
			outExpr[outIndex] = expr[*index];
		}
		if (expr[*index] == '(')
		{
			bracketCounter++;
		}
		if (expr[*index] == ')')
		{
			bracketCounter--;
		}
		(*index)++;
		outIndex++;
	}
}

void scanOperand(char *expr, char *operand, int *index)
{
	if (expr[*index] == '(')
	{
		scanExprIntoBrackets(expr, index, operand);
		(*index)++;
	}
	else
	{
		int indexOPerand = 0;
		while (isdigit(expr[*index]))
		{
			operand[indexOPerand] = expr[*index];
			(*index)++;
			indexOPerand++;
		}
	}
}

void scannerExpr(char *expr, char *operation, char *operand1, char *operand2)
{
	int index = 0;
	bool operatorIncl = false;
	bool operandIncl1 = false;
	bool operandIncl2 = false;
	while (expr[index] != '\0')
	{
		if (isOperation(expr[index]) && !operatorIncl)
		{
			operatorIncl = true;
			*operation = expr[index];
			index++;
		}
		if (operatorIncl && !operandIncl1 && (isdigit(expr[index]) || isOperation(expr[index]) || expr[index] == '('))
		{
			scanOperand(expr, operand1, &index);
			operandIncl1 = true;
		}
		if (operatorIncl && operandIncl1 && !operandIncl2 && (isdigit(expr[index]) || isOperation(expr[index]) || expr[index] == '('))
		{
			scanOperand(expr, operand2, &index);
			operandIncl2 = true;
		}
		index++;
	}
}

char *copy(char *string)
{
	char *str = new char[strlen(string) + 1]{};
	strcpy(str, string);
	return str;
}

void displayTree(Tree *tree, int level)
{
	if (tree == nullptr)
	{
		return;
	}
	displayTree(tree->more, level + 1);
	if (tree->id == number)
	{
		printf("%*c%i\n", level * 8, ' ', tree->number);
	}
	if (tree->id == operation)
	{
		printf("%*c%c\n", level * 8, ' ', tree->operation);

	}
	displayTree(tree->less, level + 1);
}

void accomondation(Tree **tree, char *string)
{
	Tree *newElement = new Tree;
	if (isExpression(string))
	{
		char currentOperation = '\0';
		char operand1[30]{};
		char operand2[30]{};
		scannerExpr(string, &currentOperation, operand1, operand2);
		newElement->id = operation;
		newElement->operation = currentOperation;
		*tree = newElement;
		accomondation(&(*tree)->less, operand1);
		accomondation(&(*tree)->more, operand2);
	}
	else
	{
		newElement->number = digitScanner(string);
		newElement->id = number;
		*tree = newElement;
	}
}

int eval(char operation, int firstNumber, int secondNumber)
{
	switch (operation)
	{
	case '+':
		return firstNumber + secondNumber;
	case '-':
		return firstNumber - secondNumber;
	case '*':
		return firstNumber * secondNumber;
	case '/':
		return firstNumber / secondNumber;
	default:
		printf("Unrecognised char: %c\n", operation);
	}
	return -1;
}

void calculation(Tree **tree)
{
	if (*tree == nullptr)
	{
		return;
	}
	calculation(&(*tree)->more);
	calculation(&(*tree)->less);
	if ((*tree)->less != nullptr && (*tree)->more != nullptr)
	{
		(*tree)->id = number;
		(*tree)->number = eval((*tree)->operation, (*tree)->less->number, (*tree)->more->number);
	}
}

int getAnswer(char *expr)
{
	Tree *tree = nullptr;
	accomondation(&tree, expr);
	calculation(&tree);
	int answer = tree->number;
	deleteTree(&tree);
	return answer;
}