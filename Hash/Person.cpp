#include <iostream>
#include <cstring>
#include "Person.h"

int GETSSN(Person * p)
{
    return p->ssn;
}

void ShowPerInfo(Person * p)
{
    std::cout << "Resident Registration Number : " << p->ssn << std::endl;
    std::cout << "Name : " << p->name << std::endl;
    std::cout << "Address : " << p->addr << std::endl;
}

Person  * MakePersonData(int ssn, const char * name, const char * addr)
{
    Person *newP;
    newP = new Person;
    newP->ssn = ssn;
    strcpy(newP->name, name);
    strcpy(newP->addr, addr);
    return newP;
}