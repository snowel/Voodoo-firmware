//struct for joystick states
typedef struct {
	int yAxis;
	int xAxis;
	uint8_t position; //1-North, 2-East, 3-South, 4-West
} joystick;

void categorizeJoy(joystick stick){
	int xVal = stick.xAxis;
	int yVal = stick.yAxis;


}
