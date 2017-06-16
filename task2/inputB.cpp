#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string readProgramFromFile(string filename);


string readProgramFromFile(string filename)
{
	string programText = "";
	//input stream for data
	ifstream inFile;

	//open file
	inFile.open(filename);

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

	return programText;
}