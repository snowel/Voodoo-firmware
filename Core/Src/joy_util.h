#define NESS_DELAY 18

uint8_t USBD_HID_SendReport(USBD_HandleTypeDef*, uint8_t*, uint16_t);

#include "main.h"
#include "usb_device.h"
#include "usbd_hid.h"
#include <extern_util.h>

//struct for joystick states
typedef struct {
	uint16_t yAxis;
	uint16_t xAxis;
	uint8_t position; //1-North, 2-East, 3-South, 4-West
} joystick;

joystick leftStick;
joystick rightStick;

void readStick(joystick* stick){
	uint16_t currentX;
	uint16_t currentY;

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	currentX = HAL_ADC_GetValue(&hadc1);

	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	currentY = HAL_ADC_GetValue(&hadc1);

	HAL_ADC_Stop(&hadc1);

	stick->xAxis = currentX;
	stick->yAxis = currentY;

}

void categorizeJoy(joystick stick){
	uint16_t xVal = stick.xAxis;
	uint16_t yVal = stick.yAxis;


}

//array of test variables

uint16_t butRef[] = {0, 0, 0, 0, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
uint8_t mapRef[16];
uint8_t keycodeOne = 0x1e;
uint8_t keycodeZero = 0x27;
uint8_t keycodeNewline = 0x28;



void joystickKeyPrint (uint16_t joystickVal){
	int j;

	for(j = 0; j < 16; j++){
		if(0 != butRef[j] & joystickVal){
			mapRef[j] = 1;
		} else{
			mapRef[j] = 0;
		}
	}

	for(j = 4; j < 10; j++){
		if (mapRef[j] == 1){
			setKeyBytes(&keycodeOne);
		} else {
			setKeyBytes(&keycodeZero);
		}
	}

	USBD_HID_SendReport(&hUsbDeviceFS, &HIDKeyboardReport, sizeof(HIDKeyboardReport));

		HAL_Delay(NESS_DELAY);

		for(j = 10; j < 16; j++){
				if (mapRef[j] == 1){
					setKeyBytes(&keycodeOne);
				} else {
					setKeyBytes(&keycodeZero);
				}
		}
		USBD_HID_SendReport(&hUsbDeviceFS, &HIDKeyboardReport, sizeof(HIDKeyboardReport));

		HAL_Delay(NESS_DELAY);
		clearReport();
		setKeyBytes(&keycodeNewline);
		USBD_HID_SendReport(&hUsbDeviceFS, &HIDKeyboardReport, sizeof(HIDKeyboardReport));
		HAL_Delay(NESS_DELAY);
}

void testMain(joystick* stick){
	readStick(stick);

	uint16_t valX = stick->xAxis;
	uint16_t valY = stick->yAxis;
	joystickKeyPrint(valX);
	joystickKeyPrint(valY);
	HAL_Delay(1500);
}

/*

	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  joyLX = HAL_ADC_GetValue(&hadc1);
*/
