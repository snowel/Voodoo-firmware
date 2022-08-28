#include "main.h"
#include "usb_device.h"
#include "usbd_hid.h"
#include <extern_util.h>
#include <stdint.h>


// Star joy stick

#define NESS_DELAY 18
#define POT_MIDPOINT 2040

enum joydir {
	CENTERWISE = 0,
	EASTWISE,
	SOUTHWISE,
	NORTHWISE,
	WESTWISE,
};

//struct for joystick states
typedef struct joystick{
	uint16_t yAxis;
	uint16_t xAxis;
	uint8_t position; //1-south, 2-East, 3-North, 4-West
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

void readADCToJoy(joystick* stick, uint32_t* buff){
	uint16_t xVal = (uint16_t)(buff[0] >> 16);
	uint16_t yVal = (uint16_t)(buff[0] >> 16);

	stick->xAxis = xVal;
	stick->yAxis = yVal;

}

enum joydir categorizeJoy(joystick* stick, uint32_t tresh){
	int16_t xVal = (int16_t)stick->xAxis;
	int16_t yVal = (int16_t)stick->yAxis;

	xVal -=  POT_MIDPOINT;
	yVal -=  POT_MIDPOINT;


	int xMag = abs(xVal);
	int yMag = abs(yVal);

	if(xMag >= tresh || yMag >= tresh) return CENTERWISE; //Stick not directed

	if(xMag > yMag) {// HORZ MOTION
		if(xVal > 0) {
			return EASTWISE; // this needs to be automated to the polarit of the stick, knowing which way the resistance increses
		} else {
			return WESTWISE;
		}

	} else { // VERT MOTION
		if(yVal > 0) {
			return NORTHWISE; // this needs to be automated to the polarit of the stick, knowing which way the resistance increses
		} else {
			return SOUTHWISE;
		}
	}

 return CENTERWISE; // If they're equal in magnitude they cancle out
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


// end joystick


// the joy position will be broken down into a bitmask, the byte is mapped as follows:

// 0 0 0 0 0 0 0 0
// bit 7 - 128 : left-left
// bit 6 - 64 : left-up
// bit 5 - 32 : left-rigth
// bit 4 - 16 : left-down
// bit 3 - 8 : right-left
// bit 2 - 4 : right-up
// bit 1 - 2 : right-right
// bit 0 - 1 : rigth-down

#define LAYER_1_ID 0// 1 = none none - 0 + 0
#define LAYER_2_ID 1// 2 = none down - 0 + 1
#define LAYER_3_ID 2// 3 = none right - 0 + 2
#define LAYER_4_ID 4// 4 = none up - Shifted Alphas 1
#define LAYER_5_ID 8 // 5 = none left - !!Imp!! Space
#define LAYER_6_ID 16 // 6 = down none - Numbers + Mods
#define LAYER_7_ID 17 // 7 = down down - WM shortcuts
#define LAYER_8_ID 18 // 8 = down right
#define LAYER_9_ID 20 // 9 = down up - Shifted Numbers
#define LAYER_10_ID 24 // 10 = down left
#define LAYER_11_ID 32 // 11 = right none - 32 + 0
#define LAYER_12_ID 33 // 12 = right down
#define LAYER_13_ID 34 // 13 = right right
#define LAYER_14_ID 36  // 14 = right up - Shifted Alphas 2
#define LAYER_15_ID 40  // 15 = right left
#define LAYER_16_ID 64 // 16 = up none
#define LAYER_17_ID 65  // 17 = up down
#define LAYER_18_ID 66  // 18 = up right
#define LAYER_19_ID 68  // 19 = up up - Tmux Shortcuts
#define LAYER_20_ID 72  // 20 = up left
#define LAYER_21_ID 128  // 21 = left none - Arrowkeys
#define LAYER_22_ID 129  // 22 = left down
#define LAYER_23_ID 130  // 23 = left right
#define LAYER_24_ID 132  // 24 = left up
#define LAYER_25_ID 136  // 25 = left left 128 + 8


#define LEFT_JOY_LEFT 0x80
#define LEFT_JOY_UP 0x40
#define LEFT_JOY_RIGHT 0x20
#define LEFT_JOY_DOWN 0x10

#define RIGHT_JOY_LEFT 0x08
#define RIGHT_JOY_UP 0x04
#define RIGHT_JOY_RIGHT 0x02
#define RIGHT_JOY_DOWN 0x01 // A more gneric but confusing way would be to have the directions be 1, 2, 4, 8 and then bitwise shift for the position of every stick

#define LEFT_JOY_LEFT_TRESH 0x80
#define LEFT_JOY_UP_TRESH 0x40
#define LEFT_JOY_RIGHT_TRESH 0x20
#define LEFT_JOY_DOWN_TRESH 0x10

#define RIGHT_JOY_LEFT_TRESH 0x08
#define RIGHT_JOY_UP_TRESH 0x04
#define RIGHT_JOY_RIGHT_TRESH 0x02
#define RIGHT_JOY_DOWN_TRESH 0x01

#define DEFAULT_TRESH 500

typedef uint8_t joystate;

enum joyhandedness {
	RIGTH_JOY = 1,
	LEFT_JOY
};

// switch case with 25 cases

int bitmaskToLayer(uint8_t bitmask){
	switch (bitmask) {
		case LAYER_1_ID :
			return 1;
			break;
		case LAYER_2_ID :
			return 2;
			break;
		case LAYER_3_ID :
			return 3;
			break;
		case LAYER_4_ID :
			return 4;
			break;
		case LAYER_5_ID :
			return 5;
			break;
		case LAYER_6_ID :
			return 6;
			break;
		case LAYER_7_ID :
			return 7;
			break;
		case LAYER_8_ID :
			return 8;
			break;
		case LAYER_9_ID :
			return 9;
			break;
		case LAYER_10_ID:
			return 10;
			break;
		case LAYER_11_ID:
			return 11;
			break;
		case LAYER_12_ID:
			return 12;
			break;
		case LAYER_13_ID:
			return 13;
			break;
		case LAYER_14_ID:
			return 14;
			break;
		case LAYER_15_ID:
			return 15;
			break;
		case LAYER_16_ID:
			return 16;
			break;
		case LAYER_17_ID:
			return 17;
			break;
		case LAYER_18_ID:
			return 18;
			break;
		case LAYER_19_ID:
			return 19;
			break;
		case LAYER_20_ID:
			return 20;
			break;
		case LAYER_21_ID:
			return 21;
			break;
		case LAYER_22_ID:
			return 22;
			break;
		case LAYER_23_ID:
			return 23;
			break;
		case LAYER_24_ID:
			return 24;
			break;
		case LAYER_25_ID:
			return 25;
			break;
	}
}

// Set byte

joystate* setJoystate(joystick* left, joystick* right, joystate* handle, uint32_t tresh){
	enum joydir leftDir = categorizeJoy(left, tresh);
	enum joydir rightDir = categorizeJoy(right, tresh);


	switch(leftDir){
		case NORTHWISE:
			*handle = *handle | LEFT_JOY_UP;
			break;
		case EASTWISE:
			*handle = *handle | LEFT_JOY_RIGHT;
			break;
		case SOUTHWISE:
			*handle = *handle | LEFT_JOY_DOWN;
			break;
		case WESTWISE:
			*handle = *handle | LEFT_JOY_LEFT;
			break;
	}

	switch(rightDir){
		case NORTHWISE:
			*handle = *handle | RIGHT_JOY_UP;
			break;
		case EASTWISE:
			*handle = *handle | RIGHT_JOY_RIGHT;
			break;
		case SOUTHWISE:
			*handle = *handle | RIGHT_JOY_DOWN;
			break;
		case WESTWISE:
			*handle = *handle | RIGHT_JOY_LEFT;
			break;
		}

	return handle;

}

