/* includes */

#include "vxWorks.h"
#include <unistd.h>
#include "gpioLib.h"

void start() {
	struct gpioSetStruct gpioBus;
	gpioBus.gpioNum = 16;
	
	/* Setting up pin */
	gpioBus.val = PINMODE_OUT;
	gpioSetDir(&gpioBus);
	
	for (int i = 0; i < 5; i++) {
		/* turning on pin */
		printf("\n\n On");
		gpioBus.val = OUTMODE_HIGH;
		gpioSetVal(&gpioBus);
		sleep(3);
		
		/* turning off pin */
		printf("\n\n Off");
		gpioBus.val = OUTMODE_LOW;
		gpioSetVal(&gpioBus);
		sleep(3);
	}
}
