#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "LevenshteinDistance.h"
#include "StringOperations.h"

string readProgramFromFile(string filename);

/*
* Entry point
*/
int main()
{
	string programA = "";
	string programB = "";

	programA = readProgramFromFile("inputA.cpp");
	programB = readProgramFromFile("inputB.cpp");

	if( programA.length() == 0 || programB.length() == 0 )
	{
		cout << "programA or programB invalid, exiting.";
		return 0;
	}

	cout << endl << endl;
	//cout << "programA:" << endl;
	//cout << programA << endl;
	//cout << endl;
	programA = getOpenClosingBracesFromString(programA);
	cout << "programA(Braces): " << programA << endl;
	programA = getBinaryString(programA);
	cout << "programA(BitString): " << programA << endl;

	//cout << "programB:" << endl;
	//cout << programB << endl;
	//cout << endl;
	programB = getOpenClosingBracesFromString(programB);
	cout << "programB(Braces): " << programB << endl;
	programB = getBinaryString(programB);
	cout << "programB(BitString): " << programB << endl;

	int largerLength = programA.length();
	if( programB.length() > largerLength )
	{
		largerLength = programB.length();
	}
	int distance = uiLevenshteinDistance(programA, programB);

	float similarity = 1 - ( distance/float(largerLength) );
	similarity = similarity * 100;

	cout << endl;
	cout << "similarity measure: " << similarity << "\%" << endl;

	if( similarity > 50 )
	{
		cout << "PLAGIARISM" << endl;
	}
	else
	{
		cout << "NO PLAGIARISM" << endl;
	}

	return 0;
}

/*
* Responsible for reading program text from file
* 
* @param filename: name of program file
* @param return: c++ program string
*/
string readProgramFromFile(string filename)
{
	string programText = "";
	//input stream for data
	ifstream inFile;

	//open file
	inFile.open(filename.c_str());

	//error handling in case file does not exist was unable to open - start
	if (!inFile)
		{
				cout << "The inventory input file " << filename << " does not exist." << endl;
				return "";
		}
	//error handling in case file does not exist was unable to open - end
	cout << "Success opening " << filename <<endl;
	//read inventory from file - start
	
	string line;
	while( !inFile.eof() )
	{
		getline (inFile, line);
		programText = programText + line;
	}
	inFile.close();

	return programText;
}