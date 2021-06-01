#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

constexpr int TRUE      =   1;
constexpr int FALSE     =   0;

constexpr int HEAP_LEN  =   100;

typedef char HData;
typedef int Priority;

typedef class heapElem
{
public:
    Priority pr;
    HData data;
}HeapElem;

typedef class heap
{
public:
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);

#endif //__SIMPLE_HEAP_H__
