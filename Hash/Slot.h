#ifndef HASH_SLOT_H
#define HASH_SLOT_H

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus{EMPTY, DELETED, INUSE};

typedef class slot
{
public:
    Key key;
    Value val;
    enum SlotStatus status;
}Slot;

#endif //HASH_SLOT_H