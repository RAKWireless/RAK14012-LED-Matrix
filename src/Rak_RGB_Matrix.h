/*!
 * @file Rak_RGB_Matrix.h
 *
 * This is part of Rakwireless RGB Matrix library is based on Adafruit's 
 * NeoPixel library for the Arduino platform, allowing a broad range of 
 * microcontroller boards (most AVR boards,many ARM devices, ESP8266 and
 *  ESP32, among others) to control Adafruit NeoPixels, FLORA RGB Smart 
 * Pixels and compatible devices -- WS2811,WS2812, WS2812B, SK6812, etc.
 *
 */

#ifndef RAK_RGB_MATRIX_H
#define RAK_RGB_MATRIX_H

#include "Adafruit_NeoPixel.h"

class RAK_RGB_Matrix : public Adafruit_NeoPixel
{
  public:
  RAK_RGB_Matrix(uint16_t n, uint16_t pin, neoPixelType type) : Adafruit_NeoPixel(n, pin, type){};
  RAK_RGB_Matrix(void) : Adafruit_NeoPixel(){};
  ~RAK_RGB_Matrix(){};
};

#endif 
