//* Includes ------------------------------------------------------------------*/
#include "check.h"
#include <stdbool.h>

extern uint16_t usSRegInBuf[];
extern uint16_t usSRegHoldBuf[];

float maxvoltage, minvoltage, maxcurrent, mincurrent;
float deltaVoltage, deltaCurrent;
float currentADC, voltageADC, currentADCP, voltageADCP; 
float procentageOfErrors;
bool checkRange(float maxx, float minx, float xADC)
{
	return (maxx > xADC) && (minx < xADC);
}

void check(void) 
{
	maxvoltage = usSRegHoldBuf[2];
	minvoltage = usSRegHoldBuf[3];	
	
	maxcurrent = usSRegHoldBuf[4];
	mincurrent = usSRegHoldBuf[5];
				
	bool isRangeVoltage = checkRange(maxvoltage, minvoltage, voltageADC);
	bool isRangeCurrent = checkRange(maxcurrent, mincurrent, currentADC);
	
	if (isRangeVoltage && isRangeCurrent)
	{
		usSRegInBuf[4] = 1;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	}
	else
	{
		usSRegInBuf[4] = 0;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	}
}

void check_thermaltests(void) 
{
	procentageOfErrors = usSRegHoldBuf[4];
	
	deltaVoltage = voltageADC * procentageOfErrors * 0.01;
	deltaCurrent = currentADC * procentageOfErrors * 0.01;
	
	maxvoltage = voltageADC + deltaVoltage;
	minvoltage = voltageADC - deltaVoltage;
	
	maxcurrent = currentADC + deltaCurrent;
	mincurrent = currentADC - deltaCurrent;	

	
	bool isRangeVoltage = checkRange(maxvoltage, minvoltage, voltageADCP);
	bool isRangeCurrent = checkRange(maxcurrent, mincurrent, currentADCP);
	
	if (isRangeVoltage && isRangeCurrent)
	{
		usSRegInBuf[4] = 1;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	}
	else
	{
		usSRegInBuf[4] = 0;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	}
}
