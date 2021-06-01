#include <iostream>
#include <cstdio>
#include "ExpressionTree.h"

int main()
{
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    std::cout << "Formula for prefix: ";
    ShowPrefixTypeExp(eTree);
    std::cout << std::endl;

    std::cout << "Formula for infix: ";
    ShowInfixTypeExp(eTree);
    std::cout << std::endl;

    std::cout << "Formula for postfix: ";
    ShowPostfixTypeExp(eTree);
    std::cout << std::endl;

    std::cout << "Result of operation: ";
    printf("%d ", EvaluateExpTree(eTree));

    return 0;
}