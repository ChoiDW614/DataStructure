#include <iostream>
#include "CLinkedList.h"

int main()
{
    using namespace std;

    // create and initialize a circle linkedlist /////
    List list;
    Data data;
    int i, nodeNum;
    ListInit(&list);

    // save 5 data to list /////
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    // output data stored in the list three times in a row /////
    if (LFirst(&list, &data))
    {
        cout << data << " ";

        for (i = 0; i < LCount(&list) * 3 - 1; i++)
        {
            if (LNext(&list, &data))
                cout << data << " ";
        }
        cout << endl;
    }

    // find multiple of 2 and delete all /////
    nodeNum = LCount(&list);

    if (nodeNum != 0)
    {
        LFirst(&list, &data);
        if (data%2 == 0)
        {
            LRemove(&list);
        }

        for (i = 0; i < LCount(&list) - 1; i++)
        {
            LNext(&list, &data);
            if (data % 2 == 0)
            {
                LRemove(&list);
            }
        }
    }

    // Output once overall data /////
    if (LFirst(&list, &data))
    {
        cout << data << " ";

        for (i = 0; i < LCount(&list) - 1; i++)
        {
            if (LNext(&list, &data))
                cout << data << " ";
        }
        cout << endl;
    }
}