| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK14012-LED-Matrix/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAK14012-LED-Matrix/actions) |
| -- | -- | -- |

# RAKwireless RGB Matrix library

Rakwireless RGB Matrix library to control the RAK14012 LED Matrix. This library is modified from Adafruit's NeoPixel library(V1.7.0) for the Arduino platform.. 

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
