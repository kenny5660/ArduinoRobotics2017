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
#define P   0.35 
#define I 0     
#define D 2
int  v = 255;
Servo servoBack;
Servo servoStop;
unsigned long lastMilis = 0;
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
	servoStop.attach(3);
	servoStop.write(120);
	servoBack.attach(10);
	servoBack.write(50);
//	servoBack.write(150);//сброс шайбы
	while (1) {
		/*Serial.print("LLINESEN = ");
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
//	servoBack.write(150);//сброс шайбы


	lastMilis = millis();
	//while (Adps_Color() != 3)//зеленый
	while (true)
	{
		black_line(P, I, D);
		if ((millis() - lastMilis)>7400)
		{
			break;
		}
	//	Serial.println(Adps_Color());
	}
	//Serial.println(millis()-lastMilis);
	//Serial.println(Adps_Color());
	MotorRight(235);
	MotorLeft(255);
	delay(1400);
	MotorRight(0);
	MotorLeft(0);
	MotorRight(190);
	MotorLeft(210);
	delay(1300);
	if (mode == 2) {
		servoStop.write(70);//stopeэ
	}


	while (Adps_Color() != 2)//красный
	{
		MotorRight(245);
		MotorLeft(255);
	}
	if (mode == 2) {
		servoStop.write(120);//поднятие заграждения
	}
	delay(60);
	servoBack.write(160);//сброс шайбы
	delay(500);
	if (mode == 2) {
		delay(300);
		servoStop.write(70);//stopeэ
		delay(1000);
	}
	if (mode == 1) {
		MotorRight(200);
		MotorLeft(200);
		delay(750);
		servoStop.write(70);//stopeэ
		MotorRight(0);
		MotorLeft(0);
		delay(300);
		MotorRight(-200);
		MotorLeft(-200);
		delay(1000);
	}

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
