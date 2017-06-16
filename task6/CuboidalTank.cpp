#include "CuboidalTank.h"

/*
* Constructor: Responsible for initializing CuboidalTank members to safe state
*/
CuboidalTank::CuboidalTank()
{
	length = 10;
	width = 6;
	height = 400;

	liquidHeight = 0;
	tankCapacity = length * width * height;
}

/*
* Responsible for getting the max liquid height
* 
*
* @param return: max liquid height
*/
float CuboidalTank::getMaxLiquidHeight()
{
	return height;
}

/*
* Responsible for getting the current liquid height
* 
*
* @param return: current liquid height
*/
float CuboidalTank::getLiquidHeight()
{
	return liquidHeight;
}

/*
* Responsible for getting the calculated maximum possible volume of the cuboidal tank
* 
*
* @param return: volume of the cuboidal tank
*/
float CuboidalTank::getMaxPossibleVolume()
{
	return tankCapacity;
}

/*
* Responsible for calculating the current volume of the cuboidal tank
* 
*
* @param return: volume of the cuboidal tank
*/
float CuboidalTank::getCurrentVolume()
{
	return length * width * liquidHeight;
}

/*
* Responsible for setting the new liquid height for the cuboidal tank
* 
*
* @param LiquidHeight: new (additional) height for the tank
*/
void CuboidalTank::supplyOil(float LiquidHeight)
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
* Responsible for calculating the amount of oil required to completely fill a full or partially filled cuboidal tank
* 
*
* @param return: oil required to completely fill a full or partially filled cuboidal tank
*/
// Quesion 1. solution
float CuboidalTank::getAmtToCompletelyFillTank()
{
	return getMaxPossibleVolume() - getCurrentVolume();
}

/*
* Responsible for calculating the amount of oil required to partially fill cuboidal tank
* 
*
* @param return: oil required to oil required to partially fill cuboidal tank
*/
// Quesion 2. solution
float CuboidalTank::getAmtToPartiallyFillTank(float LiquidHeight)
{
	if( LiquidHeight <= liquidHeight || LiquidHeight > height )
	{
		return 0;
	}

	float newVolume = length * width * LiquidHeight;
	float currentVolume = getCurrentVolume();

	return newVolume - currentVolume;
}
