#include "keyb_util.h"



// Update the key-press array.
// This is where the keys "index" is determined.
void checkKeyPins(uint8_t* keyRef){
	keyRef[0] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
	keyRef[1] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
	keyRef[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	keyRef[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
	keyRef[8] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
	keyRef[9] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
	keyRef[10] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	keyRef[11] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	keyRef[4] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
	keyRef[5] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
	keyRef[6] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
	keyRef[7] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
	keyRef[12] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	keyRef[13] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	//keyRef[14] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2); -- Hard-fault culprit
	keyRef[15] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);

}


void setModByte(uint8_t* code, keyboardHIDReport report){
	report.MOD = report.MOD | *code;
}

void setKeyBytes(uint8_t* code, keyboardHIDReport keyboardReport){
	if(keyboardReport.K1 == 0){
		keyboardReport.K1 = *code;
	} else if(keyboardReport.K2 == 0){
		keyboardReport.K2 = *code;
	} else if(keyboardReport.K3 == 0){
		keyboardReport.K3 = *code;
	} else if(keyboardReport.K4 == 0){
		keyboardReport.K4 = *code;
	} else if(keyboardReport.K5 == 0){
		keyboardReport.K5 = *code;
	} else if(keyboardReport.K6 == 0){
		keyboardReport.K6 = *code;
	}
}

//TODO physical vs imp priority could be configurable
void setReport(int keypress, Layer* layer, keyboardHIDReport keyboardReport){
	// Imp key
	uint8_t * modcode = layer->impMod;
	uint8_t * keycode = layer->impKey;

	setKeyBytes(keycode, keyboardReport);
	setModByte(modcode, keyboardReport);

	// Physical key
	modcode = layer->pModLayer + keypress; // TODO implications of pModLayer[keypress] auto dereference rather than using a pointer?
	keycode = layer->pKeyLayer + keypress;

	setKeyBytes(keycode, keyboardReport);
	setModByte(modcode, keyboardReport);

}

/*old
 * void setReport(int keypress, uint8_t * modArray, uint8_t * keyArray){
	uint8_t * modcode = modArray + keypress;// Isn't this modArray[keypress]?
	//	uint8_t * modcode = modKeyLayer1[keypress]; ... also, this was &modKeyLayer1[keypress]... which isn't right
	uint8_t * keycode = keyArray + keypress;
	//	uint8_t * keycode = keyLayer1[keypress]; if only one layer, makes mores ense to by amature mind

	setKeyBytes(keycode);
	setModByte(modcode);
}
 * */

void setHeld(int keypress, int layerNumber, int* heldRef){
	heldRef[keypress] = layerNumber;
}

void setHeldReport(int keypress, Layer* keymap, int* heldRef, keyboardHIDReport keyboardReport){
	Layer* heldKeyLayer = &keymap[heldRef[keypress]];
	//if isHold[0] then the key is not held, else it's the numebr of the layer it was pressed down in

	setReport(keypress, heldKeyLayer, keyboardReport);

}

/*old
 * void setHeldReport(int keypress){
	int holdLayer = isHold[keypress];//if isHold[0] then the key is not held, else it's the numebr of the layer it was pressed down in

//Not sure why this double pointner system doesn't work...
//	int layerRef = holdLayer - 1;

//	uint8_t ** relLayer = layers[layerRef]; ...probbably because this fully defreferences the pointer?
//	uint8_t * relMods = *relLayer;
//	uint8_t * relKeys = *relLayer + 1;

	int modArrayIndex = (holdLayer * 2) - 2;
	int keyArrayIndex = (holdLayer * 2) -1;

	uint8_t * relMods = testLayerRef[modArrayIndex];
	uint8_t * relKeys = testLayerRef[keyArrayIndex];


	setReport(keypress, relMods, relKeys);

}
 * */

void scanKeys(Layer* keymap, Layer* layerRef, int* heldRef, uint8_t* keyRef, keyboardHIDReport report){
	int i;
	for(i = 0; i < NUMBER_OF_KEYS; i++){
		//Original if condition was: GPIO_PIN_RESET == HAL_GPIO_ReadPin(keyPorts[i]/, keyPins[i])
		if(keyRef[i] == 0){
			switch(heldRef[i]){
			case 0: setReport(i, layerRef, report);
					setHeld(i, layerRef->layerNum, heldRef);
				break;
			default: setHeldReport(i, keymap, heldRef, report);
				break;
			}

		} else {// add a check? : else if (isHold[1] != 0) {} ?? not sure what's best practice
			setHeld(i, 0, heldRef);
		}
	}
}

// scan function for keyboard settings i.e. swtichingmouse mode

// scan for thumb-stick keys, so scans held, but sets the report to a prebuilt report mapped tot hat layer... technically with that the layer could still function normally... for mod keys... probbaly a more elegant solution for most cases... but I do like the manual mod map

void clearReport(keyboardHIDReport keyboardReport){
	keyboardReport.MOD = 0;
	keyboardReport.K1 = 0;
	keyboardReport.K2 = 0;
	keyboardReport.K3 = 0;
	keyboardReport.K4 = 0;
	keyboardReport.K5 = 0;
	keyboardReport.K6 = 0;
}
