#include <iostream>
#include <stdlib.h>
#include "Operator.h"
#include "CuboidalTank.h"
#include "CylindricalTank.h"
#include "HexagonalPrismTank.h"
using namespace std;

/*
* Responsible for performing tank related operations
*
*
* @param tank: Cuboidal, Cylindrical, or Hexagonal Prism tank
*/
template<typename TankType>
void tankOperations(TankType tank)
{
	int choice;
	while( true )
	{
		cout << endl;
		cout << "\t\tPress 1 to get max possible volume" << endl;
		cout << "\t\tPress 2 to get current volume" << endl;
		cout << "\t\tPress 3 to supply oil" << endl;
		cout << "\t\tPress 4 to get amt to completely fill tank" << endl;
		cout << "\t\tPress 5 to get amt to partially fill tank" << endl;
		cout << "\t\tPress 6 to exit: ";
		cin >> choice;

		switch( choice )
		{
			case 1:
				cout << endl;
				cout << "\t\tMax possible volume: " << tank.getMaxPossibleVolume() << endl;
				break;
			case 2:
				cout << endl;
				cout << "\t\tCurrent volume: " << tank.getCurrentVolume() << endl;
				break;
			case 3:
				cout << endl;
				float oilAmt;
				cout << "\t\tEnter oil amt (height): ";
				cin >> oilAmt;
				tank.supplyOil(oilAmt);
				break;
			case 4:
				cout << endl;
				cout << "\t\tAmt to completely fill tank: " << tank.getAmtToCompletelyFillTank() << endl;
				break;
			case 5:
				cout << endl;
				cout << "\t\tCurrent height: " << tank.getLiquidHeight() << endl;
				cout << "\t\tMaximum height: " << tank.getMaxLiquidHeight() << endl;
				cout << "\t\tEnter proposed new height: ";
				cin >> oilAmt;
				cout << "\t\tAmt to partially fill tank: " << tank.getAmtToPartiallyFillTank(oilAmt) << endl;
				break;
			default:
				return;
		}
	}
}

/*
* Responsible for handling the Operator menu
*
*
* @param operators: array of Operator structs
* @param sizeOfOperators: size of operators
*/
void operatorMenu(Operator *operators, int sizeOfOperators)
{
	if( operators == NULL || sizeOfOperators < 1 )
	{
		return;
	}
	cout << "\tWelcome Operator!" << endl;

	int choice;
	CuboidalTank tank0;
	CylindricalTank tank1;
	HexagonalPrismTank tank2;

	while( true )
	{
		cout << endl;
		cout << "\tPress 1 to select Cuboidal Tank" << endl;
		cout << "\tPress 2 to select Cylindrical Tank" << endl;
		cout << "\tPress 3 to select Regular Right Hexagonal Prism Tank" << endl;
		cout << "\tPress 4 to exit: ";
		cin >> choice;

		switch( choice )
		{
			cout << endl;
			case 1:
				cout << "\t\tCuboidalTank" << endl;
				tankOperations(tank0);
				break;
			case 2:
				cout << "\t\tCylindricalTank" << endl;
				tankOperations(tank1);
				break;
			case 3:
				cout << "\t\tHexagonalPrismTank" << endl;
				tankOperations(tank2);
				break;
			default:
				return;
		}
	}
}


/*
* Responsible for handling the Manager menu
*
*
* @param operators: array of Operator structs
* @param sizeOfOperators: size of operators
*/
void managerMenu(Operator *operators, int sizeOfOperators)
{
	if( operators == NULL || sizeOfOperators < 1 )
	{
		return;
	}
	int choice;

	cout << "\tWelcome Manager!" << endl;
	while( true )
	{
		cout << endl;
		cout << "\tPress 1 to print all operators" << endl;
		cout << "\tPress 2 to print only operators with a given role character" << endl;
		cout << "\tPress 3 to print only operators with a given employment year" << endl;
		cout << "\tPress 4 to print only operators with a given employment month" << endl;
		cout << "\tPress 5 to print only operators with a given employment day" << endl;
		cout << "\tPress 6 to exit: ";
		cin >> choice;

		switch( choice )
		{
			case 1:
				cout << endl;
				operators[0].printOperators(operators, sizeOfOperators, '*', -1, -1, -1);
				cout << endl;
				break;

			case 2:
				char role;
				cout << endl;
				cout << "\tEnter filter role char: ";
				cin >> role;

				cout << endl;
				operators[0].printOperators(operators, sizeOfOperators, role, -1, -1, -1);
				cout << endl;
				break;

			case 3:
				int filterYear;
				cout << endl;
				cout << "\tEnter filter employment year: ";
				cin >> filterYear;

				cout << endl;
				operators[0].printOperators(operators, sizeOfOperators, '*', -1, -1, filterYear);
				cout << endl;
				break;

			case 4:
				int filterMonth;
				cout << "\tEnter filter employment month: ";
				cin >> filterMonth;

				cout << endl;
				operators[0].printOperators(operators, sizeOfOperators, '*', filterMonth, -1, -1);
				cout << endl;
				break;

			case 5:
				int filterDay;
				cout << "\tEnter filter employment day: ";
				cin >> filterDay;

				cout << endl;
				operators[0].printOperators(operators, sizeOfOperators, '*', -1, filterDay, -1);
				cout << endl;
				break;

			default:
				return;
		}
	}

}

/*
* Responsible for handling the generic menu
*
*
* @param operators: array of Operator structs
* @param sizeOfOperators: size of operators
*/
void menu(Operator *operators, int sizeOfOperators)
{
	if( operators == NULL || sizeOfOperators < 1 )
	{
		return;
	}

	int choice;
	while(true)
	{
		cout << endl;
		cout << "Press 1 for Manager menu" << endl;
		cout << "Press 2 for Operator menu" << endl;
		cout << "Press 3 to exit: ";
		cin >> choice;

		if( choice == 1 )
		{
			managerMenu(operators, sizeOfOperators);
		}
		else if( choice == 2 )
		{
			operatorMenu(operators, sizeOfOperators);
		}
		else
		{
			exit(0);
		}
	}
}

/*
	Entry point
*/
int main()
{
	Operator opr;
	int sizeOfOperators = 0;
	Operator *operators = opr.readDataFile("operators.txt", sizeOfOperators);

	menu(operators, sizeOfOperators);
	return 0;
}
