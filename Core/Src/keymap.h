#include "usb_hid_keys.h"
#include <stdint.h>

#ifndef KEYMAP_H
#define KEYMAP_H

typedef struct Layer {
	uint8_t* impMod;
	uint8_t* impKey;
	uint8_t* pModLayer;
	uint8_t* pKeyLayer;
	int layerNum;
}Layer;

extern const Layer* keymap[26];

#define NUMBER_OF_LAYERS 25
#endif //KEYMAP_H
