#include <iostream>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    TBLInit(&myTbl, MyHashFunc);

    // input data
    np = MakePersonData(20120003, "Lee", "Seoul");
    TBLInsert(&myTbl, GETSSN(np), np);

    np = MakePersonData(20120012, "Kim", "Jeju");
    TBLInsert(&myTbl, GETSSN(np), np);

    np = MakePersonData(20120049, "Han", "Kangwon");
    TBLInsert(&myTbl, GETSSN(np), np);

    // search data
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != nullptr)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 20120012);
    if(sp != nullptr)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 20120049);
    if(sp != nullptr)
        ShowPerInfo(sp);

    // delete data
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != nullptr)
        delete rp;

    rp = TBLDelete(&myTbl, 20120012);
    if(rp != nullptr)
        delete rp;

    rp = TBLDelete(&myTbl, 20120049);
    if(rp != nullptr)
        delete rp;

    return 0;
}

