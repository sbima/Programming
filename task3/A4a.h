#ifndef _A4A_
#define _A4A_

#include <iostream> //for cout, cin
#include <iomanip> // for setw, fixed, setprecision() manipulators
#include <fstream> //for file input/output
#include <string.h> //for string types usage
#include <cstdlib>
using namespace std;

/*
Structure to store the date
*/
struct Date
{
	int month;
	int day;
	int year;

	//Constructor with default parameters to initialize of members to a safe state
	Date(int m = 999, int d = 999, int y = 999)
	{
		month = m;
		day = d;
		year = y;
	}

	bool isArgumentDateBefore(Date arg)
	{
		//case: 05:16:2000 vs 05:16:2001
		if( arg.year < year )
		{
			return true;
		}
		else if( arg.year > year )
		{
			return false;
		}

		//case: MM:DD:2000 vs MM:DD:2000
		if( arg.year == year )
		{
			//case: 04:DD:2000 vs 05:DD:2000
			if( arg.month < month )
			{
				return true;
			}
			else if( arg.month > month )
			{
				return false;
			}

			//case: 05:DD:2000 vs 05:DD:2000
			if( arg.month == month )
			{
				//case: 05:16:2000 vs 05:17:2000
				if( arg.day < day )
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		return false;
	}
};

/*
Structure to store students data
*/
struct Student
{
	string firstname;
	string lastname;
	string uin;
	string major;

	float gpa;
	char graduationStatus;
	Date graduationDate;

	//Default constructor to initialize of members to a safe state
	Student()
	{
		firstname = "";
		lastname = "";
		uin = "";
		major = "";
		gpa = 0;
		graduationStatus = ' ';
	}

	//Default constructor to initialize of members to a safe state
	Student(string firstname_, string lastname_, string uin_, string major_, float gpa_, char graduationStatus_, Date graduationDate_)
	{
		firstname = firstname_;
		lastname = lastname_;
		uin = uin_;
		major = major_;
		gpa = gpa_;
		graduationStatus = graduationStatus_;
		graduationDate = Date(graduationDate_.month, graduationDate_.day, graduationDate_.year);
	}
};

Student* readStudentsFromFile(int &totalStudents);
void menu(Student *students, int totalStudents);
void printHorizontalLine( int width, char border_char );
void printStudents(Student *students, int totalStudents, char graduationStatusFlag = 'N', float gpaThreshold = -1, string majorFilter = "");
Student* sortStudents(Student* students, int sizeOfStudents, string criteria);

#endif