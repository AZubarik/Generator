/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __check_H
#define __check_H
#ifdef __cplusplus
extern "C" {
#endif

	/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "mb.h"
#include "mbport.h"
#include "user_mb_app.h"

	/* USER CODE BEGIN Includes */

	/* USER CODE END Includes */

	/* USER CODE BEGIN Private defines */

	/* USER CODE END Private defines */

	void check(void);
	void check_thermaltests(void);

	/* USER CODE BEGIN Prototypes */

	/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */