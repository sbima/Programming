#include "Operator.h"

/*
* Responsible for initializing Operator members to safe state
*/
Operator::Operator()
{
	ID = "";
	firstName = "";
	lastName = "";
    role = 'X';
}

/*
* Responsible for reading operator data from file into array of Operator structs
* 
*
* @param fileName: input filename
* @param return: array of Operator structs
*/
Operator* Operator::readDataFile(string fileName, int &countOfOperatorsToRead)
{
	if( fileName.length() > 0 )
	{
		ifstream myfile;
		myfile.open(fileName.c_str());

		if( myfile.is_open() )
		{
			myfile >> countOfOperatorsToRead;
			if( countOfOperatorsToRead < 0 || countOfOperatorsToRead > 1000 )
			{
				return NULL;
			}

			Operator *operatorsData = new Operator[countOfOperatorsToRead];
			char colon;

			for(int i=0; i<countOfOperatorsToRead; i++)
			{
				myfile >> operatorsData[i].ID;
				myfile >> operatorsData[i].firstName;
				myfile >> operatorsData[i].lastName;

				myfile >> operatorsData[i].employmentDate.month;
				myfile >> colon;
				myfile >> operatorsData[i].employmentDate.day;
				myfile >> colon;
				myfile >> operatorsData[i].employmentDate.year;

				myfile >> operatorsData[i].role;
			}

			myfile.close();
			return operatorsData;
		}
		else
		{
			cout << "Unable to open file";
		}
	}

	return NULL;
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
	cout << "\t" << setw( width ) << border_char << "\n";
	cout.fill(' ');
}


/*
* Responsible for printing the operators array of structs
* 
*
* @param operators: pointer pointing to the array of structs containing operators' data
* @param totalOperators: size of operators
* @param roleFlag: flag to activate print for operators with the user-supplied role character
* @param employmentDateMonthFlag: flag to activate print for operators  with the user-supplied employment date month value
* @param employmentDateDayFlag: flag to activate print for operators  with the user-supplied employment date day value
* @param employmentDateYearFlag: flag to activate print for operators  with the user-supplied employment date year value
*/
void Operator::printOperators(Operator *operators, int totalOperators, char roleFlag, int employmentDateMonthFlag, int employmentDateDayFlag, int employmentDateYearFlag)
{
	if( operators == NULL || totalOperators < 1 )
	{
			return;
	}

	printHorizontalLine(55, '*');
	printHorizontalLine(55, '*');
	for(int i = 0; i < totalOperators; i++)
	{

		// filter - start

		// skip operators who don't have user-supplied role
	
		if( roleFlag != '*' )
		{
			if( operators[i].role != roleFlag )
			{
				continue;
			}
		}
		else if(employmentDateYearFlag != -1 )
		{
			// skip operators who don't have user-supplied employmentDate year
			if( operators[i].employmentDate.year != employmentDateYearFlag )
			{	
				continue;
			}	
		}
		else if( employmentDateMonthFlag != -1 )
		{
			// skip operators who don't have user-supplied employmentDate month
			if( operators[i].employmentDate.month != employmentDateMonthFlag )
			{
				continue;
			}
		}
		else if( employmentDateDayFlag != -1 )
		{
			// skip operators who don't have user-supplied employmentDate month
			if( operators[i].employmentDate.day != employmentDateDayFlag )
			{
				continue;
			}
		}
	
		// filter - end

		cout.clear();
		cout.fill(' ');

		cout << "\t"
		<< left << setw(3)
		<< i
		<< left << setw(15)
		<< operators[i].ID
		<< left << setw(10)
		<< operators[i].firstName
		<< left << setw(10)
		<< operators[i].lastName

		<< left
		<< setw(5)
		<< operators[i].role;

		cout
		<< right <<setw(2) << setfill('0')
		<< operators[i].employmentDate.month
		<< ":"
		<< right <<setw(2) << setfill('0')
		<< operators[i].employmentDate.day
		<< ":"
		<< right <<setw(2) << setfill('0')
		<< operators[i].employmentDate.year;
		

		cout << endl;
	}
	printHorizontalLine(55, '*');
	printHorizontalLine(55, '*');
}
