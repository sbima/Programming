
#ifndef _StaffData_INCLUDED_   //   if StudentsData.h hasn't been included yet,
#define _StaffData_INCLUDED_   //   #define means - the compiler knows it has already been included

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

struct Date
{
    int month;
    int day;
    int year;

    Date()
    {
        month = 0;
        day = 0;
        year = 0;
    }

    Date(int mm, int dd, int yyyy)
    {
        month = mm;
        day = dd;
        year = yyyy;
    }
};

class Operator
{
    private:
        string ID;
        string firstName;
        string lastName;
        Date employmentDate;
        char role;

    public:
        Operator();
        void printOperators(Operator *operators, int totalOperators, char roleFlag, int employmentDateYearFlag, int employmentDateMonthFlag, int employmentDateDayFlag);
        Operator* readDataFile(string fileName, int &countOfOperatorsToRead);
};

#endif
