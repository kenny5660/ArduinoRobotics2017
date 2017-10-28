/*
 Name:		ArduinoRobotics2017.ino
 Created:	28.10.2017 9:18:31
 Author:	misha
*/
#include <Servo.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
#define RLINESEN A2 //правый датчик линии
#define LLINESEN A3 //левый датчик линии
// the setup function runs once when you press reset or power the board
#define P   0.3 
#define I 0     
#define D 40 
Servo servoBack;
void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	pinMode(LLINESEN, INPUT);
	pinMode(RLINESEN, INPUT);
	MotorInit();//инцилизация моторов
	//MotorRight(-100);
	//MotorLeft(100);
//	servoBack.attach(10);
//	servoBack.write(0);
}

// the loop function runs over and over again until power down or reset
void loop() {
	black_line(P, I, D);
	//Serial.println(analogRead(LLINESEN));
	
}
