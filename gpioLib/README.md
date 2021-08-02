# gpioLib documentation #

The library consists of a 4 macros and 4 functions:
* Macros:
  * ```OUT```: it's the value to set a pin to output mode;
  * ```IN```: it's the value to set a pin to input mode;
  * ```HIGH```: it's the value to set an output pin to high tension value;
  * ```LOW```: it's the value to set an output pin to low tension value;
* Functions: they are simply wrappers for vxbGpioLib's functions, but easier to use
  * ```gpioWrite(UINT32 pinGpioNum, UINT32 value)```: it's the function to set an output pin to a value;
  * ```gpioRead(UINT32 pinGpioNum)```: it's the function to get an input pin's value;
  * ```pinMode(UINT32 pinGpioNum, UINT32 mode)```: it's the function to set a pin to input or output mode;
  * ```gpioFree(UINT32 pinGpioNum)```: it's the function to clear a pin's tension;

## Pinout Scheme ##
<p align=center>
    <img src="../design/pinout_rasp.png" width=400/>
</p>

## How to ##
### "Write" to a pin ###
```c
pinMode(PIN, OUT)
gpioWrite(PIN, HIGH)
gpioWrite(PIN, LOW)
gpioFree(PIN)
```
### "Read" a pin ###
```c
pinMode(PIN, IN)
int value = gpioRead(PIN)
gpioFree(PIN)
```

____
This library is inspired by the gpiolib included in the examples of WindRiver's VxWorks SDK and modified by us according to our need.
