#ifndef _HEXAGONAL_TANK_INCLUDED_
#define _HEXAGONAL_TANK_INCLUDED_


class HexagonalPrismTank
{
	private:
		float threeRootThreeDivTwo;
		float baseArea;
		float height;

		float liquidHeight;
		float tankCapacity;
	public:
		HexagonalPrismTank();
		
		float getMaxPossibleVolume();
		float getCurrentVolume();
		float getLiquidHeight();
		float getMaxLiquidHeight();

		float getAmtToCompletelyFillTank();
		float getAmtToPartiallyFillTank(float LiquidHeight);

		void supplyOil(float LiquidHeight);
};

#endif 