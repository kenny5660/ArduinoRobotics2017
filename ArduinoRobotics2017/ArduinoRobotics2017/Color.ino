SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t cR = 0;
uint16_t cG = 0;
uint16_t cB = 0;
void Adps_init() {

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

void Adps_Debug() {
	digitalWrite(13, 1);
	delay(500);
	if (!apds.readAmbientLight(ambient_light) ||
		!apds.readRedLight(cR) ||
		!apds.readGreenLight(cG) ||
		!apds.readBlueLight(cB)) {
		Serial.println("Error reading light values");
	}
	else {
		Serial.print("Ambient: ");
		Serial.print(ambient_light);
		Serial.print(" Red: ");
		Serial.print(cR);
		Serial.print(" Green: ");
		Serial.print(cG);
		Serial.print(" Blue: ");
		Serial.println(cB);
	}
	digitalWrite(13, 0);
	delay(500);
}

int Adps_Color() {

	digitalWrite(13, 1);
	delay(500);
	if (!apds.readAmbientLight(ambient_light) ||
		!apds.readRedLight(cR) ||
		!apds.readGreenLight(cG) ||
		!apds.readBlueLight(cB)) {
		Serial.println("Error reading light values");
	}
	else {
		Serial.print("Ambient: ");
		Serial.print(ambient_light);
		Serial.print(" Red: ");
		Serial.print(cR);
		Serial.print(" Green: ");
		Serial.print(cG);
		Serial.print(" Blue: ");
		Serial.println(cB);
			if (cG > 1500 & cR > 1500 & cB < 1500) {//������
				Serial.println("YELLOW");
				return  1;
				
			}
			if (cR > 1200 & cG < 1000 & cB < 1000) {//�������
				Serial.println("RED");
				return  2;
			}
			if (cR < 1100 & cG > 1100 & cB < 1100) {//�������
				Serial.println("GREEN");
				return  3;
			}
			if (cR< 800 & cG < 800 & cB >800) {//�����
			   	Serial.println("BLUE");
				return  4;
			}
			if (cR>2000 & cG > 2000 & cB >2000) {//�����
				Serial.println("WHITE");
				return  5;
			}
			if (cR<900 & cG < 900 & cB < 900) {//������
				Serial.println("BLACK");
				return  6;
			}
			return  7;
		
	}

}