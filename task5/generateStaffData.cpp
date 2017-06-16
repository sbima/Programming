#include "generateStaffData.h"

/*
* Responsible for checking if an integer entry is inside an integer array
* 
*
* @param numbersArray: array of numbers
* @param sizeOfArray: size of numbersArray
* @param return: true if key is inside numbersArray, false otherwise
*/
bool isInside(int numbersArray[], int sizeOfArray, int key)
{
	for(int i = 0; i<sizeOfArray; i++)
	{
		if( numbersArray[i] == key )
		{
			return true;
		}
	}
	return false;
}

/*
* Responsible for generating n unique random numbers between minRange and maxRange
* 
*
* @param minRange: minimum range of random numbers
* @param maxRange: maximum range of random numbers
* @param count: the number of unique random numbers to generate
* @param return: integer pointer to array of count unique random numbers
*/
int* getNUniqueRandomNumbers(int minRange, int maxRange, int count)
{
	if( minRange > 0 && maxRange > 0 && count > 0 && count <= (maxRange - minRange + 1) )
	{
		int *arrayOfUniqueRandInts = new int[count];
		
        if( minRange == maxRange )
        {
            arrayOfUniqueRandInts[0] = minRange;
        }
        else
        {
            int uniqueCount = 0;
            while( uniqueCount < count )
            {
                //get a randomNumber between minRange and maxRange
                int randomNumber = minRange + rand() % (maxRange - minRange + 1);
                //if randomNumber is not already inside array add to array
                if( isInside(arrayOfUniqueRandInts, uniqueCount+1, randomNumber) == 0 )
                {
                    arrayOfUniqueRandInts[uniqueCount] = randomNumber;
                    //cout << uniqueCount << ". " << randomNumber << endl;
                    uniqueCount++;
                }
            }
        }
		return arrayOfUniqueRandInts;
	}
	return NULL;
}

/*
* Responsible for generating a random string of length between minStringLength and maxStringLength
* 
*
* @param minStringLength: minimum length of string to be generated
* @param maxStringLength: maximum length of string to be generated
* @param minRange: minimum ascii range, default 65 (A)
* @param maxRange: maximum ascii range, default 90 (Z)
* @param return: a random string
*/
string getRandomString(int minStringLength, int maxStringLength, int minRange = 65, int maxRange = 90)
{
	string randomString = "";
	if( minStringLength > 0 && maxStringLength > 0 && minRange < maxRange )
	{
		//randomize string length
		int *arrayOfUniqueRandInts = getNUniqueRandomNumbers(minStringLength, maxStringLength, 1);

		if( arrayOfUniqueRandInts != NULL )
        {
            int lengthOfString = arrayOfUniqueRandInts[0];

            for(int i=0; i<lengthOfString; i++)
            {
                int randomNumber = minRange + rand() % (maxRange - minRange + 1);
                randomString = randomString + char(randomNumber);
            }
        }
        else
        {
            cout << "arrayOfUniqueRandInts is NULL" <<endl;
        }

	}

	return randomString;
}

/*
* Responsible for generating structs representing staff
* 
*
* @param staffCount: the number of staff data to generate
* @param return: a pointer pointing to the array of StaffData structs
*/
StaffData* generateStaffData(int staffCount)
{
	//staffData.txt format - start
	/*
		<
			<[5-DIGIT ID], firstName, lastName, totalWorkHours, totalOvertimeWorkHours, supervisorFirstName, supervisorLastName, employmentDate - MM:DD:YYYY>,
			<...>
			 ...
	    >
	*/
	//staffData.txt format - end
	if( staffCount > 0 )
	{
		StaffData *staffData = new StaffData[staffCount];
		//get unique 5
		int *arrayOfUniqueRandInts = getNUniqueRandomNumbers(10000, 20000, staffCount);
		
		string firstName = "";
		string lastName = "";

		for(int i = 0; i<staffCount; i++)
		{
			firstName = getRandomString(6, 20);
			lastName = getRandomString(7, 25);

			StaffData staffInstance;

		    staffInstance.ID = arrayOfUniqueRandInts[i];
		    staffInstance.firstName = firstName;
		    staffInstance.lastName = lastName;

		    // generate supervisor names - start
		    if( arrayOfUniqueRandInts[i] % 2 == 0 )
		    {
		    	staffInstance.supervisorFirstName = "Alexandre";
		    	staffInstance.supervisorLastName = "Desplat";
		    }
		    else
		    {
		    	staffInstance.supervisorFirstName = "Bruno";
		    	staffInstance.supervisorLastName = "Coulais";
		    }
		    // generate supervisor names - end

		    // generate totalWorkHours/totalOvertimeWorkHours - start
		    staffInstance.totalWorkHours = (rand() % 200000) + 1;
		    staffInstance.totalOvertimeWorkHours = (rand() % 20000) + 1;
		    // generate totalWorkHours/totalOvertimeWorkHours - end

		    // generate employmentDate between 01:01:1990 and 01:01:2015 - start

		    // random month
		    staffInstance.employmentDate.month = (rand() % 12) + 1;

		    // random day between 1 and 28
		    staffInstance.employmentDate.day = (rand() % 28) + 1;

		    // random year between 1990 and 2015
		    staffInstance.employmentDate.year = (rand() % 26) + 1990;

		    // generate employmentDate between 01:01:1990 and 01:01:2015 - end

		    staffData[i] = staffInstance;
		}

		return staffData;

	}

	return NULL;

}

/*
* Responsible for writing staff data to file
* 
*
* @param fileName: output filename
* @param staffDataArray: array of StaffData structs
* @param lengthOfArray: size of staffDataArray
*/
void writeToFile(string fileName, StaffData staffDataArray[], int lengthOfArray)
{
	if( fileName.length() > 0 && staffDataArray != NULL && lengthOfArray > 0 )
	{

		ofstream outputFile;
		outputFile.open(fileName.c_str());

		for(int i=0; i<lengthOfArray; i++)
		{
			//MOD
			cout 
		    << staffDataArray[i].ID << ", " 
		    << staffDataArray[i].firstName << ", " 
		    << staffDataArray[i].lastName << ", " 
		    << staffDataArray[i].totalWorkHours << ", " 
		    << staffDataArray[i].totalOvertimeWorkHours << ", " 
		    << staffDataArray[i].supervisorFirstName << ", "
		    << staffDataArray[i].supervisorLastName << ", "

		    << staffDataArray[i].employmentDate.month << ":" 
		    << staffDataArray[i].employmentDate.day << ":" 
		    << staffDataArray[i].employmentDate.year << endl;

		    outputFile 
		    << staffDataArray[i].ID << " " 
		    << staffDataArray[i].firstName << " " 
		    << staffDataArray[i].lastName << " " 
		    << staffDataArray[i].totalWorkHours << " " 
		    << staffDataArray[i].totalOvertimeWorkHours << " " 
		    << staffDataArray[i].supervisorFirstName << " "
		    << staffDataArray[i].supervisorLastName << " "

		    << staffDataArray[i].employmentDate.month << ":" 
		    << staffDataArray[i].employmentDate.day << ":" 
		    << staffDataArray[i].employmentDate.year << endl;
		}

		outputFile.close();
	}
}


/*
	Entry point
*/
int main()
{
	//initialize random seed
	srand (time(NULL));

	int staffCount = 1000;

	//write data to file
	//Part A - start
	cout << "Generating data file" << endl;
	StaffData *staffData = generateStaffData(staffCount);

	//Part A - end
	if( staffData != NULL )
	{
		writeToFile("staffData.txt", staffData, staffCount);
	}

	return 0;
}
