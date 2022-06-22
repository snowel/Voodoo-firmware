#include <usb_hid_keys.sh>
#include "usb_hid_keys.h"
#ifndef KEYMAP_H
#define "KEYMAP_H"
#define NUMBER_OF_LAYERS 25


//Maps for 16 key no thumb cluster
// {0,1,2,3,   4,5,6,7
// 8,9,10,11, 12,13,14,15}
//

// TODO -- layer number not set!!!!

//L-1 - base alphas 1/2
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer1[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_N, KEY_E, KEY_I, KEY_O,
                       KEY_U, KEY_F, KEY_C, KEY_D,       KEY_H, KEY_SPACE, KEY_L, KEY_W};
//                            Might need to move space, which is currently with e which is the msot use letter a d e space isa  common bigram
//                            Might also need to move L, because if I swap with space LE is probbaly pretty common
//uint8_t * layer1[] = {&modKeyLayer1[0], &keyLayer1[0]};

//Layer 2 - base alpahs 2/2
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer2[] = {KEY_Q, KEY_K, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                       KEY_Z, KEY_J, KEY_V, KEY_G,        KEY_M, KEY_COMMA, KEY_DOT, KEY_X};
//uint8_t * layer2[] = {&modKeyLayer2[0], &keyLayer2[0]};
/*
uint8_t modKeyLayer2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t keyLayer2[] = {KEY_Q, KEY_W, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                       KEY_Z, KEY_J, KEY_V, KEY_G        KEY_M, KEY_COMMA, KEY_DOT, KEY_X};
 *
 * */

//L-3 - shifted alpahas 1/2
uint8_t modKeyLayer3[] = {
		   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
		   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT};
uint8_t keyLayer3[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_N, KEY_E, KEY_I, KEY_O,
                       KEY_U, KEY_F, KEY_C, KEY_D,       KEY_H, KEY_SPACE, KEY_L, KEY_W};

//L-4 - shifted alpahs 2/2
uint8_t modKeyLayer3[] = {
		   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
		   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT};

uint8_t keyLayer2[] = {KEY_Q, KEY_K, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                       KEY_Z, KEY_J, KEY_V, KEY_G,        KEY_M, KEY_COMMA, KEY_DOT, KEY_X};


// L-5  number layer
uint8_t modKeyLayer1[] = {
		                            0, 0, 0, 0,     0, 0, 0, 0,
KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, 0,     0, KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer1[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};

// L-6  number layer shifted
uint8_t modKeyLayer3[] = {
   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
   KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT,KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};


// L-7 one total mod key layer
uint8_t modKeyLayer1[] = {
KEY_MOD_LCTRL, KEY_MOD_LMETA, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_RSHIFT,KEY_MOD_RALT, KEY_MOD_RMETA, KEY_MOD_RCTRL,
KEY_MOD_RCTRL, KEY_MOD_RMETA, KEY_MOD_RALT, KEY_MOD_RSHIFT,     KEY_MOD_LSHIFT,KEY_MOD_LALT, KEY_MOD_LMETA, KEY_MOD_LCTRL};
uint8_t keyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

//L-8 - Arrow keys et al
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer1[] = {       0, KEY_ESC, KEY_HOME, KEY_END,       KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT,
                       0, 0, KEY_PAGEUP, KEY_PAGEDOWN,       KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_W};
// TODO this could be problemnatc due to vim hjkl motion

//L-9 - Brackets
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
	                      0, 0, 0, 0,     KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer1[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_LEFTBRACE, KEY_9, KEY_0, KEY_RIGHTBRACE,
                       KEY_U, KEY_F, KEY_C, KEY_D,       KEY_COMMA, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_DOT};

//L-10 - function
uint8_t modKeyLayer1[] = {    0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0
			};
uint8_t keyLayer1[] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4,       KEY_F5, KEY_F6, KEY_F7, KEY_F8,
                       KEY_F9, KEY_F10, KEY_F11, KEY_F12,       KEY_F13, KEY_F14, KEY_F15, KEY_F16};

//L-11 - CIRCUFIRENTIAL SYMBOLS
uint8_t modKeyLayer1[] = {
		     		  0, 0, 0, KEY_MOD_LSHIFT,     0, 0, KEY_MOD_LSHIFT, 0,
	             0, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0,     KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT
			};
uint8_t keyLayer1[] = {KEY_ESC KEY_TAB, KEY_PLUS, KEY_GRAVE,       KEY_SLASH, KEY_MINUS, KEY_ENTER, KEY_BACKSLASH,
                       KEY_U, KEY_F, KEY_PLUS, KEY_GRAVE,       KEY_COMMA, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_BACKSLASH};

//L-12 - WRITING SYMBOLS
uint8_t modKeyLayer1[] = {0, 0, 0, KEY_MOD_LSHIFT,     0, 0, 0, 0,
	                               0, 0, 0, 0,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT
			};
uint8_t keyLayer1[] = {KEY_ESC KEY_TAB, KEY_R, KEY_GRAVE,       KEY_MINUS, KEY_BACKSPACE, KEY_ENTER, KEY_BACKSLASH,
                       KEY_U, KEY_F, KEY_C, KEY_GRAVE,       KEY_1, KEY_SLASH, KEY_RIGHTBRACE, KEY_BACKSLASH};

//L-13 - WM (xmonad)
uint8_t modKeyLayer1[] = {KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT + KEY_MOD_LALT, KEY_MOD_LSHIFT,
	                  KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer1[] = {
			KEY_1 KEY_2, KEY_3, KEY_4,       KEY_H, KEY_BACKSPACE, KEY_ENTER, KEY_L,
                           0, KEY_5, KEY_6, KEY_7,       KEY_1, KEY_SLASH, KEY_ENTER, KEY_BACKSLASH};
//Layer reference
//testing another way with a more complicated fetching procedure to see if my first implementaiton is at fault:

uint8_t * testLayerRef[] = {&modKeyLayer1[0], &keyLayer1[0], &modKeyLayer2[0], &keyLayer2[0]};

//For some reason this:
//uint8_t ** layers[] = {&layer1[0]};
//Is not allowed
//So unless I can mess with the compiler
//I'll have to do it this way:

//Not sure why this doesn't work...
/*
uint8_t ** layers[NUMBER_OF_LAYERS];

void initLayers(void){
	layers[0] = &layer1[0];
	layers[1] = &layer2[0];
}
*/
#endif //KEYMAP_H
