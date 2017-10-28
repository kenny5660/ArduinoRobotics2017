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
#define BUT1 A1
#define BUT2 A0
// the setup function runs once when you press reset or power the board
#define P   0.3 
#define I 0     
#define D 40 
Servo servoBack;
int mode = 0;
void setup() {
	Serial.begin(9600);

	pinMode(13, OUTPUT);
	pinMode(LLINESEN, INPUT);
	pinMode(RLINESEN, INPUT);
	pinMode(BUT1,INPUT_PULLUP);
	pinMode(BUT2, INPUT_PULLUP);
	MotorInit();//инцилизация моторов
	Adps_init();//дачик цвета
	MotorRight(0);
	MotorLeft(0);
	servoBack.attach(10);
	servoBack.write(50);
//	servoBack.write(150);//сброс шайбы
	while (1) {
		if (digitalRead(BUT1) == 0) {
			mode = 1;
			break;
		}
		if (digitalRead(BUT2) == 0)
		{
			mode = 2;
			break;
		}
   }
}

// the loop function runs over and over again until power down or reset
void loop() {

		

	//black_line(P, I, D);
	//Serial.println(mode);
	//Adps_Debug();
}
