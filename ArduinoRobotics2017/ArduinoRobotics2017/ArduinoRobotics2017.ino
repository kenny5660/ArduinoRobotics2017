/*
 Name:		ArduinoRobotics2017.ino
 Created:	28.10.2017 9:18:31
 Author:	misha
*/
#include <iarduino_RF433_Transmitter.h>
#include <iarduino_RF433_Receiver.h>
#include <Servo.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
#define RLINESEN A2 //правый датчик линии
#define LLINESEN A3 //левый датчик линии
#define BUT1 A1
#define BUT2 A0
// the setup function runs once when you press reset or power the board
#define P   0.25 
#define I 0     
#define D 1
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
	reciver_init();
	MotorRight(0);
	MotorLeft(0);
	servoBack.attach(10);
	servoBack.write(50);
//	servoBack.write(150);//сброс шайбы
	while (1) {
	/*	Serial.print("LLINESEN = ");
		Serial.print(analogRead(LLINESEN));
		Serial.print("\t RLINESEN = ");
		Serial.println(analogRead(RLINESEN));*/
	//	Adps_Debug();
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
	//while (Adps_Color() != 4)//синий
	//{
	//	black_line(P, I, D);
	////	Serial.println(Adps_Color());
	//}
	//Serial.println(Adps_Color());
	//while (Adps_Color() != 2)//красный
	//{
	//	MotorRight(255);
	//	MotorLeft(255);
	//}
	servoBack.write(150);//сброс шайбы
	MotorRight(0);
	MotorLeft(0);

}

// the loop function runs over and over again until power down or reset
void loop() {
//	Serial.println(avilable_stop_byte(), HEX);

	//black_line(P, I, D);
	//Serial.println(mode);
	//Adps_Debug();
}
