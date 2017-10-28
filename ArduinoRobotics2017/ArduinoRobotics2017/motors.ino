#define Rpwm 6
#define Lpwm 5
#define L1DIR 4
#define L2DIR 7
#define R1DIR 9
#define R2DIR 8
int Lsen = 0;
int Rsen = 0;
int u, uOld, er, erOld = 0;
int  v = 255;
void MotorInit() {
	pinMode(Rpwm, OUTPUT);
	pinMode(Lpwm, OUTPUT);
	pinMode(L1DIR, OUTPUT);
	pinMode(L2DIR, OUTPUT);
	pinMode(R1DIR, OUTPUT);
	pinMode(R2DIR, OUTPUT);
}
void MotorRight(int pec) {
	if (pec > 255) {  //255
		pec = 255;
	}
	if (pec < -255)
	{
		pec = -255;
	}
	if (pec>0) {
		analogWrite(Rpwm, pec); //шим1
		digitalWrite(R1DIR, LOW);//мотор1
		digitalWrite(R2DIR, HIGH);//мотор1
	}
	else {
		pec *= -1;
		analogWrite(Rpwm, pec); //шим1
		digitalWrite(R2DIR, LOW);//мотор1
		digitalWrite(R1DIR, HIGH);//мотор1
	}
}

void MotorLeft(int pec) {
	if (pec > 255) {  //255
		pec = 255;
	}
	if (pec < -255)
	{
		pec = -255;
	}

	if (pec>0) {
		analogWrite(Lpwm, pec); //шим1

		digitalWrite(L1DIR, LOW);//мотор1
		digitalWrite(L2DIR, HIGH);//мотор1
	}
	else {
		pec *= -1;
		analogWrite(Lpwm, pec); //шим1
		digitalWrite(L2DIR, LOW);//мотор1
		digitalWrite(L1DIR, HIGH);//мотор1
	}
}

void black_line(float p, float i, float d) {

	Lsen = analogRead(LLINESEN);
	Rsen = analogRead(RLINESEN);
	er = Rsen - Lsen;
	u = p*er + i*(er + uOld) + d*(er - erOld);
	MotorLeft(v - (int)u);
	MotorRight(v + (int)u);
//	Serial.println(u);
	erOld = er;
	uOld = u;
	//delayMicroseconds(1);

}