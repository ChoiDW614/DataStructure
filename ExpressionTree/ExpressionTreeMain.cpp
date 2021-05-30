#include <iostream>
#include "ExpressionTree.h"

int main()
{
    char exp[] = "327*+";
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

    return 0;
}