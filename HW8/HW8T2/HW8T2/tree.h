#pragma once

struct Tree;


void scannerExpr(char *expr, char *operation, char *operand1, char *operand2);

// Accomondation numbers and operations into binary tree.
void accomondation(Tree **tree, char *string);

// Display all data from tree.
void displayTree(Tree *tree, int level);

// Calculation.
void calculation(Tree **tree);

// Return number from tree elemment.
int returnNumber(Tree *tree);

// Delete tree.
void deleteTree(Tree **tree);

// Get answer from prefix expression.
int getAnswer(char *expr);
