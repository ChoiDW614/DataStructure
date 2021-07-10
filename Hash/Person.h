#ifndef HASH_PERSON_H
#define HASH_PERSON_H

constexpr int STR_LEN = 50;

typedef class person
{
public:
    int ssn;                    // Resident Registration Number
    char name[STR_LEN];         // Name
    char addr[STR_LEN];         // Address
}Person;

int GETSSN(Person * p);
void ShowPerInfo(Person * p);
Person  * MakePersonData(int ssn, const char * name, char * addr);

#endif //HASH_PERSON_H