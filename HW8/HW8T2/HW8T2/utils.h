#pragma once

// Get string.
void getString(char *str, int maxSize);

// Load data from file.
void load(FILE *file, char *outExpr);

// Check that operation.
bool isOperation(char symbol);

// Scan digit.
int digitScanner(char *str);

// Check that number.
bool isNumber(char *string);

// Check that expression.
bool isExpression(char *string);