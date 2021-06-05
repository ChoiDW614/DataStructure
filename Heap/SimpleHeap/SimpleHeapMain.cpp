#include <iostream>
#include "SimpleHeap.h"
using namespace std;

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main()
{

    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'a');
    HInsert(&heap, 'b');
    HInsert(&heap, 'c');
    cout << HDelete(&heap) << " ";


    HInsert(&heap, 'a');
    HInsert(&heap, 'b');
    HInsert(&heap, 'c');
    cout << HDelete(&heap) << " ";

    while(!HIsEmpty(&heap))
        cout << HDelete(&heap) << " ";

    return 0;
}