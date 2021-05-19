#include <iostream>
#include <cstring>
#include <cctype>
#include "InfixToPostfix.h"
#include "D:/Github/DataStructure/Calculator/ListBaseStack.h"

int GetOpPrec(char Op)
{
    switch(Op)
    {
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
    }

    return -1;
}

int WhoPrecOp(char Op1, char Op2)
{
    if (GetOpPrec(Op1) > GetOpPrec(Op2))        // if op1 has a higher priority
        return 1;
    else if(GetOpPrec(Op1) < GetOpPrec(Op2))    // if op2 has a higher priority
        return -1;
    else
        return 0;                               // if op1 and op2 have the same priority
}

void ConvToRPNExp(char exp[])
{

}