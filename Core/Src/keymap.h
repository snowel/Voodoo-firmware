#define NUMBER_OF_LAYERS 2

//Layer 1

uint8_t modKeyLayer1[] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t keyLayer1[] = {0x0f, 0x12, 0x19, 0x08, 0x2c, 0x1c, 0x18, 0x05, 0x04, 0x05};
//uint8_t * layer1[] = {&modKeyLayer1[0], &keyLayer1[0]};

//Layer 2

uint8_t modKeyLayer2[] = {2, 0, 1, 0, 1, 23, 1, 23, 1, 23};
uint8_t keyLayer2[] = {0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05};
//uint8_t * layer2[] = {&modKeyLayer2[0], &keyLayer2[0]};

//Layer referecne

//testing another way with a more complicated fetching procedure to see if my first implementaiton is at fault:

uint8_t * testLayerRef[] = {&modKeyLayer1[0], &keyLayer1[0], &modKeyLayer2[0], &keyLayer2[0]};

//For some reason this:
//uint8_t ** layers[] = {&layer1[0]};
//Is not allowed
//So unlesss I can mess with the compiler
//I'll have to do it this way:

//Not sure why this doesn't work...
/*
uint8_t ** layers[NUMBER_OF_LAYERS];

void initLayers(void){
	layers[0] = &layer1[0];
	layers[1] = &layer2[0];
}
*/
