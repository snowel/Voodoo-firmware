#ifndef LAYER_UTIL_C
#define LAYER_UTIL_C

#include <stdint.h>
#include "joy_util.h"
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

#define DEFAULT_TRESH

typedef uint8_t joystate;

enum joyhandedness {
	RIGTH_JOY = 1,
	LEFT_JOY
};

// switch case with 25 cases

int bitmaskToLayer(uint8_t bitmask){
	switch (bitmask):
	case 0;
}

// Set byte

joystate* setJoystate(joystick* left, joystick* right, joystate* handle, uint32_t tresh){
	enum joydir leftDir = categorizeJoy(*left, tresh);
	enum joydir rightDir = categorizeJoy(*rigth, tresh);


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
		default:
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
		default:
		}

	return handle;

}
#endif //LAYER_UTILS_C
