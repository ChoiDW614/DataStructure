#include <iostream>
#include "DBLinkedList.h"

int main()
{
    using namespace std;
    
    // create and initialize the doubly linked list /////
    List list;
    int data;
    ListInit(&list);

    // save 8 data /////
    LInsert(&list, 1); LInsert(&list, 2);
    LInsert(&list, 3); LInsert(&list, 4);
    LInsert(&list, 5); LInsert(&list, 6);
    LInsert(&list, 7); LInsert(&list, 8);

    // Query stored data /////
    if (LFirst(&list, &data))
    {
        cout << data << ", ";
        
        while (LNext(&list, &data))
        {
            cout << data << ", ";
        }

        while (LPrevious(&list, &data))
        {
            cout << data << ", ";
        }
    }

    return 0;
}