#include "CylindricalTank.h"

/*
* Constructor: Responsible for initializing CylindricalTank members to safe state
*/
CylindricalTank::CylindricalTank()
{
	PI = 3.1415926;

	radius = 6;
	height = 400;

	liquidHeight = 0;
	tankCapacity = PI * radius * radius * height;
}

/*
* Responsible for getting the max liquid height
* 
*
* @param return: max liquid height
*/
float CylindricalTank::getMaxLiquidHeight()
{
	return height;
}

/*
* Responsible for getting the current liquid height
* 
*
* @param return: current liquid height
*/
float CylindricalTank::getLiquidHeight()
{
	return liquidHeight;
}

/*
* Responsible for getting the calculated maximum possible volume of the cylindrical tank
* 
*
* @param return: volume of the cylindrical tank
*/
float CylindricalTank::getMaxPossibleVolume()
{
	return tankCapacity;
}

/*
* Responsible for calculating the current volume of the cylindrical tank
* 
*
* @param return: volume of the cylindrical tank
*/
float CylindricalTank::getCurrentVolume()
{
	return PI * radius * radius * liquidHeight;
}

/*
* Responsible for setting the new liquid height for the cylindrical tank
* 
*
* @param LiquidHeight: new (additional) height for the tank
*/
void CylindricalTank::supplyOil(float LiquidHeight)
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
float CylindricalTank::getAmtToCompletelyFillTank()
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
float CylindricalTank::getAmtToPartiallyFillTank(float LiquidHeight)
{
	if( LiquidHeight <= liquidHeight || LiquidHeight > height )
	{
		return 0;
	}

	float newVolume = PI * radius * radius * LiquidHeight;
	float currentVolume = getCurrentVolume();

	return newVolume - currentVolume;
}
