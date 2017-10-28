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

	if (apds.init()) {
		Serial.println(F("APDS-9960 initialization complete"));
	}
	else {
		Serial.println(F("Something went wrong during APDS-9960 init!"));
	}
	if (apds.enableLightSensor(false)) {
		Serial.println(F("Light sensor is now running"));
	}
	else {
		Serial.println(F("Something went wrong during light sensor init!"));
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(13, 1);
	delay(500);
	Serial.println(analogRead(LLINESEN));
	if (!apds.readAmbientLight(ambient_light) ||
		!apds.readRedLight(red_light) ||
		!apds.readGreenLight(green_light) ||
		!apds.readBlueLight(blue_light)) {
		Serial.println("Error reading light values");
	}
	else {
		Serial.print("Ambient: ");
		Serial.print(ambient_light);
		Serial.print(" Red: ");
		Serial.print(red_light);
		Serial.print(" Green: ");
		Serial.print(green_light);
		Serial.print(" Blue: ");
		Serial.println(blue_light);
	}
	digitalWrite(13, 0);
	delay(500);
	
}
