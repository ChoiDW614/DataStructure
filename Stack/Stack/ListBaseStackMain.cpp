#include <iostream>
#include <stdlib.h>
#include "ListBaseStack.h"

int main()
{
    // create and initialize the stack /////
    Stack stack;
    StackInit(&stack);

    // Push data /////
    SPush(&stack, 1);   SPush(&stack, 2);
    SPush(&stack, 3);   SPush(&stack, 4);
    SPush(&stack, 5);

    // Pop data /////
    while (!SIsEmpty(&stack))
        std::cout << SPop(&stack) << " ";

    system("PAUSE");
    return 0;
}