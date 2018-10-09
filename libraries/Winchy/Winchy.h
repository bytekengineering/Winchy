#ifndef Winchy_h
#define Winchy_h

#include <Servo.h>

#include <US.h>
#include <Adafruit_NeoPixel.h>

class Winchy
{
  public:
	Winchy();
    
	//-- Winchy initialization
    void init();

    //-- Attach & detach functions
    void attachServos();
    void detachServos();

    //-- Predetermined Movement
    void forward();
	void backward();
	void left();
	void left2();
	void right();
	void right2();
	void myStop();

    //-- WS2812b LEDs
    void turnPixelOn(uint16_t pos, uint8_t r, uint8_t g, uint8_t b);
    void turnPixelOff(uint16_t pos);

    //-- Sensors functions
    float getDistance();	// US HC-SR04 sensor
    float getTemperature();	// LM35 Temperature Sensor

	
  private:
    
	//-- Variables & Objects
	Adafruit_NeoPixel _pixels;
	US _us;
	Servo _leftWheel, _rightWheel;
   
    
};

#endif


