#ifndef _CYCLINDRICAL_TANK_INCLUDED_
#define _CYCLINDRICAL_TANK_INCLUDED_


class CylindricalTank
{
	private:
		float PI;
		float radius;
		float height;

		float liquidHeight;
		float tankCapacity;
	public:
		CylindricalTank();
		
		float getMaxPossibleVolume();
		float getCurrentVolume();
		float getLiquidHeight();
		float getMaxLiquidHeight();

		float getAmtToCompletelyFillTank();
		float getAmtToPartiallyFillTank(float LiquidHeight);

		void supplyOil(float LiquidHeight);
};

#endif 