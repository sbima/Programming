#include "A4a.h"

/*
* Entry point
*/
int main()
{
	Student *allStudentsPointer;
	int totalStudents = 0;
	allStudentsPointer = readStudentsFromFile(totalStudents);

	menu(allStudentsPointer, totalStudents);

	if( allStudentsPointer == NULL )
	{
		return 0;
	}

	return 0;
}

/*
* Responsible for reading students records from students.txt into students array of structs
* 
*
* @param totalStudents: reference variable which post execution, contains size of students
* @param return: pointer pointing to the array of structs containing students' data
*/
Student* readStudentsFromFile(int &totalStudents)
{
	Student *allStudentsPointer;
	//input stream for students data
	ifstream allStudentsInFile;

	//open students file
	allStudentsInFile.open("students.txt");

	//error handling in case file does not exist - start
	if( !allStudentsInFile )
	{
		cout << "Error opening students.txt" << endl;
		return NULL;
	}
	//error handling in case file does not exist - end
	cout << "Success opening students.txt" << endl;
	allStudentsInFile >> totalStudents;
	allStudentsPointer = new Student[totalStudents];

	cout << "totalStudents: " << totalStudents << endl;
	for(int i = 0; i < totalStudents; i++)
	{
		allStudentsInFile >> allStudentsPointer[i].firstname;
		allStudentsInFile >> allStudentsPointer[i].lastname;
		allStudentsInFile >> allStudentsPointer[i].uin;
		allStudentsInFile >> allStudentsPointer[i].major;
		allStudentsInFile >> allStudentsPointer[i].gpa;
		allStudentsInFile >> allStudentsPointer[i].graduationStatus;

		//graduationDate only exists when graduationStatus = 'Y'
		if( allStudentsPointer[i].graduationStatus == 'Y' )
		{
			char delimiter;
			allStudentsInFile >> allStudentsPointer[i].graduationDate.month;
			allStudentsInFile >> delimiter;
			allStudentsInFile >> allStudentsPointer[i].graduationDate.day;
			allStudentsInFile >> delimiter;
			allStudentsInFile >> allStudentsPointer[i].graduationDate.year;
		}
	}
	allStudentsInFile.close();

	return allStudentsPointer;
}

/*
* Responsible for printing menu and handling user selection
* 
*
* @param students: pointer pointing to the array of structs containing students' data
* @param totalStudents: size of students
*/
void menu(Student *students, int totalStudents)
{
	int input;
	cout << endl;
	cout << "Press 0 to print all students" <<endl;
	cout << "Press 1 to print only students who graduated" << endl;
	cout << "Press 2 to print only students with gpa >= value" << endl;
	cout << "Press 3 to print only students of a given major" << endl;
	cout << endl;
	cout << "Press 4 to sort students based on graduation date" << endl;
	cout << "Press 5 to sort students based on gpa" << endl;
	cout << "Press 6 to exit: ";

	while( true )
	{
		cin >> input;
		if( input == 0 )
		{
			printStudents(students, totalStudents);
		}
		else if( input == 1 )
		{
			//graduated students
			printStudents(students, totalStudents, 'Y');
		}
		else if( input == 2 )
		{
			float gpaThreshold;
			cout << "Enter gpa filter value: ";
			cin >> gpaThreshold;
			//gpa filter
			printStudents(students, totalStudents, 'N', gpaThreshold);
		}
		else if( input == 3 )
		{
			//major filter
			string majorFilter;
			cout << "Enter major filter value: ";
			cin >> majorFilter;
			
			printStudents(students, totalStudents, 'N', -1, majorFilter);
		}
		else if( input == 4 )
		{
			//graduation date sort
			students = sortStudents(students, totalStudents, "graduationDate");
			printStudents(students, totalStudents, 'N', -1, "");
		}
		else if( input == 5 )
		{
			//gpa sort
			students = sortStudents(students, totalStudents, "gpa");
			printStudents(students, totalStudents, 'N', -1, "");
		}
		else
		{
			exit(0);
		}
	}
}

