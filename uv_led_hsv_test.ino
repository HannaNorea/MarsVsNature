#include <Wire.h>
#include "Adafruit_SI1145.h"

Adafruit_SI1145 uv = Adafruit_SI1145();

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 1

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
      Serial.begin(9600);
  
  Serial.println("Adafruit SI1145 test");
  
  if (! uv.begin()) {
    Serial.println("Didn't find Si1145");
    while (1);
  }
  
      FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
    
  	  //FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      
}

void loop() { 
  float trueUVindex = uv.readUV();
  // the index is multiplied by 100 so to get the
  // integer index, divide by 100!
  float UVindex = trueUVindex/100.0;  
  Serial.print("UV: ");  Serial.println(UVindex);
  Serial.print("Hue: ");  Serial.println(UVindex*1000);
  ledControl(UVindex*1000);
//hue, sat, val
//  for(int i=0; i<255; i++){
//    leds[0] = CHSV( i, 255, 255);
//    FastLED.show();
//    delay(500);
//  }
  
}

void ledControl(int UV){
  
  leds[0] = CHSV(UV, 255, 255);
  FastLED.show();
  delay(500);
}
