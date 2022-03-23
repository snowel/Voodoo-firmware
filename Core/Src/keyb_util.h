
#define NUMBER_OF_KEYS 7

//#include <stdint.h>
#include "keymap.h"
int i;

//uint8_t keyPins[] = {DasKey_Pin, L_m_Pin};// Array of pins
//GPIO_TypeDef * keyPorts[] = {DasKey_GPIO_Port, L_m_GPIO_Port};//array of ports
//GPIO_TypeDef * pKeyPorts = &keyPorts[0];

//struggling with arryas of pins and ports, this is my cheesy solution

//Array of key pin states
uint8_t pinStates[NUMBER_OF_KEYS];

//Init the pin array
void checkPins(void){
	pinStates[0] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	pinStates[1] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	pinStates[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
	pinStates[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
	pinStates[4] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
	pinStates[5] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	pinStates[6] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
}

int isHold[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//ints showing which Layer the keys are held from
//NOTE that if I leave it with 0 as unheld I cand have keys held from layer 0... or I need to start my layers at 1

/*
 * For some reason I need that arbitrary structure...

uint8_t HIDKeyboardReport[] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t * pHIDKeyboardReport = &HIDKeyboardReport[0];
uint16_t keyboardReportSize = sizeof(HIDKeyboardReport);
*/
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

keyboardHIDReport HIDKeyboardReport = {0, 0, 0, 0, 0, 0, 0, 0};

uint8_t* pModLayer;
uint8_t* pKeyLayer;
int layerNum;



void checkLayer(void){// Will probbaly end up setting the pointers to the mod and layer here
	layerNum = 1;
	pModLayer = &modKeyLayer1[0];
	pKeyLayer = &keyLayer1[0];
}

/*
void setModByte(uint8_t* code){
	HIDKeyboardReport[0] = HIDKeyboardReport[0] | *code;
}
*/
void setModByte(uint8_t* code){
	HIDKeyboardReport.MOD = HIDKeyboardReport.MOD | *code;
}

/*
void setKeyBytes(uint8_t* code){
	for(i = 2; i < 9; i++){
		if(HIDKeyboardReport[i] == 0){
			HIDKeyboardReport[i] = *code;
		}
	}
}
*/

void setKeyBytes(uint8_t* code){
	if(HIDKeyboardReport.K1 == 0){
		HIDKeyboardReport.K1 = *code;
	} else if(HIDKeyboardReport.K2 == 0){
		HIDKeyboardReport.K2 = *code;
	} else if(HIDKeyboardReport.K3 == 0){
		HIDKeyboardReport.K3 = *code;
	} else if(HIDKeyboardReport.K4 == 0){
		HIDKeyboardReport.K4 = *code;
	} else if(HIDKeyboardReport.K5 == 0){
		HIDKeyboardReport.K5 = *code;
	} else if(HIDKeyboardReport.K6 == 0){
		HIDKeyboardReport.K6 = *code;
	}
}

void setReport(int keypress, uint8_t * modArray, uint8_t * keyArray){
	uint8_t * modcode = modArray + keypress;
	//	uint8_t * modcode = &modKeyLayer1[keypress];
	uint8_t * keycode = keyArray + keypress;
	//	uint8_t * keycode = &keyLayer1[keypress]; if only one layer, makes mores ense to by amature mind

	setKeyBytes(keycode);
	setModByte(modcode);
}

void setHeld(int keypress, int layerNumber){
	isHold[keypress] = layerNumber;
}

void setHeldReport(int keypress){
	int holdLayer = isHold[keypress];//if isHold[0] then the key is not held, else it's the numebr of the layer it was pressed down in

//Not sure why this double poitner system doesn't work...
//	int layerRef = holdLayer - 1;

//	uint8_t ** relLayer = layers[layerRef];
//	uint8_t * relMods = *relLayer;
//	uint8_t * relKeys = *relLayer + 1;

	int modArrayIndex = (holdLayer * 2) - 2;
	int keyArrayIndex = (holdLayer * 2) -1;

	uint8_t * relMods = testLayerRef[modArrayIndex];
	uint8_t * relKeys = testLayerRef[keyArrayIndex];


	setReport(keypress, relMods, relKeys);

}

void scanKeys(){
	for(i = 0; i < NUMBER_OF_KEYS; i++){
		//Original if condition was: GPIO_PIN_RESET == HAL_GPIO_ReadPin(keyPorts[i]/, keyPins[i])
		if(pinStates[i] == 0){
			switch(isHold[i]){
			case 0: setReport(i, pModLayer, pKeyLayer);
					setHeld(i, layerNum);//TODO  LayerNum in layer check funct
				break;
			default: setHeldReport(i);
				break;
			}

		} else {// add a check? : else if (isHold[1] != 0) {} ?? not sure what's best practice
			setHeld(i, 0);
		}
	}
}

void clearReport(void){
	HIDKeyboardReport.MOD = 0;
	HIDKeyboardReport.K1 = 0;
	HIDKeyboardReport.K2 = 0;
	HIDKeyboardReport.K3 = 0;
	HIDKeyboardReport.K4 = 0;
	HIDKeyboardReport.K5 = 0;
	HIDKeyboardReport.K6 = 0;
}
