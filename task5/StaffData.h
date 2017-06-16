
#ifndef _StaffData_INCLUDED_   //   if header.h hasn't been included yet,
#define _StaffData_INCLUDED_   //   #define means - the compiler knows it has already been included

#include <string>
using namespace std;

struct Date
{   
    int month;
    int day;
    int year;

    Date()
    {
        month = 999;
        day = 999;
        year = 999;
    }

    Date(int mm, int dd, int yyyy)
    {
        month = mm;
        day = dd;
        year = yyyy;
    }
};

struct StaffData
{
    int ID;

    string firstName;
    string lastName;
    
    int totalWorkHours;
    int totalOvertimeWorkHours;

    string supervisorFirstName;
    string supervisorLastName;

    Date employmentDate;

    StaffData()
    {
    	ID = 0;

    	firstName = "";
    	lastName = "";

    	totalWorkHours = 0;
        totalOvertimeWorkHours = 0;

        supervisorFirstName = "";
        supervisorLastName = "";
    }
};

#endif
