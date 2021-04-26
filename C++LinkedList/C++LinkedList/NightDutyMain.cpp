#include <iostream>
#include <string>
#include "CLinkedList.h"
#include "EmployeeInformation.h"

Employee * WhosNightDuty(List * plist, string name, int day);
void ShowEmployInfo(Employee * pemp);

int main()
{
    using namespace std;

    // create and initialize a circle linkedlist /////
    int i;
    Employee * pemp;
    List list;
    ListInit(&list);

    // save 5 data to list /////
    pemp = new Employee;
    pemp->employeeNumber = 11111;
    pemp->nameOfEmployee = "john";
    LInsert(&list, pemp);

    pemp = new Employee;
    pemp->employeeNumber = 22222;
    pemp->nameOfEmployee = "jery";
    LInsert(&list, pemp);

    pemp = new Employee;
    pemp->employeeNumber = 33333;
    pemp->nameOfEmployee = "terry";
    LInsert(&list, pemp);

    pemp = new Employee;
    pemp->employeeNumber = 44444;
    pemp->nameOfEmployee = "hary";
    LInsert(&list, pemp);

    // Three days after Terry, who's on duty? /////
    pemp = WhosNightDuty(&list, "terry", 3);
    ShowEmployInfo(pemp);

    // fifteen days after hary, who's on duty? /////
    pemp = WhosNightDuty(&list, "hary", 15);
    ShowEmployInfo(pemp);

    // delete all data /////
    if (LFirst(&list, &pemp))
    {
        delete pemp;

        for (i = 0; i < LCount(&list) - 1; i++)
        {
            if(LNext(&list, &pemp))
                delete pemp;
        }
    }

    return 0;
}

Employee * WhosNightDuty(List * plist, string name, int day)
{
    int i, num;
    Employee * ret;

    num = LCount(plist);

    LFirst(plist, &ret);

    for (i = 0; i < num - 1; i++)
    {
        LNext(plist, &ret);
        
        if(ret->nameOfEmployee == name)
            break;
    }

    if (i >= num - 1)
        return NULL;

    for (i = 0; i < day; i++)
        LNext(plist, &ret);

    return ret;
}

void ShowEmployInfo(Employee * pemp)
{
    cout << "Employee name : " << pemp->nameOfEmployee << endl;
    cout << "Employee number : " << pemp->employeeNumber << endl;
}