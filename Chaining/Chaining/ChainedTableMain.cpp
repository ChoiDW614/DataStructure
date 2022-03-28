#include <iostream>
#include <cstdlib>
#include "Person.h"
#include "Table2.h"

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

	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900139, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900827, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 900254);
	if (sp != nullptr)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900139);
	if (sp != nullptr)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900827);
	if (sp != nullptr)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTbl, 900254);
	if (rp != nullptr)
		delete rp;

	rp = TBLDelete(&myTbl, 900139);
	if (rp != nullptr)
		delete rp;

	rp = TBLDelete(&myTbl, 900827);
	if (rp != nullptr)
		delete rp;

	return 0;
}