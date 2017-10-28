/*
 Name:		ArduinoRobotics2017.ino
 Created:	28.10.2017 9:18:31
 Author:	misha
*/
#include <Wire.h>
#include <SparkFun_APDS9960.h>
#define RLINESEN A3 //правый датчик линии
#define LLINESEN A2 //левый датчик линии
// the setup function runs once when you press reset or power the board
#define P   0.37 
#define I 0     
#define D 60 
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	pinMode(LLINESEN, INPUT);
	pinMode(RLINESEN, INPUT);
	MotorInit();//инцилизация моторов

}

// the loop function runs over and over again until power down or reset
void loop() {
//	black_line(P, I, D);
	
	
}
