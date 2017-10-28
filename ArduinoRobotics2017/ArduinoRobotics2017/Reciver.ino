// Объявляем объекты, переменные и массивы:
iarduino_RF433_Transmitter radioTX(3);                    // Создаём объект radioTX для работы с библиотекой iarduino_RF433, указывая номер вывода к которому подключён передатчик
iarduino_RF433_Receiver    radioRX(2);

#define STOP_BYTE 0xFE
//#define STOP_BYTE 0xF5

uint8_t writebuff = STOP_BYTE;
void reciver_init(){
	radioTX.begin(1000);                                  // Инициируем работу передатчика FS1000A на скорости 1 кбит/сек
	radioTX.openWritingPipe(5);                           // Открываем 5 трубу для передачи данных (передатчик может передавать данные только по одной из труб: 0...7). Если повторно вызвать функцию openWritingPipe указав другой номер трубы, то передатчик начнёт передавать данные по вновь указанной трубе
//	pinMode(2, INPUT);								  //  =============================== ПРИЁМНИК
	radioRX.begin(1000);                                  // Инициируем работу приёмника MX-RM-5V (в качестве параметра можно указать скорость ЧИСЛО бит/сек, тогда можно не вызывать функцию setDataRate)
	radioRX.openReadingPipe(5);                          // Открываем 5 трубу для приема данных (если вызвать функцию без параметра, то будут открыты все трубы сразу, от 0 до 7)
	radioRX.startListening();        // Включаем приемник, начинаем прослушивать открытую трубу

}



char avilable_stop_byte(){
	uint8_t readbuff[1];
	uint8_t pipe = 0;
	if (radioRX.available(&pipe)) { // Если в буфере имеются данные принятые приёмником, то получаем номер трубы в переменную k и ... 
		radioRX.read(readbuff, 1); // Читаем данные в массив j и указываем сколько байт читать 
		if (readbuff[0] == STOP_BYTE) {
			return 1;
		}
		//Serial.print(readbuff[0], HEX); // Выводим полученные данные на монитор 
		//Serial.println((String)" (Pipe=" + pipe + ")"); // Выводим номер трубы, по которой эти данные получены. Так можно определить, от кокого передатчика они получены 
	}
	//Serial.println((String)" (Pipe=" + pipe + ")"); // Выводим номер трубы, по которой эти данные получены. Так можно определить, от кокого передатчика они получены 


	return 0;
}
void send_stop_byte() {
	Serial.println("RADIO SENDED");
	radioTX.write(&writebuff, 1);
}
