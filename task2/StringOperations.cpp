#include "StringOperations.h"

/*
* Responsible for converting "{" and "}" to bitstring 0 and 1 respectively
* 
* @param wellFormedString: string consisting of "{" and "}"
* @param return: bistring due to processing wellFormedString
*/
string getBinaryString(string wellFormedString)
{
	string bitString = "";

	for(int i = 0; i<wellFormedString.length(); i++)
	{
		if( wellFormedString[i] == '{' )
		{
			bitString = bitString + '0';
		}
		else if( wellFormedString[i] == '}' )
		{
			bitString = bitString + '1';
		}
	}

	return bitString;
}

/*
* Responsible for removing all text excluding "{" and "}" from plaintext program
* 
* @param programStr: c++ program text
* @param return: c++ program string stripped of all characters excluding "{" and "}"
*/ 
string getOpenClosingBracesFromString(string programStr)
{
	string wellFormedString = "";

	for(int i = 0; i<programStr.length(); i++)
	{
		if( programStr[i] == '{' || programStr[i] == '}' )
		{
			wellFormedString = wellFormedString + programStr[i];
		}
	}

	return wellFormedString;
}