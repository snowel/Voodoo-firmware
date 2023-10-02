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

// 1 = none none - Typing 1/4
// 2 = none down - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 3 = none right - Typing 1/4 + Shifted
// 4 = none up - Prime Symbols
// 5 = none left - IMP SPACE
// 6 = down none - Typing 4/4
// 7 = down down - Modifiers
// 8 = down right - Typing 4/4 + Shifted
// 9 = down up - Number 2/2
// 10 = down left - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 11 = right none - Typing 2/4
// 12 = right down - Function Keys 1/2
// 13 = right right - Typing 2/4 + Shifted
// 14 = right up - Number Symbols
// 15 = right left - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 16 = up none - Arrow Keys
// 17 = up down -  Function Keys 2/2
// 18 = up right - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 19 = up up - Numbers (1,0) 1/2 + Edge Symbols
// 20 = up left - TODO: Mode swticher
// 21 = left none - Typing 3/4
// 22 = left down - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 23 = left right - Typing 3/4 + Shifted
// 24 = left up - Brackets
// 25 = left left - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ---- Layer numbers
// 1 = none none
// Typing 1/4
uint8_t impMod1 = 0;
uint8_t impKey1 = 0;
uint8_t modKeyLayer1[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer1[] = {KEY_S, KEY_A, KEY_T, KEY_H,       KEY_N, KEY_E, KEY_O, KEY_I,
                                       0, 0, 0, 0,     0, 0, 0, 0};

// REF
// s a t h   n e o i 

// 2 = none down
// FREE
uint8_t impMod2 = 0;
uint8_t impKey2 = 0;
uint8_t modKeyLayer2[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer2[] = {0, 0, 0, 0,     0, 0, 0, 0,
					   0, 0, 0, 0,     0, 0, 0, 0};

// 3 = none right
// Typing 1/4 Shifted
uint8_t impMod3 = 0;
uint8_t impKey3 = 0;
uint8_t modKeyLayer3[] = {KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
							                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer3[] = {KEY_S, KEY_A, KEY_T, KEY_H,       KEY_N, KEY_E, KEY_O, KEY_I,
                                        0, 0, 0, 0,     0, 0, 0, 0};
// REF
// S A T H   N E O I

// 4 = none up
// Prime Symbols
uint8_t impMod4 = 0; 
uint8_t impKey4 = 0x0;
uint8_t modKeyLayer4[] = {0, 0, 0, KEY_MOD_LSHIFT,     0, 0, KEY_MOD_LSHIFT, 0,
	                      0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer4[] = {KEY_A, KEY_S, KEY_MINUS, KEY_ESC,       KEY_SEMICOLON, KEY_EQUAL, KEY_EQUAL, KEY_O,
        				 0, 0, 0, 0,     0, 0, 0, 0};

// REF
//
// [?] [?] _ esc   ; = + [?]

// 5 = none left
// IMPL SPACE
uint8_t impMod5 = 0;
uint8_t impKey5 = KEY_SPACE;
uint8_t modKeyLayer5[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        	          0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer5[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 6 = down none
// Typing 4/4
uint8_t impMod6 = 0;
uint8_t impKey6 = 0;
uint8_t modKeyLayer6[] = {0, 0, 0, 0,  0, 0, 0, 0,
			  0, 0, 0, 0,  0, 0, 0, 0};
uint8_t keyLayer6[] = {KEY_Z, KEY_MINUS, KEY_Q, KEY_J,       KEY_X, KEY_BACKSPACE, KEY_APOSTROPHE, KEY_ENTER,
                                           0, 0, 0, 0,       0, 0, 0, 0};

// 7 = down down
// Modifiers
uint8_t impMod7 = 0;
uint8_t impKey7 = 0;
uint8_t modKeyLayer7[] = {KEY_MOD_LMETA, KEY_MOD_LALT, KEY_MOD_LCTRL, KEY_MOD_LSHIFT,     KEY_MOD_RSHIFT, KEY_MOD_RCTRL, KEY_MOD_LALT, KEY_MOD_RMETA,
									  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer7[] ={0, 0, 0, 0,     0, 0, 0, 0,
                      0, 0, 0, 0,     0, 0, 0, 0};

// lmeta lalt lctrl lshift   rshift rctrl ralt rmeta

// 8 = down right
// Typing 4/4 Shifted
uint8_t impMod8 = 0;
uint8_t impKey8 = 0;
uint8_t modKeyLayer8[] =  {KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, 0, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
                                                                               0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer8[] = {KEY_Z, KEY_SLASH, KEY_Q, KEY_J,       KEY_X, KEY_TAB, KEY_APOSTROPHE, KEY_DELETE,
                                        0, 0, 0, 0,     0, 0, 0, 0};


// 9 = down up
// Numbers 2-9
uint8_t impMod9 = 0;
uint8_t impKey9 = 0;
uint8_t modKeyLayer9[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//{KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
//   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer9[] = {KEY_2, KEY_3, KEY_4, KEY_5,       KEY_6, KEY_7, KEY_8, KEY_9,
                                   0, 0, 0, KEY_1,       KEY_0, 0, 0, 0};
// 2 3 4 5   6 7 8 9

// 10 = down left
// FREE
uint8_t impMod10 = 0;
uint8_t impKey10 = KEY_SPACE;
uint8_t modKeyLayer10[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        	           0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer10[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 11 = right none
// Typing 2/4
uint8_t impMod11 = 0;
uint8_t impKey11 = 0;
uint8_t modKeyLayer11[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                   0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer11[] = {KEY_C, KEY_U, KEY_D, KEY_L,       KEY_R, KEY_W, KEY_G, KEY_COMMA,
                                         0, 0, 0, 0,     0, 0, 0, 0};
// REF
// c u d l   r w g ,

// 12 = right down
// FREE
uint8_t impMod12 = 0;
uint8_t impKey12 = 0;
uint8_t modKeyLayer12[] = {0, 0, 0, 0,     0, 0, 0, 0,
	       		           0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer12[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 13 = right right
// Typing 2/4 Shifted
uint8_t impMod13 = 0;
uint8_t impKey13 = 0;
uint8_t modKeyLayer13[] =  {KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
		                                                                        0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer13[] = {KEY_C, KEY_U, KEY_D, KEY_L,       KEY_R, KEY_W, KEY_G, KEY_COMMA,
                                        0, 0, 0, 0,     0, 0, 0, 0};

// 14 = right up
// Shifted base alpha 2
uint8_t impMod14 = KEY_MOD_LSHIFT;
uint8_t impKey14 = 0;
uint8_t modKeyLayer14[] =  {KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
		                                                                        0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer14[] = {KEY_6, KEY_2, KEY_3, KEY_1,       KEY_5, KEY_7, KEY_8, KEY_4,
                                        0, 0, 0, 0,     0, 0, 0, 0};
// ^ @ # !   % & * $

// 15 = right left
uint8_t impMod15 = 0;
uint8_t impKey15 = 0;
uint8_t modKeyLayer15[] = {0, 0, 0, 0,     0, 0, 0, 0,
	               	       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer15[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 16 = up none
// Arrow Keys
uint8_t impMod16 = 0;
uint8_t impKey16 = 0;
uint8_t modKeyLayer16[] = {KEY_MOD_LSHIFT, KEY_MOD_LCTRL, KEY_MOD_LMETA, KEY_MOD_LALT,    0, 0, 0, 0,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer16[] = {0, 0, 0, 0,       KEY_LEFT, KEY_DOWN, KEY_UP, KEY_RIGHT,
                        0, 0, 0, 0,       0, 0, 0, 0};
// 17 = up down
// FREE
uint8_t impMod17 = 0;
uint8_t impKey17 = 0;
uint8_t modKeyLayer17[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer17[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 18 = up right
// FREE
uint8_t impMod18 = 0;
uint8_t impKey18 = 0;
uint8_t modKeyLayer18[] = {0, 0, 0, 0,     0, 0, 0, 0,
	         	           0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer18[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 19 = up up
// Symbols
uint8_t impMod19 = 0;
uint8_t impKey19 = 0;
uint8_t modKeyLayer19[] = {0, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     0, 0, 0, KEY_MOD_LSHIFT,
        0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer19[] = {KEY_GRAVE, KEY_GRAVE, KEY_BACKSLASH, KEY_MINUS,       KEY_1, KEY_0, KEY_SLASH, KEY_BACKSLASH,
                            0, 0, 0, 0,      0, 0, 0, 0};


// 20 = up left
uint8_t impMod20 = 0;
uint8_t impKey20 = 0;
uint8_t modKeyLayer20[] = {0, 0, 0, 0,     0, 0, 0, 0,
	        			  0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer20[] = {0, 0, 0, 0,     0, 0, 0, 0,
                        0, 0, 0, 0,     0, 0, 0, 0};

// 21 = left none
// Typing 3/4
uint8_t impMod21 = 0;
uint8_t impKey21 = 0;
uint8_t modKeyLayer21[] = {0, 0, 0, 0,     0, 0, 0, 0,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer21[] = {KEY_F, KEY_K, KEY_P, KEY_M,       KEY_V, KEY_DOT, KEY_Y, KEY_B,
        0, 0, 0, 0,     0, 0, 0, 0};

// 22 = left down
// FREE
uint8_t impMod22 = 0;
uint8_t impKey22 = 0;
uint8_t modKeyLayer22[] =  {0, 0, 0, 0,     0, 0, 0, 0,
							0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer22[] = {0, 0, 0, 0,     0, 0, 0, 0,
                       0, 0, 0, 0,     0, 0, 0, 0};

// 23 = left right
// Typing 3/4 Shifted
uint8_t impMod23 = 0;
uint8_t impKey23 = 0;
uint8_t modKeyLayer23[] = {KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer23[] = {KEY_F, KEY_K, KEY_P, KEY_M,       KEY_V, KEY_1, KEY_Y, KEY_B,
        0, 0, 0, 0,     0, 0, 0, 0};

// 24 = left up
// Brackets
uint8_t impMod24 = 0;
uint8_t impKey24 = 0;
uint8_t modKeyLayer24[] = {KEY_MOD_LSHIFT, 0, 0, KEY_MOD_LSHIFT,     KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT, KEY_MOD_LSHIFT,
	                       0, 0, 0, 0,     0, 0, 0, 0};
uint8_t keyLayer24[] = {KEY_COMMA, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_DOT,       KEY_LEFTBRACE, KEY_9, KEY_0, KEY_RIGHTBRACE,
        0, 0, 0, 0,     0, 0, 0, 0};

// 25 = left left
// FREE
uint8_t impMod25 = 0;
uint8_t impKey25 = 0;
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

// REF
//   [split vert] [search] [create window] [dfdf]     [Leader] [prev window] [next window] [split horz]








































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
