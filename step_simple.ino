#include <Wire.h>
#include "SPI.h"
#include "Adafruit_WS2801.h"
#include <Adafruit_LSM303_U.h>
#include <Adafruit_Sensor.h>

Adafruit_WS2801 strip = Adafruit_WS2801(25,10,9);

int LED_COUNT = 24;

int seqcount = 12;
int topseq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int botseq[] = {24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13};

void setup() {
 pinMode(7, OUTPUT);
 strip.begin();
 strip.show();
 
}

void loop() {
 hideAll();
 digitalWrite(7, HIGH); // turn the LED on (HIGH is the voltage level)
 delay(1500); // wait for a second
 digitalWrite(7, LOW); // turn the LED off by making the voltage LOW
 delay(1000);
 
// setLED((12*2)/2/2, Color(0, 0, 200));
 stepsimple() ;
 // Serial.println("strip changed");
}


void stepsimple() {
 int led;
 for(led = 0; led < seqcount; led++) {
    //setLED(topseq[led], Color(250, 50, 0));
    // setLED(botseq[led], Color(250, 50, 0));
    setLEDPair(topseq[led], Color(250, 50, 0));
    
    if(led > 0) {
    // setLED(topseq[led-1], Color(0, 0, 0));
    // setLED(botseq[led-1], Color(0, 0, 0));
     
     setLEDPair(topseq[led-1], Color(250, 50, 0));
    }
    
    strip.show();
    delay(2000);
 }
 
 setLED(topseq[seqcount-1], Color(0, 0, 0));
 setLED(botseq[seqcount-1], Color(0, 0, 0));
 
}

void setLEDPair(uint8_t led, uint32_t c) {
   setLED(led, c);
   setLED(led+(LED_COUNT/2), c);
}

void setLED(uint8_t led, uint32_t c) {
   strip.setPixelColor(led, c);
}

void hideAll(){
  Serial.print(strip.numPixels());
  for(int i = 0; i > strip.numPixels();i++){
    strip.setPixelColor(i,Color(0,0,0));
    Serial.print(i);
    Serial.print(Color(0,0,0):
}
  
  strip.show();
}

uint32_t Color(byte r, byte g, byte b) {
 uint32_t c;
 c = r;
 c <<= 8;
 c |= g;
 c <<= 8;
 c |= b;
 return c;
}
