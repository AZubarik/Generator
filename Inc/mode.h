#ifndef __mode_H
#define __mode_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "mb.h"
#include "mbport.h"
#include "user_mb_app.h"
#include "measuring_vd_vz.h"

extern uint16_t usSRegInBuf[];
extern uint16_t usSRegHoldBuf[];
int id30min, id30max, iz30min, iz30max;
	
void waiting_mode(void);
void modeVD(void);
void modeVZ(void);
void modeVD_pulse(void);
void modeVZ_pulse(void);	
void diagnostic(void);

#ifdef __cplusplus
}
#endif
#endif 