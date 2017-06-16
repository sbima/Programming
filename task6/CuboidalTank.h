#ifndef _CUBOIDAL_TANK_INCLUDED_
#define _CUBOIDAL_TANK_INCLUDED_

class CuboidalTank
{
	private:
		float length;
		float width;
		float height;

		float liquidHeight;
		float tankCapacity;
	public:
		CuboidalTank();
		
		float getMaxPossibleVolume();
		float getCurrentVolume();
		float getLiquidHeight();
		float getMaxLiquidHeight();

		float getAmtToCompletelyFillTank();
		float getAmtToPartiallyFillTank(float LiquidHeight);

		void supplyOil(float LiquidHeight);
};

#endif 