| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK14012-LED-Matrix/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAK14012-LED-Matrix/actions) |
| -- | -- | -- |

# RAKwireless RGB Matrix library

Rakwireless RGB Matrix library to control the RAK14012 LED Matrix. This library is modified from Adafruit's NeoPixel library(V1.7.0) for the Arduino platform. 

_**See licence information in [License](#license)

[*RAKwireless RAK14012 LED Matrix*](https://store.rakwireless.com/products/led_matrix-rak14012)

# Documentation

* **[Product Repository](https://github.com/RAKWireless/RAK14012-LED-Matrix)** - Product repository for the RAKWireless RAK14012 LED-Matrix module.
* **[Documentation](https://docs.rakwireless.com/Product-Categories/WisBlock/RAK14012/Overview/)** - Documentation and Quick Start Guide for the RAK14012 LED-Matrix module.

# Installation

In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAK14012 LED-Matrix.    

In PlatformIO open PlatformIO Home, switch to libraries and search for RAK14012 LED-Matrix. 
Or install the library project depend by adding 

```log
lib_deps =
  rakwireless/RAK14012-LED-Matrix
```
into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAK14012-LED-Matrix folder into the library directory.    
In Arduino IDE this is usually <arduinosketchfolder>/libraries/    
In PlatformIO this is usually <user/.platformio/lib>     

# Usage

The library provides an interface class, which allows communication to the RGB Matrix over NZR. Check out the examples how to use the RGB Matrix.  

- [RAK14012_RGB_Matrix_Disco](./examples/RAK14012_RGB_Matrix_Disco) Light up the RGB mixed color screen as your Disco atmosphere light.
- [RAK14012_RGB_Matrix_RandomColor](./examples/RAK14012_RGB_Matrix_RandomColor) Light up the RGB mixed color screen using random colors.
- [RAK14012_RGB_Matrix_SevenColor](./examples/RAK14012_RGB_Matrix_SevenColor) Light up the RGB mixed color screen to display seven colors.
- [RAK14012_RGB_Matrix_SingleCycle](./examples/RAK14012_RGB_Matrix_SingleCycle) Light up the LED for a single cycle.
- [RAK14012_RGB_Matrix_Strand](./examples/RAK14012_RGB_Matrix_Strand) RGB Matrix Strand.

## This class provides the following methods:
**Notes: Because Class RAK_RGB_Matrix Inherits from Adafruit_NeoPixel class, all functions description below will apply to RAK_RGB_Matrix. Below is the important API** 

**RAK_RGB_Matrix pixels(uint16_t n, uint16_t p, neoPixelType t);**     
NeoPixel constructor when length, pin and pixel type are known at compile-time.
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| in     | n | Number of NeoPixels in strand. |
| in | p | Arduino pin number which will drive the NeoPixel data in. |
| in | t | Pixel type -- add together NEO_* constants defined in Adafruit_NeoPixel.h, for example NEO_GRB+NEO_KHZ800 for NeoPixels expecting an 800 KHz (vs 400 KHz) data stream with color bytes expressed in green, red, blue order per pixel. |

**void begin(void);**    
Configure NeoPixel pin for output.
Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**void updateLength(uint16_t n);**    
Change the length of a previously-declared Adafruit_NeoPixel strip object. Old data is deallocated and new data is cleared. Pin number and pixel format are unchanged.  

@note   This function is deprecated, here only for old projects that may still be calling it. New projects should instead use the 'new' keyword with the first constructor syntax (length, pin, type).

Parameters:    

| Direction | Name | Function                        |
| --------- | ---- | ------------------------------- |
| in        | n    | New length of strip, in pixels. |
| return    |      | none                            |

**void setPin(uint16_t p);**    
Set/change the NeoPixel output pin number. Previous pin, if any, is set to INPUT and the new pin is set to OUTPUT.

Parameters:    

| Direction | Name | Function                          |
| --------- | ---- | --------------------------------- |
| in        | p    | Arduino pin number (-1 = no pin). |
| return    |      | none                              |

**void updateType(neoPixelType t);**     
Change the pixel format of a previously-declared Adafruit_NeoPixel strip object. If format changes from one of the RGB variants to an RGBW variant (or RGBW to RGB), the old data will be deallocated and new data is cleared. Otherwise, the old data will remain in RAM and is not reordered to the new format, so it's advisable to follow up with clear().

@note   This function is deprecated, here only for old projects that may still be calling it. New projects should instead use the 'new' keyword with the first constructor syntax (length, pin, type).

Parameters:    

| Direction | Name | Function                                                     |
| --------- | ---- | ------------------------------------------------------------ |
| in        | t    | Pixel type -- add together NEO_* constants defined in Adafruit_NeoPixel.h, for example NEO_GRB+NEO_KHZ800 for NeoPixels expecting an 800 KHz (vs 400 KHz) data stream with color bytes expressed in green, red, blue order per pixel. |
| return    |      | none                                                         |

**void show(void);**     
Transmit pixel data in RAM to NeoPixels.

 @note   On most architectures, interrupts are temporarily disabled in order to achieve the correct NeoPixel signal timing. This means that the Arduino millis() and micros() functions, which require interrupts, will lose small intervals of time whenever this function is called (about 30 microseconds per RGB pixel, 40 for RGBW pixels). There's no easy fix for this, but a few specialized alternative or companion libraries exist that use very device-specific peripherals to work around it.

Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);**     
Set a pixel's color using separate red, green and blue components. If using RGBW pixels, white will be set to 0.

Parameters:    

| Direction | Name | Function                                            |
| --------- | ---- | --------------------------------------------------- |
| in        | n    | Pixel index, starting from 0.                       |
| in        | r    | Red brightness, 0 = minimum (off), 255 = maximum.   |
| in        | g    | Green brightness, 0 = minimum (off), 255 = maximum. |
| in        | b    | Blue brightness, 0 = minimum (off), 255 = maximum.  |
| return    |      | none                                                |

**void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);**    
Set a pixel's color using separate red, green, blue and white components (for RGBW NeoPixels only).

Parameters:    

| Direction | Name | Function                                                     |
| --------- | ---- | ------------------------------------------------------------ |
| in        | n    | Pixel index, starting from 0.                                |
| in        | r    | Red brightness, 0 = minimum (off), 255 = maximum.            |
| in        | g    | Green brightness, 0 = minimum (off), 255 = maximum.          |
| in        | b    | Blue brightness, 0 = minimum (off), 255 = maximum.           |
| in        | w    | White brightness, 0 = minimum (off), 255 = maximum, ignored if using RGB pixels. |
| return    |      | none                                                         |

**void fill(uint32_t c=0, uint16_t first=0, uint16_t count=0);**     
Fill all or part of the NeoPixel strip with a color.

Parameters:    

| Direction | Name  | Function                                                     |
| --------- | ----- | ------------------------------------------------------------ |
| in        | c     | 32-bit color value. Most significant byte is white (for RGBW pixels) or ignored (for RGB pixels), next is red, then green, and least significant byte is blue. If all arguments are unspecified, this will be 0 (off). |
| in        | first | Index of first pixel to fill, starting from 0. Must be in-bounds, no clipping is performed. 0 if unspecified. |
| in        | count | Number of pixels to fill, as a positive value. Passing 0 or leaving unspecified will fill to end of strip. |
| return    |       | none                                                         |

**uint32_t getPixelColor(uint16_t n) const;**     
Query the color of a previously-set pixel.

Parameters:    

| Direction | Name | Function                                                     |
| --------- | ---- | ------------------------------------------------------------ |
| in        | n    | Index of pixel to read (0 = first).                          |
| return    |      | 'Packed' 32-bit RGB or WRGB value. Most significant byte is white (for RGBW pixels) or 0 (for RGB pixels), next is red, then green,and least significant byte is blue. |

**void setBrightness(uint8_t b);**     
Adjust output brightness. Does not immediately affect what's currently displayed on the LEDs. The next call to show() will refresh the LEDs at this level.

 @note   This was intended for one-time use in one's setup() function, not as an animation effect in itself. Because of the way this library "pre-multiplies" LED colors in RAM, changing the brightness is often a "lossy" operation -- what you write to pixels isn't necessary the same as what you'll read back. Repeated brightness changes using this function exacerbate the problem. Smart programs therefore treat the strip as a write-only resource, maintaining their own state to render each frame of an animation, not relying on read-modify-write.

Parameters:    

| Direction | Name | Function                                            |
| --------- | ---- | --------------------------------------------------- |
| in        | b    | Brightness setting, 0=minimum (off), 255=brightest. |
| return    |      | none                                                |

**uint8_t getBrightness(void);**     
Retrieve the last-set brightness value for the strip.

Parameters:    

| Direction | Name | Function                                            |
| --------- | ---- | --------------------------------------------------- |
| return    |      | Brightness value: 0 = minimum (off), 255 = maximum. |

**void clear(void);**     
Fill the whole NeoPixel strip with 0 / black / off.

Parameters:    

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

## Support

- Platfrom
  - most AVR boards
  - NRF52
  - ESP8266/ESP32
  - RP2040
  - STM32



- RGB IC
  - WS2811
  - WS2812
  - WS2812B
  - SK6812



## Structure

The library structure is like below:

- example

- src
  - platform
  - Adafruit_NeoPixel.cpp
  - Adafruit_NeoPixel.h
  - Rak_RGB_Matrix.h
- keywords.txt
- library.json
- library.properties
- LICENSE.txt
- README.md

# License

This code is partly based on the Adafruit_NeoPixel library and following their requirements, here is the Adafruit README file:

# Adafruit NeoPixel Library [![Build Status](https://github.com/adafruit/Adafruit_NeoPixel/workflows/Arduino%20Library%20CI/badge.svg)](https://github.com/adafruit/Adafruit_NeoPixel/actions)[![Documentation](https://github.com/adafruit/ci-arduino/blob/master/assets/doxygen_badge.svg)](http://adafruit.github.io/Adafruit_NeoPixel/html/index.html)

Arduino library for controlling single-wire-based LED pixels and strip such as the [Adafruit 60 LED/meter Digital LED strip][strip], the [Adafruit FLORA RGB Smart Pixel][flora], the [Adafruit Breadboard-friendly RGB Smart Pixel][pixel], the [Adafruit NeoPixel Stick][stick], and the [Adafruit NeoPixel Shield][shield].

After downloading, rename folder to 'Adafruit_NeoPixel' and install in Arduino Libraries folder. Restart Arduino IDE, then open File->Sketchbook->Library->Adafruit_NeoPixel->strandtest sketch.

Compatibility notes: Port A is not supported on any AVR processors at this time

[flora]:  http://adafruit.com/products/1060
[strip]:  http://adafruit.com/products/1138
[pixel]:  http://adafruit.com/products/1312
[stick]:  http://adafruit.com/products/1426
[shield]: http://adafruit.com/products/1430

---

## Installation

### First Method

![image](https://user-images.githubusercontent.com/36513474/68967967-3e37f480-0803-11ea-91d9-601848c306ee.png)

1. In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries
1. Then the Library Manager will open and you will find a list of libraries that are already installed or ready for installation.
1. Then search for Neopixel strip using the search bar.
1. Click on the text area and then select the specific version and install it.

### Second Method

1. Navigate to the [Releases page](https://github.com/adafruit/Adafruit_NeoPixel/releases).
1. Download the latest release.
1. Extract the zip file
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

## Features

- ### Simple to use

  Controlling NeoPixels “from scratch” is quite a challenge, so we provide a library letting you focus on the fun and interesting bits.

- ### Give back

  The library is free; you don’t have to pay for anything. Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

- ### Supported Chipsets

  We have included code for the following chips - sometimes these break for exciting reasons that we can't control in which case please open an issue!

  - AVR ATmega and ATtiny (any 8-bit) - 8 MHz, 12 MHz and 16 MHz
  - Teensy 3.x and LC
  - Arduino Due
  - Arduino 101
  - ATSAMD21 (Arduino Zero/M0 and other SAMD21 boards) @ 48 MHz
  - ATSAMD51 @ 120 MHz
  - Adafruit STM32 Feather @ 120 MHz
  - ESP8266 any speed
  - ESP32 any speed
  - Nordic nRF52 (Adafruit Feather nRF52), nRF51 (micro:bit)
  - Infineon XMC1100 BootKit @ 32 MHz
  - Infineon XMC1100 2Go @ 32 MHz
  - Infineon XMC1300 BootKit  @ 32 MHz
  - Infineon XMC4700 RelaxKit, XMC4800 RelaxKit, XMC4800 IoT Amazon FreeRTOS Kit @ 144 MHz

  Check forks for other architectures not listed here!

- ### GNU Lesser General Public License

  Adafruit_NeoPixel is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

## Functions

- begin()
- updateLength()
- updateType()
- show()
- delay_ns()
- setPin()
- setPixelColor()
- fill()
- ColorHSV()
- getPixelColor()
- setBrightness()
- getBrightness()
- clear()
- gamma32()

## Examples

There are many examples implemented in this library. One of the examples is below. You can find other examples [here](https://github.com/adafruit/Adafruit_NeoPixel/tree/master/examples)

### Simple

```Cpp
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        6
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}
```

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell others about this library
- Contribute new protocols

Please read [CONTRIBUTING.md](https://github.com/adafruit/Adafruit_NeoPixel/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

### Roadmap

The PRIME DIRECTIVE is to maintain backward compatibility with existing Arduino sketches -- many are hosted elsewhere and don't track changes here, some are in print and can never be changed!

Please don't reformat code for the sake of reformatting code. The resulting large "visual diff" makes it impossible to untangle actual bug fixes from merely rearranged lines. (Exception for first item in wishlist below.)

Things I'd Like To Do But There's No Official Timeline So Please Don't Count On Any Of This Ever Being Canonical:

- For the show() function (with all the delicate pixel timing stuff), break out each architecture into separate source files rather than the current unmaintainable tangle of #ifdef statements!
- Please don't use updateLength() or updateType() in new code. They should not have been implemented this way (use the C++ 'new' operator with the regular constructor instead) and are only sticking around because of the Prime Directive. setPin() is OK for now though, it's a trick we can use to 'recycle' pixel memory across multiple strips.
- In the M0 and M4 code, use the hardware systick counter for bit timing rather than hand-tweaked NOPs (a temporary kludge at the time because I wasn't reading systick correctly). (As of 1.4.2, systick is used on M4 devices and it appears to be overclock-compatible. Not for M0 yet, which is why this item is still here.)
- As currently written, brightness scaling is still a "destructive" operation -- pixel values are altered in RAM and the original value as set can't be accurately read back, only approximated, which has been confusing and frustrating to users. It was done this way at the time because NeoPixel timing is strict, AVR microcontrollers (all we had at the time) are limited, and assembly language is hard. All the 32-bit architectures should have no problem handling nondestructive brightness scaling -- calculating each byte immediately before it's sent out the wire, maintaining the original set value in RAM -- the work just hasn't been done. There's a fair chance even the AVR code could manage it with some intense focus. (The DotStar library achieves nondestructive brightness scaling because it doesn't have to manage data timing so carefully...every architecture, even ATtiny, just takes whatever cycles it needs for the multiply/shift operations.)

## Credits

This library is written by Phil "Paint Your Dragon" Burgess for Adafruit Industries, with contributions by PJRC, Michael Miller and other members of the open source community.

## License

Adafruit_NeoPixel is free software: you can redistribute it and/or  modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Adafruit_NeoPixel is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the [GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.en.html) for more details.
You should have received a copy of the GNU Lesser General Public License along with NeoPixel.  If not, see [this](https://www.gnu.org/licenses/)
