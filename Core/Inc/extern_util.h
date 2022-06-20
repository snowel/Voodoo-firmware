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
} keyboardHIDReport;

extern keyboardHIDReport HIDKeyboardReport;

extern USBD_HandleTypeDef hUsbDeviceFS;

uint8_t USBD_HID_SendReport(USBD_HandleTypeDef*, uint8_t*, uint16_t);

#endif //EXTERN_UTIL_H
