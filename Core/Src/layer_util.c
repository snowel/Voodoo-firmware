

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

#define RIGTH_JOY_LEFT 0x08
#define RIGTH_JOY_UP 0x04
#define RIGTH_JOY_RIGHT 0x02
#define RIGTH_JOY_DOWN 0x01

// switch case with 25 cases

int bitmaskToLayer(uint8_t bitmask){
	swtich bitmask:
	case 0
}
