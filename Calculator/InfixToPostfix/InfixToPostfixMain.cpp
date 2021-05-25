#include <iostream>
#include "InfixToPostfix.h"

int main()
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(epx3);

    std::cout << "'" << exp1 << "'" << endl;
    std::cout << "'" << exp2 << "'" << endl;
    std::cout << "'" << exp3 << "'" << endl;

    return 0;
}