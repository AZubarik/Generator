#include "mode.h"

void waiting_mode(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, OFF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, OFF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, OFF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, OFF);	
	
	for (int i = 0; i <= 10; i++) {
		usSRegInBuf[i] = 0;	
	}
}
void modeVD(void) {
	HAL_Delay(250);
	ISTD_OFF;
	HAL_Delay(5000);
	measuringVD(); 
				  
	usSRegHoldBuf[1] = 0;
	ISTD_ON;
}

void modeVD_pulse(void) {
	HAL_Delay(250);
	id30min = 0; id30max = 0;
	
	PWMN_Stop(&htim1, TIM_CHANNEL_3);
	PWMN_Start(&htim1, TIM_CHANNEL_2);
	
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_Delay(100);
	HAL_TIM_Base_Stop_IT(&htim2);
	
	HAL_Delay(2000);

	ISTD_OFF;

	HAL_Delay(5000);
	measuringVD();
				  
	usSRegHoldBuf[1] = 0;

	ISTD_ON;
}

void modeVZ(void) {
	HAL_Delay(250);
	ISTZ_OFF;
	HAL_Delay(5000);
	measuringVZ();
				  
	usSRegHoldBuf[1] = 0;
	ISTZ_ON;
}

void modeVZ_pulse(void) {
	HAL_Delay(250);
	iz30min = 0, iz30max = 0;
	
	PWMN_Stop (&htim1, TIM_CHANNEL_2);
	PWMN_Start (&htim1, TIM_CHANNEL_3);
				  
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_Delay(100);
	HAL_TIM_Base_Stop_IT(&htim3);
	
	HAL_Delay(2000);
	
	ISTZ_OFF;
	
	HAL_Delay(5000);
	measuringVZ();
			  
	usSRegHoldBuf[1] = 0;
	
	ISTZ_ON;
}

void diagnostic(void) {
	iz30min = 0, iz30max = 0;
			  
	if (IZ30MIN == ON) {
		iz30min =  1;
		usSRegInBuf[5] = iz30min;
	}
	
	if (IZ30MAX == ON) {
		iz30max = 1;
		usSRegInBuf[6] = iz30max;
	}
	usSRegInBuf[5] = iz30min;
	usSRegInBuf[6] = iz30max;		  
}