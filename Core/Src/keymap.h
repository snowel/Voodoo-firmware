#include <usb_hid_keys.sh>
#include "usb_hid_keys.h"
#ifndef KEYMAP_H
#define "KEYMAP_H"
#define NUMBER_OF_LAYERS 25


//Maps for 16 key no thumb cluster
// {0,1,2,3,   4,5,6,7
// 8,9,10,11, 12,13,14,15}
//
// bit 7 - 128 : left-left
// bit 6 - 64 : left-up
// bit 5 - 32 : left-rigth
// bit 4 - 16 : left-down
// bit 3 - 8 : right-left
// bit 2 - 4 : right-up
// bit 1 - 2 : right-right
// bit 0 - 1 : rigth-down

// 1 = none none - Base Alphas 1
// 2 = none down - Circumfirential Symbols i.e. `~+=\|/?-_[del][esc][tab]
// 3 = none right - Brackets [](){}<>
// 4 = none up - Shifted Alphas 1
// 5 = none left - !!Imp!! Space
// 6 = down none - Numbers + Mods
// 7 = down down - WM shortcuts
// 8 = down right
// 9 = down up - Shifted Numbers
// 10 = down left
// 11 = right none - Alphas 2
// 12 = right down
// 13 = right right
// 14 = right up - Shifted Alphas 2
// 15 = right left
// 16 = up none
// 17 = up down
// 18 = up right
// 19 = up up - Tmux Shortcuts
// 20 = up left
// 21 = left none - Arrowkeys
// 22 = left down
// 23 = left right
// 24 = left up
// 25 = left left

// ---- Layer numbers
// 1 = none none
//L1 - base alphas 1
uint8_t impMod1 = 0;
uint8_t impKey1 = 0;

uint8_t modKeyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer1[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_N, KEY_E, KEY_I, KEY_O,
                       KEY_U, KEY_F, KEY_C, KEY_D,       KEY_H, KEY_M, KEY_L, KEY_W};
// 2 = none down
// CIRCUFIRENTIAL SYMBOLS
uint8_t modKeyLayer2[] = {
		     		  0, 0, 0, KEY_MOD_LSHIFT,     0, 0, KEY_MOD_LSHIFT, 0,
	             0, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0,     KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT
			};
uint8_t keyLayer2[] = {KEY_ESC KEY_TAB, KEY_PLUS, KEY_GRAVE,       KEY_SLASH, KEY_MINUS, KEY_ENTER, KEY_BACKSLASH,
                       KEY_U, KEY_F, KEY_PLUS, KEY_GRAVE,       KEY_COMMA, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_BACKSLASH};
// 3 = none right
// Brackets
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
	                      0, 0, 0, 0,     KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer1[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_LEFTBRACE, KEY_9, KEY_0, KEY_RIGHTBRACE,
                       KEY_U, KEY_F, KEY_C, KEY_D,       KEY_COMMA, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_DOT};
