#include <iostream>
#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
    for(int i = 0; i < MAX_TBL; i++)
    {
        (pt->tbl[i]).status = EMPTY;
    }

    pt->hf = f;         // Register hash function
}

void TBLInsert(Table * pt, Key k, Value v)
{
    int hv = pt->hf(k);
    pt->tbl[hv].val = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table * pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return nullptr;
    else
    {
        (pt->tbl[hv]).status = DELETED;
        return (pt->tbl[hv]).val;           // return the value that will be deleted
    }
}

Value TBLSearch(Table * pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return nullptr;
    else
    {
        return (pt->tbl[hv]).val;           // return the searched value
    }
}