#include <iostream>
#include "SimpleHeap.h"
using namespace std;

int main()
{
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'a', 1);
    HInsert(&heap, 'b', 2);
    HInsert(&heap, 'c', 3);

    HInsert(&heap, 'a', 1);
    HInsert(&heap, 'b', 2);
    HInsert(&heap, 'c', 3);

    return 0;
}