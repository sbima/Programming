#include "HexagonalPrismTank.h"

/*
* Constructor: Responsible for initializing CylindricalTank members to safe state
*/
HexagonalPrismTank::HexagonalPrismTank()
{
	threeRootThreeDivTwo = 2.5980762;

	baseArea = 6;
	height = 400;

	liquidHeight = 0;
	tankCapacity = threeRootThreeDivTwo * baseArea * baseArea * height;
}

/*
* Responsible for getting the max liquid height
* 
*
* @param return: max liquid height
*/
float HexagonalPrismTank::getMaxLiquidHeight()
{
	return height;
}

/*
* Responsible for getting the current liquid height
* 
*
* @param return: current liquid height
*/
float HexagonalPrismTank::getLiquidHeight()
{
	return liquidHeight;
}

/*
* Responsible for getting the calculated maximum possible volume of the cylindrical tank
* 
*
* @param return: volume of the cylindrical tank
*/
float HexagonalPrismTank::getMaxPossibleVolume()
{
	return tankCapacity;
}

/*
* Responsible for calculating the current volume of the cylindrical tank
* 
*
* @param return: volume of the cylindrical tank
*/
float HexagonalPrismTank::getCurrentVolume()
{
	return threeRootThreeDivTwo * baseArea * baseArea * liquidHeight;
}

/*
* Responsible for setting the new height for the cylindrical tank
* 
*
* @param LiquidHeight: new (additional) height for the tank
*/
void HexagonalPrismTank::supplyOil(float LiquidHeight)
{
	// if the proposed liquid height exceeds of reaches the maximum possible height
	liquidHeight += LiquidHeight;
	if( liquidHeight > height )
	{
		// tank is full
		liquidHeight = height;
	}
}

/*
* Responsible for calculating the amount of oil required to completely fill a full or partially filled cylindrical tank
* 
*
* @param return: oil required to completely fill a full or partially filled cylindrical tank
*/
// Quesion 1. solution
float HexagonalPrismTank::getAmtToCompletelyFillTank()
{
	return getMaxPossibleVolume() - getCurrentVolume();
}

/*
* Responsible for calculating the amount of oil required to partially fill cylindrical tank
* 
*
* @param return: oil required to oil required to partially fill cylindrical tank
*/
// Quesion 2. solution
float HexagonalPrismTank::getAmtToPartiallyFillTank(float LiquidHeight)
{
	if( LiquidHeight <= liquidHeight || LiquidHeight > height )
	{
		return 0;
	}

	float newVolume = threeRootThreeDivTwo * baseArea * baseArea * LiquidHeight;
	float currentVolume = getCurrentVolume();

	return newVolume - currentVolume;
}
