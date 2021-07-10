#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Slot.h"

constexpr int MAX_TBL = 100;

typedef int (*HashFunc)(Key k);

typedef class table
{
public:
    Slot tbl[MAX_TBL];
    HashFunc * hf;
}Table;

// Initialize the table
void TBLInit(Table * pt, HashFunc * f);

// Save the key and value in table
void TBLInsert(Table * pt, Key k, Value v);

// Delete data from table based on key
Value TBLDelete(Table * pt, Key k);

// Search data from table based on key
Value TBLSearch(Table * pt, Key k);

#endif //HASH_TABLE_H