#include <iostream>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPerInfo(Person* p)
{
	std::cout << "resident registration number: " << p->ssn << std::endl;
	std::cout << "name: " << p->name << std::endl;
	std::cout << "address: " << p->addr << std::endl;
}

Person* MakePersonData(int ssn, const char* name, const char* addr)
{
	Person* newP = new Person;
	newP->ssn = ssn;
	strncpy_s(newP->name, name, sizeof(name));
	strncpy_s(newP->addr, addr, sizeof(addr)*2);
	return newP;
}