#include <iostream>
#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("PrefixType expression: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("InfixType expression: ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("PostfixType expression: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("result of expression: %d \n", EvaluateExpTree(eTree));

	return 0;
}