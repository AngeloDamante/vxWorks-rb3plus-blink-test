/* includes */

#include "vxWorks.h"
#include <unistd.h>
#include "../gpioLib/gpioLib.h"

#define PIN 16

void start() {

	/* Setting up pin */
	pinMode(PIN, OUT)
	
	for (int i = 0; i < 5; i++) {
		/* turning on pin */
		printf("\n\n On");
		gpioWrite(PIN, HIGH)
		sleep(3);
		
		/* turning off pin */
		printf("\n\n Off");
		gpioWrite(PIN, LOW)
		sleep(3);
	}

	gpioFree(PIN)
}
