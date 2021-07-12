/* gpioLib.h - GPIO API definitions header file */

/*
 * Copyright (c) 2019 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */



#ifndef __INCgpioLibH
#define __INCgpioLibH
#include "vxWorks.h"
#include "taskLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "sysLib.h"
#include <subsys/gpio/vxbGpioLib.h>

#define PINMODE_OUT		1
#define PINMODE_IN		0
#define OUTMODE_HIGH	1
#define OUTMODE_LOW		0

/*The only interface required right now to use the GPIO APIs*/
typedef struct gpioSetStruct
{
    UINT32 gpioNum;
    UINT32 val;
} gpioSetType;

extern int gpioSetVal(gpioSetType * gSet);
extern int gpioGetVal(gpioSetType * gSet);
extern int gpioSetDir(gpioSetType * gSet);
extern int gpioGetDir(gpioSetType * gSet);

#endif /* __INCgpioLibH */
