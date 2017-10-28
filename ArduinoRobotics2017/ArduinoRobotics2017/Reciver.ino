// Объявляем объекты, переменные и массивы:
iarduino_RF433_Transmitter radioTX(4);                    // Создаём объект radioTX для работы с библиотекой iarduino_RF433, указывая номер вывода к которому подключён передатчик
iarduino_RF433_Receiver    radioRX(3);

//#define STOP_BYTE 0xFE
#define STOP_BYTE 0xF5
uint8_t readbuff[1];
uint8_t writebuff = STOP_BYTE;
void reciver_init(){
	pinMode(11, INPUT);
	Serial.begin(112500);

	radioTX.begin(1000);                                  // Инициируем работу передатчика FS1000A на скорости 1 кбит/сек
	radioTX.openWritingPipe(5);                           // Открываем 5 трубу для передачи данных (передатчик может передавать данные только по одной из труб: 0...7). Если повторно вызвать функцию openWritingPipe указав другой номер трубы, то передатчик начнёт передавать данные по вновь указанной трубе
														  //  =============================== ПРИЁМНИК
	radioRX.begin(1000);                                  // Инициируем работу приёмника MX-RM-5V (в качестве параметра можно указать скорость ЧИСЛО бит/сек, тогда можно не вызывать функцию setDataRate)
	radioRX.openReadingPipe(5);                          // Открываем 5 трубу для приема данных (если вызвать функцию без параметра, то будут открыты все трубы сразу, от 0 до 7)
	radioRX.startListening();        // Включаем приемник, начинаем прослушивать открытую трубу

}



char avilable_stop_byte(){
	uint8_t pipe = 0;
	                      
	if (radioRX.available(&pipe)) {                        
		radioRX.read(&readbuff, 1);
		Serial.print(readbuff[0], HEX);
		if (readbuff[0] == 0xF5) {
		                              // Выводим полученные данные на монитор
			Serial.println((String)" (Pipe=" + pipe + ")"); // Выводим номер трубы, по которой эти данные получены. Так можно определить, от кокого передатчика они получены
			return 1;
		}
	}

	return 0;
}
void send_stop_byte() {
	Serial.println("RADIO SENDED");
	radioTX.write(&writebuff, 1);
}
