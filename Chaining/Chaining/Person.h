#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN	50

struct Person
{
	int ssn;
	char name[STR_LEN];
	char addr[STR_LEN];
};

int GetSSN(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, const char* name, const char* addr);

#endif