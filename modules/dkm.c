/* includes */

#include "vxWorks.h"
#include <unistd.h>
#include "GPIOLib.h"

void start() {
	struct gpioSetStruct gpioPin;
	gpioPin.gpioNum = 16;
	
	/* Setting up pin */
	gpioPin.val = PINMODE_OUT;
	gpioSetDir(&gpioPin);
	
	for (int i = 0; i < 5; i++) {
		/* turning on pin */
		printf("\n\n On");
		gpioPin.val = OUTMODE_HIGH;
		gpioSetVal(&gpioPin);
		sleep(3);
		
		/* turning off pin */
		printf("\n\n Off");
		gpioPin.val = OUTMODE_LOW;
		gpioSetVal(&gpioPin);
		sleep(3);
	}
}
