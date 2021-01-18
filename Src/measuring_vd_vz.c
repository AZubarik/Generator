#include "measuring_vd_vz.h"

uint16_t		CFG = 0x39FF << 2,
         AD7682_IN0 = 0x3C49 << 2,         // 0x3C49   // 0x3849
         AD7682_IN1 = 0x3CC9 << 2,         // 0x3CC9   // 0x38C9
         AD7682_IN2 = 0x3D49 << 2,         // 0x3D49   // 0x3949
         AD7682_IN3 = 0x3DC9 << 2;         // 0x3DC9   // 0x39C9   
                    
float deltaADC = 0.0000625,
      Resistor = 0.25;

int   UDOUT = 2,	IDOUT = 2,
      UZOUT = 2,	IZOUT = 2;
uint16_t out;
uint16_t* tmp;
float currentADC_vd, voltageADC_vd, currentADC_vz, voltageADC_vz;
extern uint16_t usSRegInBuf[];

int setConfigADC(uint16_t value) {
    
    for (int i = 0; i <= 15; i++) {
	    CNV_OFF;
	    HAL_Delay(2);
        HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&value, (uint8_t*)&out, 1, 10);
        HAL_Delay(2);	
        CNV_ON;
    }
    return out;
}

void dataTransferADC(int registr, float out) {
	tmp = (uint16_t*) &out;
    usSRegInBuf[registr] = *tmp;
    usSRegInBuf[registr + 1] = *(tmp + 1);
}

void measuringVD(void) { 
    setConfigADC(AD7682_IN3);
    voltageADC_vd = out * deltaADC  * UDOUT ;
    dataTransferADC(0, voltageADC_vd);
    
    setConfigADC(AD7682_IN2);  
    currentADC_vd = out * deltaADC * IDOUT; 
    dataTransferADC(2, currentADC_vd);
}

void measuringVZ(void) {
    setConfigADC(AD7682_IN1);
    voltageADC_vz = out * deltaADC * UZOUT;
    dataTransferADC(4, voltageADC_vz);

    setConfigADC(AD7682_IN0); 
    currentADC_vz = out * deltaADC * IZOUT * Resistor;  
    dataTransferADC(6, currentADC_vz);
}

void configurationADC(void) {
	
    for (int i = 0; i <= 3; i++) {
        CNV_ON;
        HAL_Delay(20);
        
        CNV_OFF;
        HAL_Delay(2);
        HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&CFG, (uint8_t*)&out, 1, 10);
        HAL_Delay(2);
        CNV_ON;
    }
}

