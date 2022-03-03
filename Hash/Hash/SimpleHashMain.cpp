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
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20120012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20170049, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 20120003);
	if (sp != nullptr)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20120012);
	if (sp != nullptr)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20170049);
	if (sp != nullptr)
		ShowPerInfo(sp);
	
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != nullptr)
		delete rp;

	rp = TBLDelete(&myTbl, 20120012);
	if (rp != nullptr)
		delete rp;

	rp = TBLDelete(&myTbl, 20170049);
	if (rp != nullptr)
		delete rp;
	
	return 0;
}