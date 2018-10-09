
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

#include "Winchy.h"
#include <US.h>
#include <Adafruit_NeoPixel.h>

//-- Constants
#define PIN_LedWS	D9
#define PIN_Trigger D10
#define PIN_Echo    D8
#define PIN_TemperatureSensor	A0
#define PIN_leftWheel	D1
#define PIN_rightWheel	D2
#define NUMPIXELS 6

Winchy::Winchy()
{
	Winchy::init();
}

void Winchy::init() {

  // Initialize and turn leds off because of Serial
  _pixels = Adafruit_NeoPixel(NUMPIXELS, PIN_LedWS, NEO_GRB + NEO_KHZ800);
  _pixels.begin();
  for (int i=0; i<NUMPIXELS; i++) 
	turnPixelOff(i);

  // Initialize servos
  attachServos();
  _leftWheel.write(90);
  _rightWheel.write(90);
  
  // US sensor init with the pins:
  _us.init(PIN_Trigger, PIN_Echo);

}


///////////////////////////////////////////////////////////////////
//-- ATTACH & DETACH FUNCTIONS ----------------------------------//
///////////////////////////////////////////////////////////////////

void Winchy::attachServos(){
	
  _leftWheel.attach(PIN_leftWheel);
  _rightWheel.attach(PIN_rightWheel);
  
}

void Winchy::detachServos(){
	
  _leftWheel.detach();
  _rightWheel.detach();
  
}


///////////////////////////////////////////////////////////////////
//-- Predetermined Movement--------------------------------------//
///////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//-- Winchy forward: moves forward
//---------------------------------------------------------
void Winchy::forward(){
	
  _leftWheel.write(180);
  _rightWheel.write(0);

}

//---------------------------------------------------------
//-- Winchy backward: moves backward
//---------------------------------------------------------
void Winchy::backward(){
	
  _leftWheel.write(0);
  _rightWheel.write(180);
  
}

//---------------------------------------------------------
//-- Winchy left: turns left moving 1 wheel
//---------------------------------------------------------
void Winchy::left(){
	
  _leftWheel.write(90); 
  _rightWheel.write(0);
  
}

//---------------------------------------------------------
//-- Winchy left2: turns left moving 2 wheels
//---------------------------------------------------------
void Winchy::left2(){
	
  _leftWheel.write(0); 
  _rightWheel.write(0);
  
}

//---------------------------------------------------------
//-- Winchy right: turns right moving 1 wheel
//---------------------------------------------------------
void Winchy::right(){
	
  _leftWheel.write(180);
  _rightWheel.write(90);
  
}

//---------------------------------------------------------
//-- Winchy right2: turns right moving 2 wheels
//---------------------------------------------------------
void Winchy::right2(){
	
  _leftWheel.write(180);
  _rightWheel.write(180);
  
}

//---------------------------------------------------------
//-- Winchy myStop: stops
//---------------------------------------------------------
void Winchy::myStop(){
	
  _leftWheel.write(90);
  _rightWheel.write(90);
  
}


///////////////////////////////////////////////////////////////////
//-- WS2818b LEDs -----------------------------------------------//
///////////////////////////////////////////////////////////////////
/*
         * Set the color of a pixel.
         * Params:
         * pos		which led starting from 0
		 * r		red value (0-255)
		 * g		green value (0-255)
		 * b		blue value (0-255)
         */
void Winchy::turnPixelOn(uint16_t pos, uint8_t r, uint8_t g, uint8_t b){
	
  _pixels.setPixelColor(pos, _pixels.Color(r,g,b));
  _pixels.show();

}

/*
         * Turns off a pixel
         * Params:
         * pos		which led starting from 0
         */
void Winchy::turnPixelOff(uint16_t pos){
	
  _pixels.setPixelColor(pos, _pixels.Color(0,0,0));
  _pixels.show();
  
}


///////////////////////////////////////////////////////////////////
//-- Sensors functions ------------------------------------------//
///////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//-- Winchy getDistance: return Winchy's ultrasonic sensor measure
//---------------------------------------------------------
float Winchy::getDistance(){
	
  return _us.read();
  
}

//---------------------------------------------------------
//-- Winchy getTemperature: return Winchy's lm35 temperature sensor measure
//---------------------------------------------------------
float Winchy::getTemperature(){
	
	return (analogRead(A0)*3300/1024)/10;
	
}


