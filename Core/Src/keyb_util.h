

#ifndef KEYB_UTIL.H
#define KEYB_UTIL.H


#define NUMBER_OF_KEYS 16
#include <stdint.h>
#include <extern_util.h>
#include <main.h>
#include "keymap.h"




// Array of key pin states. For the current pull up resistor, the values of a lifted keys is 1, and pressed key is 0.
extern uint8_t pinStates[NUMBER_OF_KEYS];

// Fetch the pin values for the keys.
// This determines the order of the keys.
void checkKeyPins(uint8_t* keyRef);

extern int isHold[NUMBER_OF_KEYS];//ints showing which Layer the keys are held from
//NOTE that if I leave it with 0 as unheld I cand have keys held from layer 0... or I need to start my layers at 1

/*
 * For some reason I need that arbitrary structure...

uint8_t HIDKeyboardReport[] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t * pHIDKeyboardReport = &HIDKeyboardReport[0];
uint16_t keyboardReportSize = sizeof(HIDKeyboardReport);
*/


extern keyboardHIDReport kReport;



void scanKeys(Layer* keymap, Layer* layerRef, int* heldRef, uint8_t* keyRef, keyboardHIDReport report);

// scan function for keyboard settings i.e. swtichingmouse mode

// scan for thumb-stick keys, so scans held, but sets the report to a prebuilt report mapped tot hat layer... technically with that the layer could still function normally... for mod keys... probbaly a more elegant solution for most cases... but I do like the manual mod map

void clearReport(keyboardHIDReport keyboardReport);
#endif
