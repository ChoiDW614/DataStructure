#include <iostream>
#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return (idx*2)+1;
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData)
        return (GetLChildIDX(idx));
    else
    {
        if(ph->heapArr[GetLChildIDX(idx)].pr < ph->heapArr[GetRChildIDX(idx)].pr)
            return GetLChildIDX(idx);
        else
            return GetRChildIDX(idx);
    }
}

void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = (++ph->numOfData);

    HeapElem elem = {pr, data};
    ph->heapArr[idx] = elem;

    while(idx != 1)
    {
        if(ph->heapArr[GetParentIDX(idx)].pr > pr)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = elem;
}

HData HDelete(Heap * ph)
{
    HData tmpData = ph->heapArr[1].data;

    ph->heapArr[1] = ph->heapArr[ph->numOfData];
    int i = 1;
    while(ph->heapArr[GetLChildIDX(i)].data != NULL && ph->heapArr[GetRChildIDX(i)].data != NULL)
    {



    }

    return tmpData;
}