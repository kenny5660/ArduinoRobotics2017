// ��������� �������, ���������� � �������:
iarduino_RF433_Transmitter radioTX(4);                    // ������ ������ radioTX ��� ������ � ����������� iarduino_RF433, �������� ����� ������ � �������� ��������� ����������
iarduino_RF433_Receiver    radioRX(3);

//#define STOP_BYTE 0xFE
#define STOP_BYTE 0xF5
uint8_t readbuff[1];
uint8_t writebuff = STOP_BYTE;
void reciver_init(){
	pinMode(11, INPUT);
	Serial.begin(112500);

	radioTX.begin(1000);                                  // ���������� ������ ����������� FS1000A �� �������� 1 ����/���
	radioTX.openWritingPipe(5);                           // ��������� 5 ����� ��� �������� ������ (���������� ����� ���������� ������ ������ �� ����� �� ����: 0...7). ���� �������� ������� ������� openWritingPipe ������ ������ ����� �����, �� ���������� ����� ���������� ������ �� ����� ��������� �����
														  //  =============================== ��Ȩ����
	radioRX.begin(1000);                                  // ���������� ������ �������� MX-RM-5V (� �������� ��������� ����� ������� �������� ����� ���/���, ����� ����� �� �������� ������� setDataRate)
	radioRX.openReadingPipe(5);                          // ��������� 5 ����� ��� ������ ������ (���� ������� ������� ��� ���������, �� ����� ������� ��� ����� �����, �� 0 �� 7)
	radioRX.startListening();        // �������� ��������, �������� ������������ �������� �����

}



char avilable_stop_byte(){
	uint8_t pipe = 0;
	                      
	if (radioRX.available(&pipe)) {                        
		radioRX.read(&readbuff, 1);
		Serial.print(readbuff[0], HEX);
		if (readbuff[0] == 0xF5) {
		                              // ������� ���������� ������ �� �������
			Serial.println((String)" (Pipe=" + pipe + ")"); // ������� ����� �����, �� ������� ��� ������ ��������. ��� ����� ����������, �� ������ ����������� ��� ��������
			return 1;
		}
	}

	return 0;
}
void send_stop_byte() {
	Serial.println("RADIO SENDED");
	radioTX.write(&writebuff, 1);
}
