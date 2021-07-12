/* gpioLib.c - Library functions for basic GPIO manipulation in VxWorks */

/*
 Copyright (c) 2019 Wind River Systems, Inc.
 The right to copy, distribute, modify or otherwise make use
 of this software may be licensed only pursuant to the terms
 of an applicable Wind River license agreement.
 */

/*
 DESCRIPTION

 Basic GPIO manipulation API in VxWorks.  

 */

#include <vxWorks.h>
#include <taskLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysLib.h>
#include <subsys/gpio/vxbGpioLib.h>
#include "gpioLib.h"


/*******************************************************************************
 * 
 * gpioSetVal - Set the value of the specified pin
 * 
 * Set the value of the GPIO pin
 * 
 * RETURNS: void
 * 
 */
int gpioSetVal(gpioSetType* gSet)
{
    return (vxbGpioSetValue(gSet->gpioNum, gSet->val));
}

/*******************************************************************************
 * 
 * gpioGetVal - Return the value of the specified pin
 * 
 * Get the value of the GPIO pin
 * 
 * RETURNS: void
 * 
 */
int gpioGetVal(gpioSetType* gSet)
{
    gSet->val = vxbGpioGetValue(gSet->gpioNum);
    return OK;
}

/*******************************************************************************
 * 
 * gpioSetDir - Set the direction of the specified pin
 * 
 * Set the direction, input or output, of the GPIO pin
 * 
 * RETURNS: OK
 * 
 */
int gpioSetDir(gpioSetType* gSet)
{
    return (vxbGpioSetDir(gSet->gpioNum, gSet->val));
}

/*******************************************************************************
 * 
 * gpioGetDir - Return the direction of the specified pin
 * 
 * Get the direction, input or output, of the GPIO pin
 * 
 * RETURNS: direction of the pin 
 * 
 */
int gpioGetDir(gpioSetType * gSet)
{
    gSet->val = vxbGpioGetDir(gSet->gpioNum);
    return OK;
}
