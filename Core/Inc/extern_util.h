#include "stm32f4xx.h"
#include "usbd_def.h"
#ifndef EXTERN_UTIL_H
#define EXTERN_UTIL_H

extern ADC_HandleTypeDef hadc1;

typedef struct {
	uint8_t MOD;
	uint8_t REZ;
	uint8_t K1;
	uint8_t K2;
	uint8_t K3;
	uint8_t K4;
	uint8_t K5;
	uint8_t K6;
}keyboardHIDReport;

extern USBD_HandleTypeDef hUsbDeviceFS;


#endif //EXTERN_UTIL_H
