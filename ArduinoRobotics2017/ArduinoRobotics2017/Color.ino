
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