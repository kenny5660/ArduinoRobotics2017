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

int Adps_Debug() {
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
		if (cG > 600 & cR > 400 & cB <1000) {//желтый
											Serial.println("YELLOW");
			return  1;

		}
		if (cR > 300 & cG < 300 & cB < 420) {///красный
											 Serial.println("RED");
			return  2;
		}
		if (cR < 400 & cG > 450 & cB > 400 & cB < 700) {//зеленый
											 Serial.println("GREEN");
			return  3;
		}
		if (ambient_light<900 & cR < 250 & cG < 300 & cB >400) {//синий
											Serial.println("BLUE");
			return  4;
		}
		if (ambient_light>1800 & cR > 500 & cG > 700 & cB > 1000) {//белый
																   Serial.println("WHITE");
			return  5;
		}
		if (ambient_light < 800 & cR < 200 & cG < 300 & cB < 400) {//черный
																 Serial.println("BLACK");
			return  6;
		}
		return  7;

	}
}

int Adps_Color() {
	if (!apds.readAmbientLight(ambient_light) ||
		!apds.readRedLight(cR) ||
		!apds.readGreenLight(cG) ||
		!apds.readBlueLight(cB)) {
		Serial.println("Error reading light values");
	}
	else {
			if (cG > 600 & cR > 400 & cB < 1000 ) {//желтый
				return  1;
				
			}
			if (cR > 300 & cG < 300 & cB < 420) {//красный
				return  2;
			}
			if (cR < 400 & cG > 450 & cB > 400 & cB < 700) {//зеленый
				return  3;
			}
			if (ambient_light<900 & cR < 250 & cG < 300 & cB >400) {//синий
				return  4;
			}
			if (ambient_light>1800 & cR > 500 & cG > 700 & cB > 1000) {//белый
				return  5;
			}
			if (ambient_light < 800 & cR < 200 & cG < 300 & cB < 400) {//черный
				return  6;
			}
			return  7;
		
	}

}