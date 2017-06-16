#ifndef _generateStaffData_INCLUDED_
#define _generateStaffData_INCLUDED_

#include <iostream> 	//for cout, cin
#include <string>		//for string
#include <fstream>		//for reading/writing from/to file
#include <stdlib.h>		//for rand
#include <time.h>		//for time
#include "StaffData.h"
using namespace std;

bool isInside(int[], int, int);
int* getNUniqueRandomNumbers(int, int, int);
string getRandomString(int, int, int, int);
StaffData* generateStaffData(int, int, string);
string* readFromFileIntoStringArray(string, int);

#endif 