# STMDomingoArkanoid
## Overview
DomingoArkanoid is a simple 2D action game for one player written in C++ for Windows.
The paddle can be controled by keyboard or accelerometer in STM32F407 Discovery.

## Description
DomingoArkanoid is containing paddle and ball with stable speed. Breakable tiles. Two levels of game, random set
of tiles. Possibility to use STM32F407 Discovery as keyboard (gamepad isn't working with SDL 1.0). 
Classic arkanoid, taste of childhood...

## Tools
CooCox CoIDE v1.7.8, 
Visual Studio 2015, 
SDL 1.0 

## Future improvements
Bonuses: revert paddle direction, change ball speed, shooting, lengthen or reduce length of paddle.
Rewrite project to SDL 2.0, to make it compatibile with gamepads.

## How to run
Unzip folder. Open main folder. Double click, Gra.exe.

## How to use accelerometer:
1. Take STM32F407VG and connect miniUSB to USB.
2. Open CooCox and flash program to STM.
3. Connect microUSB to USB.

## Attributions
Keyboard HID by Tilen Majerle. Source: http://stm32f4-discovery.net/

## License
MIT

## Credits
Project by:
Mateusz Byczkowski & Bartosz Dominiak

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Michał Fularz
