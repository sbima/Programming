#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

int  n,k;
int  a[100];

vector<string> sixComb5;
vector<string> sixComb4;
vector<string> sixComb3;
vector<string> sixComb2;

/*
* Responsible for populating vectors with combinations
*/
void PrintIt()
{
	//*initialize state variables
	int i;
	string combination = "";
	//*if combinations token is 1 print *
	//*if combinations token is 0 print |
	//*append tokens to variable
	for (i=1; i <= n; i++)
	{
		if( a[i] == 1 )
		{
			combination = combination + "*";
		}
		else
		{
			combination = combination + "|";
		}
	}

	//*add respective combination tokens to vectors
	switch( k )
	{
		case 5:
			sixComb5.push_back(combination);
			break;
		case 4:
			sixComb4.push_back(combination);
			break;
		case 3:
			sixComb3.push_back(combination);
			break;
		case 2:
			sixComb2.push_back(combination);
			break;
	}
}

/*
* Recursive algorithm for generating combinations
*/
// credit to: http://theory.cs.uvic.ca/inf/comb/CombinationsInfo.html - start
void Comb(int j, int m)
{
	if (j > n)
	{
		PrintIt();
	}
	else
	{
		if (k-m < n-j+1)
		{
			a[j] = 0;
			Comb(j+1, m);
		}
		if (m<k)
		{
			a[j] = 1;
			Comb(j+1, m+1);
		}
	}
}

/*
* Responsible for populating vectors with combinations
*/
void populateVectors()
{
	//*initialize combinations state variables
	n = 6;k = 5;
	//*generate combinations
	Comb(1, 0);

	//*repeat previous steps 3 more times
	n = 6;k = 4;
	Comb(1, 0);

	n = 6;k = 3;
	Comb(1, 0);

	n = 6;k = 2;
	Comb(1, 0);
}

/*
* Responsible managing the handling games
*/
int gameInstance(vector<string> sixCombN, int& missingCount)
{
	//*perform error checking
	//**perform error checking, exit function if any vector is empty
	if( sixCombN.size() == 0 )
	{
		return 0;
	}

	//* declare/initialize state variables
	int incorrectCount = 0;
	vector<int> randomIndices;
	string userInput;
	int i;

	//*generate random count of missing combinations
	//**generate random count between [0,|vector|/2] of missing combinations
	missingCount = rand() % (sixCombN.size()/2);
	if( missingCount == 0 )
	{
		missingCount = 2;
	}

	//*populate random indices
	//**populate random indices; ensure indices are unique
	//**populate random indices; ensure indices are unique and populate a vector with indices
	for(i = 0; i<missingCount; i++)
	{
		int randomIndex = rand() % sixCombN.size();
		while
		(
			find(randomIndices.begin(), randomIndices.end(), randomIndex) != randomIndices.end() ||
			(randomIndex == 0) ||
			(randomIndex == 1)
		)
		{
			randomIndex = rand() % sixCombN.size();
		}

		randomIndices.push_back(randomIndex);
	}

	//*begin game logic
	//**traverse all combinations
	//***traverse all combinations, skip combinations in random index list
	//****traverse all combinations, skip combinations in random index list, ask user to guess remaining sequence
	//*****If the user fails the guess, give a second try
	//**print combinations
	for(i = 0; i<sixCombN.size(); i++)
	{
		if( find(randomIndices.begin(), randomIndices.end(), i) != randomIndices.end() )
		{
			cout << endl;
			cout << "Enter next sequence: ";
			cin >> userInput;

			if( userInput != sixCombN[i] )
			{
				incorrectCount++;
				cout << "Try again, Enter next sequence: ";
				cin >> userInput;

				if( userInput != sixCombN[i] )
				{
					incorrectCount++;
					cout << "Incorrect count: " << incorrectCount << endl;
					cout << "\t" << sixCombN[i] << endl;
				}

			}
		}
		else
		{
			cout << "\t" << sixCombN[i] << endl;
		}
	}

	return incorrectCount;
}

/*
* Responsible for directing the games
*/
void playGame()
{
	//*perform error checking
	//**perform error checking, exit function if any vector is empty
	if
	(
		sixComb5.size() == 0 ||
		sixComb4.size() == 0 ||
		sixComb3.size() == 0 ||
		sixComb2.size() == 0
	)
	{
		return;
	}
	//*initialize state variables
	int missingCount = 0;
	int gameCount = 0;

	//*print notification to signal start of game
	cout << endl;
	cout<< "---------------------------- " << endl;
	cout << "********** Game 1 ********** " << endl;
	cout<< "---------------------------- " << endl;

	//*setup game
	//**create a game instance
	int incorrectCount = gameInstance(sixComb5, missingCount);
	gameCount++;

	//*check game outcome
	//**check the number of incorrect instances
	//***check the number of incorrect instances vs. blanks/2
	//*repeat previous steps for all remaining games
	if( incorrectCount > missingCount/2 )
	{
		cout << "Incorrect Count post game: " << incorrectCount << " of " << missingCount << endl;
		cout << "Game over, score: " << gameCount << "/" << 4 << endl;
		exit(0);
	}

	cout << endl;
	cout<< "---------------------------- " << endl;
	cout<< "********** Game 2 ********** " << endl;
	cout<< "---------------------------- " << endl;
	incorrectCount = gameInstance(sixComb4, missingCount);
	gameCount++;
	if( incorrectCount > missingCount/2 )
	{
		cout << "Incorrect Count post game: " << incorrectCount << " of " << missingCount << endl;
		cout << "Game over, score: " << gameCount << "/" << 4 << endl;
		exit(0);
	}

	cout << endl;
	cout<< "---------------------------- " << endl;
	cout<< "********** Game 3 ********** " << endl;
	cout<< "---------------------------- " << endl;
	incorrectCount = gameInstance(sixComb3, missingCount);
	gameCount++;
	if( incorrectCount > missingCount/2 )
	{
		cout << "Incorrect Count post game: " << incorrectCount << " of " << missingCount << endl;
		cout << "Game over, score: " << gameCount << "/" << 4 << endl;
		exit(0);
	}

	cout << endl;
	cout<< "---------------------------- " << endl;
	cout<< "********** Game 4 ********** " << endl;
	cout<< "---------------------------- " << endl;
	incorrectCount = gameInstance(sixComb2, missingCount);
	gameCount++;
	if( incorrectCount > missingCount/2 )
	{
		cout << "Incorrect Count post game: " << incorrectCount << " of " << missingCount << endl;
		cout << "Game over, score: " << gameCount << "/" << 4 << endl;
		exit(0);
	}

	cout << "Well done, score: 4/4" << endl;
}

int main()
{
	//*initialize state variables
	//**seed random number generator
	srand(time(NULL));
	//*setup game parameters
	//**initialize vector with combinations: 6 combination 2, 6 combination 3, 6 combinaiton 3, 6 combination 4
	populateVectors();
	//*play game
	playGame();

	return 0;
}



