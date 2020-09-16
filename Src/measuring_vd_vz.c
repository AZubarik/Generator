//* Includes ------------------------------------------------------------------*/
#include "measuring_vd_vz.h"
#include "converting.h"
//* Includes ------------------------------------------------------------------*/

uint16_t AD7682_IN0 = 0x3C79 ;         //0x3C79
uint16_t AD7682_IN1 = 0x3CF9;      // 0x3CF9
uint16_t AD7682_IN2 = 0x3D79  ;       //  0x3D79
uint16_t AD7682_IN3 = 0x3DF9;             //0x3DF9     

uint16_t out;

float currentADC, voltageADC, currentADCP, voltageADCP; 
extern uint16_t usSRegInBuf[];
extern uint16_t usSRegHoldBuf[];

void setConfigADC(uint16_t value)
{
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_SET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_RESET);
	
	uint16_t registerADC = value;
	uint8_t* pRegisterADC = (uint8_t*)(&registerADC);    //(uint8_t*)&AD7682_IN3
	
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_SET);
	
	//HAL_SPI_Transmit(&hspi2, (uint8_t*)&AD7682_IN2, 1, 5);
	
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)& AD7682_IN2, (uint8_t*)&out, 16,5);
	 usSRegInBuf[0] = out;
}

int getMeasurementADC()
{
	uint16_t out;
	int resultBin;
	
//	HAL_SPI_Receive(&hspi2, (uint8_t*)&out, 2, 5); 	
	resultBin = out;
	
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_SET);
	return binaryToDecimal(resultBin);
}
/*----------------------------------------------------------------------------*/

void staticsVD(void)
	
{   
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_SET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)& AD7682_IN3, (uint8_t*)&out,4, 5);
	usSRegInBuf[0] = out;
	
	HAL_GPIO_WritePin(GPIOB, CNV, GPIO_PIN_SET);
	
//	setConfigADC(AD7682_IN3);
//	voltageADC = getMeasurementADC(); // * 0.0000625;
 //   usSRegInBuf[0] = voltageADC;
		
//	setConfigADC(AD7682_IN2);                      
//	usSRegInBuf[1] = getMeasurementADC();  
//	currentADC =  getMeasurementADC(); // * 0.0000625 * 0.005;
//	usSRegInBuf[1] = currentADC;
//	
	usSRegHoldBuf[0] = 0;
}

void staticsVZ(void)
{
	setConfigADC(AD7682_IN1);
	usSRegInBuf[2] = getMeasurementADC();
     
	HAL_Delay(20);

	setConfigADC(AD7682_IN0);                      
	usSRegInBuf[3] = getMeasurementADC(); 
  
	usSRegHoldBuf[0] = 0;
}

void dynamic_VD(void)
{
	setConfigADC(AD7682_IN3);
	voltageADCP = getMeasurementADC();  // * 0.0000625;
    usSRegInBuf[0] = voltageADCP;
	
	HAL_Delay(20);
	
	setConfigADC(AD7682_IN2);                      
	usSRegInBuf[1] = getMeasurementADC();  
	currentADCP =  getMeasurementADC();  // * 0.0000625 * 0.005;
	usSRegInBuf[1] = currentADCP;
	
	usSRegHoldBuf[0] = 0;
}

void dynamic_VZ(void)
{
	setConfigADC(AD7682_IN1);
	usSRegInBuf[2] = getMeasurementADC();
     
	HAL_Delay(20);

	setConfigADC(AD7682_IN0);                      
	usSRegInBuf[3] = getMeasurementADC(); 
  
	usSRegHoldBuf[0] = 0;
}

/*----------------------------------------------------------------------------*/
//	SPI2->DR = 0x3DF9;
//	while (!(SPI2->SR & SPI_FLAG_RXNE)) ;
//	reg16bit = (int16_t)(SPI2->DR);
//	usSRegInBuf[0] = reg16bit;