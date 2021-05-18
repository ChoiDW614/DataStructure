#include <iostream>
#include <stdlib.h>
#include "ArrayBaseStack.h"

int main()
{
    // create and initialze the stack /////
    Stack stack;
    StackInit(&stack);

    // push data /////
    SPush(&stack, 1);   SPush(&stack, 2);
    SPush(&stack, 3);   SPush(&stack, 4);
    SPush(&stack, 5);

    // pop data /////
    while (!SIsEmpty(&stack))
        std::cout << SPop(&stack) << " ";

    system("PAUSE");
    return 0;
}