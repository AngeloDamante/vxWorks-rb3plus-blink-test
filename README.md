# Blink Test for VxWorks on Raspberry 3B+
A simple script to blinking test for Raspberry Pi 3B+ on <a href="https://github.com/AngeloDamante/VxWorks_basics">VxWorks</a> RTOS. This project provides the development environment for writing DKM for VxWorks and interact with GPIO bus.

You will need to SD card (>= 8 GB, FAT32), UART cable, Raspberry 3B+ and resistor (220 ohm).
<p align=center>
    <img src="design/raspLed.png" />
</p>

## Requirements
```bash
- python3
- screen
- pyftpdlib
```

## Preparing
```
git clone https://github.com/AngeloDamante/vxWorks-rb3plus-blink-test.git
cd vxWorks-rb3plus-blink-test
chmod +x init.sh
./init
```

At this point, copy all files from SD_card directory to your partition of SD card. Insert the SD card on Raspberry 3B+ and connect UART cable to PC's USB port.

```
├── vxWorks-rb3plus-blink-test
    ├── SD_card         # For Target
    ├── SDK             # For Host
    └── modules         # dkm files by user
        ├── dkm.c
        ├── gpioLib.h
        └── gpioLib.c

```

# Let's Develop!
<p align=center>
    <img src="design/targetHost.png" width=400/>
</p>

## Host
The gpioLib.h provides the library to interact to GPIO bus. Must build this library to obtain gpioLib.o. The dkm.c is the DKM developed by the user.
```
cd vxWorks-rb3plus-blink-test

# Build modules
source SDK/toolkit/wind_sdk_env.linux
$CC -dkm modules/gpioLib.c -o modules/gpioLib.o
$CC -dkm modules/dkm.c -o modules/dkm.o

# Start FTP Session
sudo python3 -m pyftpdlib -p 21 -u target -P vxTarget -d modules/ &
```

## Target (Raspberry)
With lkup "gpio" commands, we can check the absence gpio methods in symbols' table.
```
-> netDevCreate("wrs", "192.168.1.11", 1)
-> cmd
[vxWorks *]# cd wrs
[vxWorks *]# ld "gpioLib.o"
[vxWorks *]# ld "dkm.o"
[vxWorks *]# C
-> sp start 
```

<p align=center>
    <img src="design/led_test.gif" width=200/>
</p>



## Authors
- <a href="https://github.com/AngeloDamante"> Angelo D'Amante </a>
- <a href="https://github.com/KevinMaggi"> Kevin Maggi </a>