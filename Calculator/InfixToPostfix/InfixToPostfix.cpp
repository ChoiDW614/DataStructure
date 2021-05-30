#include <cstring>
#include <cctype>
#include "InfixToPostfix.h"
#include "D:/Github/DataStructure/Calculator/ListBaseStack/ListBaseStack.h"

#define _CRT_SECURE_NO_WARNINGS

int GetOpPrec(char Op)
{
    switch(Op)
    {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
        default: ;
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
    Stack stack;
    int expLen = (int)strlen(exp);
    char * convExp = new char[expLen+1];

    int i = 0;
    int idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char) * (expLen + 1));
    StackInit(&stack);

    for (i = 0; i < expLen; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch(tok)
            {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(true)
                    {
                        popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;

                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                        convExp[idx++] = SPop(&stack);

                    SPush(&stack, tok);
                    break;
                default: ;
                    //THIS CODE BLOCK SHOULD NEVER BE EXECUTED!
            }
        }
    }

    while(!SIsEmpty((&stack)))
        convExp[idx++] = SPop(&stack);

    strcpy(exp, convExp);
    delete convExp;
}