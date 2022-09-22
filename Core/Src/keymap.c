#include "keymap.h"
#include <stdint.h>
// Maps for 16 key no thumb cluster
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
uint8_t impMod2 = 0;
uint8_t impKey2 = 0;
uint8_t modKeyLayer2[] = {
		     		  0, 0, 0, KEY_MOD_LSHIFT,     0, 0, KEY_MOD_LSHIFT, 0,
	             0, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0,     KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT
			};
uint8_t keyLayer2[] = {KEY_Z, KEY_TAB, KEY_EQUAL, KEY_GRAVE,       KEY_SLASH, KEY_MINUS, KEY_ENTER, KEY_BACKSLASH,
                       KEY_U, KEY_F, KEY_EQUAL, KEY_GRAVE,       KEY_COMMA, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_BACKSLASH};

// 3 = none right
// Brackets
uint8_t impMod3 = 0;
uint8_t impKey3 = 0;
uint8_t modKeyLayer3[] = {0, 0, 0, 0,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
	                      0, 0, 0, 0,     KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer3[] = {KEY_A, KEY_S, KEY_R, KEY_T,       KEY_LEFTBRACE, KEY_9, KEY_0, KEY_RIGHTBRACE,
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
//imp space
//L5 - imp space
uint8_t impMod5 = 0;
uint8_t impKey5 = KEY_SPACE;
uint8_t modKeyLayer5[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        	          0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer5[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 6 = down none
// nums + mod keys
uint8_t impMod6 = 0;
uint8_t impKey6 = 0;
uint8_t modKeyLayer6[] = {             0, 0, 0, 0,     0, 0, 0, 0,
   KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, 0,     0, KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer6[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};

// could swap 5 and 1, 6 and 0

// 7 = down down
// WM (xmonad)
uint8_t impMod7 = 0;
uint8_t impKey7 = 0;
uint8_t modKeyLayer7[] = {
		          KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT,     KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT + KEY_MOD_LALT, KEY_MOD_LSHIFT,
	            KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LALT, KEY_MOD_LALT,     KEY_MOD_LALT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT};
uint8_t keyLayer7[] = {
			KEY_1, KEY_2, KEY_3, KEY_4,       KEY_H, KEY_BACKSPACE, KEY_ENTER, KEY_L,
                0, KEY_5, KEY_6, KEY_7,       KEY_P, KEY_SLASH, KEY_ENTER, KEY_BACKSLASH};

// REF
//                     [wksp 1] [wksp 2] [wkps 3] [wksp 4]
//                     [move window + wksp]                     [dmenu]

// 8 = down right
// WRITING SYMBOLS
uint8_t impMod8 = 0;
uint8_t impKey8 = 0;
uint8_t modKeyLayer8[] = {0, 0, 0, KEY_MOD_LSHIFT,     0, 0, 0, 0,
	                               0, 0, 0, 0,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT
			};
uint8_t keyLayer8[] = {KEY_ESC, KEY_TAB, KEY_R, KEY_GRAVE,       KEY_MINUS, KEY_BACKSPACE, KEY_ENTER, KEY_BACKSLASH,
                           KEY_U, KEY_F, KEY_C, KEY_GRAVE,       KEY_1, KEY_SLASH, KEY_RIGHTBRACE, KEY_BACKSLASH};

// 9 = down up
// Number layer shifted
uint8_t impMod9 = 0;
uint8_t impKey9 = 0;
uint8_t modKeyLayer9[] = {
   KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
   KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT,KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer9[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};
// 10 = down left
uint8_t impMod10 = 0;
uint8_t impKey10 = KEY_SPACE;
uint8_t modKeyLayer10[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        	   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer10[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 11 = right none
// Base Alphas 2
uint8_t impMod11 = 0;
uint8_t impKey11 = 0;
uint8_t modKeyLayer11[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer11[] = {KEY_Q, KEY_K, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                        KEY_Z, KEY_J, KEY_V, KEY_G,       KEY_M, KEY_COMMA, KEY_DOT, KEY_X};
// 12 = rigth down
uint8_t impMod12 = 0;
uint8_t impKey12 = 0;
uint8_t modKeyLayer12[] = {0, 0, 0, 0,     0, 0, 0, 0,
	       		   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer12[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 13 = right right
uint8_t impMod13 = 0;
uint8_t impKey13 = 0;
uint8_t modKeyLayer13[] = {0, 0, 0, 0,     0, 0, 0, 0,
	       		   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer13[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 14 = right up
// Shifted base alpha 2
uint8_t impMod14 = KEY_MOD_LSHIFT;
uint8_t impKey14 = 0;
uint8_t modKeyLayer14[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer14[] = {KEY_Q, KEY_K, KEY_Y, KEY_B,       KEY_P, KEY_SEMICOLON, KEY_APOSTROPHE, KEY_BACKSPACE,
                        KEY_Z, KEY_J, KEY_V, KEY_G,       KEY_M, KEY_COMMA, KEY_DOT, KEY_X};
// 15 = right left
uint8_t impMod15 = 0;
uint8_t impKey15 = KEY_SPACE;
uint8_t modKeyLayer15[] = {0, 0, 0, 0,     0, 0, 0, 0,
	               	   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer15[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 16 = up none
//L16 - nums + mod keys
uint8_t impMod16 = 0;
uint8_t impKey16 = 0;
uint8_t modKeyLayer16[] = {         0, 0, 0, 0,     0, 0, 0, 0,
KEY_MOD_LCTRL, KEY_MOD_LSHIFT, KEY_MOD_LALT, 0,     0, KEY_MOD_LALT, KEY_MOD_LSHIFT, KEY_MOD_LCTRL};
uint8_t keyLayer16[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                    0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};
// 17 = up down
uint8_t impMod17 = 0;
uint8_t impKey17 = KEY_SPACE;
uint8_t modKeyLayer17[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer17[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 18 = up right
uint8_t impMod18 = 0;
uint8_t impKey18 = KEY_SPACE;
uint8_t modKeyLayer18[] = {0, 0, 0, 0,     0, 0, 0, 0,
	         	   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer18[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

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
//   [split vert] [search] [create window] [dfdf]     [Leader] [prev window] [next window] [split horz]
//                                      [del win]      [move] [move] [move] [move]

// 20 = up left
uint8_t impMod20 = 0;
uint8_t impKey20 = 0;
uint8_t modKeyLayer20[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer20[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 21 = left none
// Arrow keys et al.
uint8_t impMod21 = 0;
uint8_t impKey21 = 0;
uint8_t modKeyLayer21[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer21[] = {       0, KEY_ESC, KEY_HOME, KEY_END,       KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT,
                       0, 0, KEY_PAGEUP, KEY_PAGEDOWN,       KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_W};
// TODO this could be problemnatc due to vim hjkl motion
// 22 = left down
// Total mod key layer
uint8_t impMod22 = 0;
uint8_t impKey22 = 0;
uint8_t modKeyLayer22[] = {
KEY_MOD_LCTRL, KEY_MOD_LMETA, KEY_MOD_LALT, KEY_MOD_LSHIFT,     KEY_MOD_RSHIFT,KEY_MOD_RALT, KEY_MOD_RMETA, KEY_MOD_RCTRL,
KEY_MOD_RCTRL, KEY_MOD_RMETA, KEY_MOD_RALT, KEY_MOD_RSHIFT,     KEY_MOD_LSHIFT,KEY_MOD_LALT, KEY_MOD_LMETA, KEY_MOD_LCTRL};
uint8_t keyLayer22[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 23 = left right
uint8_t impMod23 = 0;
uint8_t impKey23 = KEY_SPACE;
uint8_t modKeyLayer23[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer23[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 24 = left up
// Function 1-16
uint8_t impMod24 = 0;
uint8_t impKey24 = 0;
uint8_t modKeyLayer24[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer24[] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4,       KEY_F5, KEY_F6, KEY_F7, KEY_F8,
                       KEY_F9, KEY_F10, KEY_F11, KEY_F12,       KEY_F13, KEY_F14, KEY_F15, KEY_F16};
// 25 = left left
uint8_t impMod25 = 0;
uint8_t impKey25 = KEY_SPACE;
uint8_t modKeyLayer25[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer25[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

Layer layer1 = {&impMod1, &impKey1, &modKeyLayer1[0], &keyLayer1[0], 1};
Layer layer2 = {&impMod2, &impKey2, &modKeyLayer2[0], &keyLayer2[0], 2};
Layer layer3 = {&impMod3, &impKey3, &modKeyLayer3[0], &keyLayer3[0], 3};
Layer layer4 = {&impMod4, &impKey4, &modKeyLayer4[0], &keyLayer4[0], 4};
Layer layer5 = {&impMod5, &impKey5, &modKeyLayer5[0], &keyLayer5[0], 5};
Layer layer6 = {&impMod6, &impKey6, &modKeyLayer6[0], &keyLayer6[0], 6};
Layer layer7 = {&impMod7, &impKey7, &modKeyLayer7[0], &keyLayer7[0], 7};
Layer layer8 = {&impMod8, &impKey8, &modKeyLayer8[0], &keyLayer8[0], 8};
Layer layer9 = {&impMod9, &impKey9, &modKeyLayer9[0], &keyLayer9[0], 9};
Layer layer10 = {&impMod10, &impKey10, &modKeyLayer10[0], &keyLayer10[0], 10};
Layer layer11 = {&impMod11, &impKey11, &modKeyLayer11[0], &keyLayer11[0], 11};
Layer layer12 = {&impMod12, &impKey12, &modKeyLayer12[0], &keyLayer12[0], 12};
Layer layer13 = {&impMod13, &impKey13, &modKeyLayer13[0], &keyLayer13[0], 13};
Layer layer14 = {&impMod14, &impKey14, &modKeyLayer14[0], &keyLayer14[0], 14};
Layer layer15 = {&impMod15, &impKey15, &modKeyLayer15[0], &keyLayer15[0], 15};
Layer layer16 = {&impMod16, &impKey16, &modKeyLayer16[0], &keyLayer16[0], 16};
Layer layer17 = {&impMod17, &impKey17, &modKeyLayer17[0], &keyLayer17[0], 17};
Layer layer18 = {&impMod18, &impKey18, &modKeyLayer18[0], &keyLayer18[0], 18};
Layer layer19 = {&impMod19, &impKey19, &modKeyLayer19[0], &keyLayer19[0], 19};
Layer layer20 = {&impMod20, &impKey20, &modKeyLayer20[0], &keyLayer20[0], 20};
Layer layer21 = {&impMod21, &impKey21, &modKeyLayer21[0], &keyLayer21[0], 21};
Layer layer22 = {&impMod22, &impKey22, &modKeyLayer22[0], &keyLayer22[0], 22};
Layer layer23 = {&impMod23, &impKey23, &modKeyLayer23[0], &keyLayer23[0], 23};
Layer layer24 = {&impMod24, &impKey24, &modKeyLayer24[0], &keyLayer24[0], 24};
Layer layer25 = {&impMod25, &impKey25, &modKeyLayer25[0], &keyLayer25[0], 25};

Layer BuffLayer; //This is to have layers 1 indexed

const Layer* keymap[] = {&BuffLayer, &layer1, &layer2, &layer3, &layer4, &layer5, &layer6, &layer7, &layer8, &layer9, &layer1, &layer11, &layer12, &layer13, &layer14, &layer15, &layer16, &layer17, &layer18, &layer19, &layer20, &layer21, &layer22, &layer23, &layer24, &layer25};





//Layer reference
//testing another way with a more complicated fetching procedure to see if my first implementaiton is at fault:

uint8_t * testLayerRef[] = {&modKeyLayer1[0], &keyLayer1[0], &modKeyLayer2[0], &keyLayer2[0]};

// Full reference, single array

uint8_t * FullLayerRef[] = {&impMod1, &impKey1, &modKeyLayer1[0], &keyLayer1[0], &impMod2, &impKey2, &modKeyLayer2[0], &keyLayer2[0], &impMod3, &impKey3, &modKeyLayer3[0], &keyLayer3[0], &impMod4, &impKey4, &modKeyLayer4[0], &keyLayer4[0], &impMod5, &impKey5, &modKeyLayer5[0], &keyLayer5[0], &impMod6, &impKey6, &modKeyLayer6[0], &keyLayer6[0], &impMod7, &impKey7, &modKeyLayer7[0], &keyLayer7[0], &impMod8, &impKey8, &modKeyLayer8[0], &keyLayer8[0], &impMod9, &impKey9, &modKeyLayer9[0], &keyLayer9[0], &impMod10, &impKey10, &modKeyLayer10[0], &keyLayer10[0], &impMod11, &impKey11, &modKeyLayer11[0], &keyLayer11[0], &impMod12, &impKey12, &modKeyLayer12[0], &keyLayer12[0], &impMod13, &impKey13, &modKeyLayer13[0], &keyLayer13[0], &impMod14, &impKey14, &modKeyLayer14[0], &keyLayer14[0], &impMod15, &impKey15, &modKeyLayer15[0], &keyLayer15[0], &impMod16, &impKey16, &modKeyLayer16[0], &keyLayer16[0], &impMod17, &impKey17, &modKeyLayer17[0], &keyLayer17[0], &impMod18, &impKey18, &modKeyLayer18[0], &keyLayer18[0], &impMod19, &impKey19, &modKeyLayer19[0], &keyLayer19[0], &impMod20, &impKey20, &modKeyLayer20[0], &keyLayer20[0], &impMod21, &impKey21, &modKeyLayer21[0], &keyLayer21[0], &impMod22, &impKey22, &modKeyLayer22[0], &keyLayer22[0], &impMod23, &impKey23, &modKeyLayer23[0], &keyLayer23[0], &impMod24, &impKey24, &modKeyLayer24[0], &keyLayer24[0], &impMod25, &impKey25, &modKeyLayer25[0], &keyLayer25[0]};
// Useful format for other management

/*

uint8_t * testLayerRef[] = {&impMod1, &impKey1, &modKeyLayer1[0], &keyLayer1[0]};
uint8_t * testLayerRef[] = {&impMod2, &impKey2, &modKeyLayer2[0], &keyLayer2[0]};
uint8_t * testLayerRef[] = {&impMod3, &impKey3, &modKeyLayer3[0], &keyLayer3[0]};
uint8_t * testLayerRef[] = {&impMod4, &impKey4, &modKeyLayer4[0], &keyLayer4[0]};
uint8_t * testLayerRef[] = {&impMod5, &impKey5, &modKeyLayer5[0], &keyLayer5[0]};
uint8_t * testLayerRef[] = {&impMod6, &impKey6, &modKeyLayer6[0], &keyLayer6[0]};
uint8_t * testLayerRef[] = {&impMod7, &impKey7, &modKeyLayer7[0], &keyLayer7[0]};
uint8_t * testLayerRef[] = {&impMod8, &impKey8, &modKeyLayer8[0], &keyLayer8[0]};
uint8_t * testLayerRef[] = {&impMod9, &impKey9, &modKeyLayer9[0], &keyLayer9[0]};
uint8_t * testLayerRef[] = {&impMod10, &impKey10, &modKeyLayer10[0], &keyLayer10[0]};
uint8_t * testLayerRef[] = {&impMod11, &impKey11, &modKeyLayer11[0], &keyLayer11[0]};
uint8_t * testLayerRef[] = {&impMod12, &impKey12, &modKeyLayer12[0], &keyLayer12[0]};
uint8_t * testLayerRef[] = {&impMod13, &impKey13, &modKeyLayer13[0], &keyLayer13[0]};
uint8_t * testLayerRef[] = {&impMod14, &impKey14, &modKeyLayer14[0], &keyLayer14[0]};
uint8_t * testLayerRef[] = {&impMod15, &impKey15, &modKeyLayer15[0], &keyLayer15[0]};
uint8_t * testLayerRef[] = {&impMod16, &impKey16, &modKeyLayer16[0], &keyLayer16[0]};
uint8_t * testLayerRef[] = {&impMod17, &impKey17, &modKeyLayer17[0], &keyLayer17[0]};
uint8_t * testLayerRef[] = {&impMod18, &impKey18, &modKeyLayer18[0], &keyLayer18[0]};
uint8_t * testLayerRef[] = {&impMod19, &impKey19, &modKeyLayer19[0], &keyLayer19[0]};
uint8_t * testLayerRef[] = {&impMod20, &impKey20, &modKeyLayer20[0], &keyLayer20[0]};
uint8_t * testLayerRef[] = {&impMod21, &impKey21, &modKeyLayer21[0], &keyLayer21[0]};
uint8_t * testLayerRef[] = {&impMod22, &impKey22, &modKeyLayer22[0], &keyLayer22[0]};
uint8_t * testLayerRef[] = {&impMod23, &impKey23, &modKeyLayer23[0], &keyLayer23[0]};
uint8_t * testLayerRef[] = {&impMod24, &impKey24, &modKeyLayer24[0], &keyLayer24[0]};
uint8_t * testLayerRef[] = {&impMod25, &impKey25, &modKeyLayer25[0], &keyLayer25[0]};
*/










































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
