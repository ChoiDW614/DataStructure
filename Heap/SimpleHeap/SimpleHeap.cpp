#include <iostream>
#include "SimpleHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = &pc;
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
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]))
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap * ph, HData data)
{
    int idx = (++ph->numOfData);

    while(idx != 1)
    {
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = data;
}

HData HDelete(Heap * ph)
{
    HData tmpData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIDX = 1;
    int childIDX;

    while(childIDX = GetHiPriChildIDX(ph, parentIDX))
    {
        if(ph->comp(lastElem, ph->heapArr[childIDX]) >= 0)
            break;

        ph->heapArr[parentIDX] = ph->heapArr[childIDX];
        parentIDX = childIDX;
    }

    ph->heapArr[parentIDX] = lastElem;
    ph->numOfData -= 1;
    return tmpData;
}