/*
* Responsible for printing the students array of structs
* 
*
* @param students: pointer pointing to the array of structs containing students' data
* @param totalStudents: size of students
* @param graduationStatusFlag: flag to activate print for students who have graduated
* @param gpaThreshold: flag to activate print for students with gpa > gpaThreshold
* @param majorFilter: variable to activate print for students with major, majorFilter
*/
void printStudents(Student *students, int totalStudents, char graduationStatusFlag, float gpaThreshold, string majorFilter)
{
	if( students == NULL || totalStudents < 1 )
	{
		return;
	}

	printHorizontalLine(80, '*');
	printHorizontalLine(80, '*');
	for(int i = 0; i < totalStudents; i++)
	{

		// filter - start

		if( graduationStatusFlag == 'Y' )
		{
			// skip students who haven't graduated
			if( students[i].graduationStatus == 'N' )
			{
				continue;
			}
		}
		else if( gpaThreshold != -1 )
		{
			// skip students with gpa < gpaThreshold
			if( students[i].gpa < gpaThreshold )
			{
				continue;
			}
		}
		else if( majorFilter.length() != 0 )
		{
			// skip students with major != majorFilter
			if( students[i].major != majorFilter )
			{
				continue;
			}
		}



		// filter - end

		cout.clear();
		cout.fill(' ');

		cout << left << setw(3)
		<< i
		<< left << setw(10)
		<< students[i].firstname
		<< left << setw(10)
		<< students[i].lastname
		
		<< left << setw(15)
		<< students[i].uin
		<< left << setw(10)
		<< students[i].major

		<< setw(10)
		<< fixed
		<< setprecision(2)
		<< showpoint

		<< students[i].gpa
		<< left
		<< setw(5)
		<< students[i].graduationStatus;

		if( students[i].graduationStatus == 'Y' )
		{
			cout
			<< right <<setw(2) << setfill('0')
			<< students[i].graduationDate.month
			<< ":"
			<< right <<setw(2) << setfill('0')
			<< students[i].graduationDate.day
			<< ":"
			<< right <<setw(2) << setfill('0')
			<< students[i].graduationDate.year;
		}

		cout << endl;
	}
	printHorizontalLine(80, '*');
	printHorizontalLine(80, '*');
	cout << endl;
	cout << "Press 0 to print all students" <<endl;
	cout << "Press 1 to print only students who graduated" << endl;
	cout << "Press 2 to print only students with gpa >= value" << endl;
	cout << "Press 3 to print only students of a given major" << endl;
	cout << endl;
	cout << "Press 4 to sort students based on graduation date" << endl;
	cout << "Press 5 to sort students based on gpa" << endl;
	cout << "Press 6 to exit: ";
}

/*
* Responsible for printing a horizontal line which consists of border_char characters
* 
*
* @param width: count of border_char
* @param border_char: width made out of characters
*/
void printHorizontalLine( int width, char border_char )
{
    cout.fill( border_char );
    cout << setw( width ) << border_char << "\n";
    cout.fill(' ');
}

/*
* Responsible for sorting students based on graduationDate or gpa
* 
*
* @param students: pointer pointing to the array of structs containing Students items
* @param sizeOfStudents: size of students
* @param criteria: graduationDate or gpa
* @return: returns sorted students
*/
Student* sortStudents(Student* students, int sizeOfStudents, string criteria)
{
	if( sizeOfStudents < 1 )
	{
		return NULL;
	}
	
	for(int i = 0; i<sizeOfStudents; i++)
	{
		for(int j = i+1; j<sizeOfStudents; j++)
		{
			//if j's date is before i's date swap
			bool shouldSwapFlag = false;
			if( criteria == "graduationDate" )
			{
				if( students[j].graduationDate.isArgumentDateBefore(students[i].graduationDate) )
				{
					shouldSwapFlag = true;
				}
			}
			else if( criteria == "gpa" )
			{
				if( students[i].gpa < students[j].gpa )
				{
					shouldSwapFlag = true;
				}
			}
			
			//swap j's position with i - start		
			if( shouldSwapFlag )
			{
				Student student
				(
					students[i].firstname,
					students[i].lastname, 
					students[i].uin, 
					students[i].major, 
					students[i].gpa, 
					students[i].graduationStatus,
					students[i].graduationDate
				);
				
				students[i].firstname = students[j].firstname;
				students[i].lastname = students[j].lastname;
				students[i].uin = students[j].uin;
				students[i].major = students[j].major;
				students[i].gpa = students[j].gpa;
				students[i].graduationStatus = students[j].graduationStatus;
				students[i].graduationDate = students[j].graduationDate;

				students[j].firstname = student.firstname;
				students[j].lastname = student.lastname;
				students[j].uin = student.uin;
				students[j].major = student.major;
				students[j].gpa = student.gpa;
				students[j].graduationStatus = student.graduationStatus;
				students[j].graduationDate = student.graduationDate;
			}
			//swap j's position with i - end
		}
	}

	return students;
}