// 4 = none up
//L4 - imp shift base alpha
uint8_t impMod4 = KEY_MOD_LSHIFT; // implicite shifted layers may be a problem for held keys
uint8_t impKey4 = 0x0;
uint8_t modKeyLayer4[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
/* or
 * uint8_t modKeyLayer4[] = {
		   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
		   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_SHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT};
 */
uint8_t keyLayer4[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_N, KEY_E, KEY_I, KEY_O,
                       KEY_U, KEY_F, KEY_C, KEY_D,       KEY_H, KEY_M, KEY_L, KEY_W};
// 5 = none left
//L5 - imp space
uint8_t impMod5 = 0;
uint8_t impKey5 = KEY_SPACE;
uint8_t modKeyLayer5[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer5[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 6 = down none
// nums + mod keys
uint8_t impMod16 = 0;
uint8_t impKey16 = 0;
uint8_t modKeyLayer16[] = {         0, 0, 0, 0,     0, 0, 0, 0,
KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, 0,     0, KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer16[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};
// 7 = down down
// WM (xmonad)
uint8_t impMod6 = 0;
uint8_t impKey6 = 0;
uint8_t modKeyLayer6[] = {
		          KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT + KEY_MOD_LALT, KEY_MOD_LSHIFT,
	              KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer6[] = {
			KEY_1, KEY_2, KEY_3, KEY_4,       KEY_H, KEY_BACKSPACE, KEY_ENTER, KEY_L,
                0, KEY_5, KEY_6, KEY_7,       KEY_1, KEY_SLASH, KEY_ENTER, KEY_BACKSLASH};

// 8 = down right
// WRITING SYMBOLS
uint8_t modKeyLayer12[] = {0, 0, 0, KEY_MOD_LSHIFT,     0, 0, 0, 0,
	                               0, 0, 0, 0,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT
			};
uint8_t keyLayer12[] = {KEY_ESC KEY_TAB, KEY_R, KEY_GRAVE,       KEY_MINUS, KEY_BACKSPACE, KEY_ENTER, KEY_BACKSLASH,
                       KEY_U, KEY_F, KEY_C, KEY_GRAVE,       KEY_1, KEY_SLASH, KEY_RIGHTBRACE, KEY_BACKSLASH};

// 9 = down up
// Number layer shifted
uint8_t modKeyLayer9[] = {
   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
   KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT,KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};
// 10 = down left
// 11 = right none
// Base Alphas 2
uint8_t impMod11 = 0;
uint8_t impKey11 = 0;
uint8_t modKeyLayer11[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer11[] = {KEY_Q, KEY_K, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                        KEY_Z, KEY_J, KEY_V, KEY_G,       KEY_M, KEY_COMMA, KEY_DOT, KEY_X};
// 12 = rigth down
// 13 = right right
// 14 = right up
// Shifted base alpha 2
uint8_t impMod14 = KEY_MOD_LSHIFT;
uint8_t impKey14 = 0;
uint8_t modKeyLayer14[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer14[] = {KEY_Q, KEY_K, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                        KEY_Z, KEY_J, KEY_V, KEY_G,       KEY_M, KEY_COMMA, KEY_DOT, KEY_X};
// 15 = right left
// 16 = up none
//L16 - nums + mod keys
uint8_t impMod16 = 0;
uint8_t impKey16 = 0;
uint8_t modKeyLayer16[] = {         0, 0, 0, 0,     0, 0, 0, 0,
KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, 0,     0, KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer16[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};
// 17 = up down
// 18 = up right
// 19 = up up
// TMUX
uint8_t impMod19 = 0;
uint8_t impKey19 = 0;
uint8_t modKeyLayer19[] = {
		          KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_LCTRL, 0, KEY_MOD_LSHIFT + KEY_MOD_LALT, KEY_MOD_LSHIFT,
	              KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer19[] = {
			KEY_1, KEY_2, KEY_3, KEY_4,       KEY_SPACE, KEY_N, KEY_ENTER, KEY_L,
                0, KEY_5, KEY_6, KEY_7,       KEY_1, KEY_SLASH, KEY_ENTER, KEY_BACKSLASH};
// Ref bindings
//   [split vert] [search] [create window] [dfdf]     [Leader] [prev window] [next window]
//
// 20 = up left
// 21 = left none
// Arrow keys et al.
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer1[] = {       0, KEY_ESC, KEY_HOME, KEY_END,       KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT,
                       0, 0, KEY_PAGEUP, KEY_PAGEDOWN,       KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_W};
// TODO this could be problemnatc due to vim hjkl motion
// 22 = left down
// Total mod key layer
uint8_t modKeyLayer1[] = {
KEY_MOD_LCTRL, KEY_MOD_LMETA, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_RSHIFT,KEY_MOD_RALT, KEY_MOD_RMETA, KEY_MOD_RCTRL,
KEY_MOD_RCTRL, KEY_MOD_RMETA, KEY_MOD_RALT, KEY_MOD_RSHIFT,     KEY_MOD_LSHIFT,KEY_MOD_LALT, KEY_MOD_LMETA, KEY_MOD_LCTRL};
uint8_t keyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 23 = left right
// 24 = left up
// Function 1-16
uint8_t modKeyLayer1[] = {    0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0
			};
uint8_t keyLayer1[] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4,       KEY_F5, KEY_F6, KEY_F7, KEY_F8,
                       KEY_F9, KEY_F10, KEY_F11, KEY_F12,       KEY_F13, KEY_F14, KEY_F15, KEY_F16};
// 25 = left left





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
