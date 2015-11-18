/*

Simple Serial Bridge for Arduino.
 
copyright: eden candelas
license: CC-BY read LICENSE.

*/


#define UNO
//#define MEGA

#ifdef UNO
	#include <SoftwareSerial.h>
	SoftwareSerial SoftSerial(10,11); // RX, TX
#endif

void setup() {
	pinMode(8, OUTPUT); //controla DE/RE en el max485
	Serial.begin(9600);
	Serial.println("Serial Bridge - all characters sent will be forwarded");

#ifdef UNO
	SoftSerial.begin(9600);
	Serial.println("SoftSerial");
#endif
#ifdef MEGA
	Serial1.begin(9600);
	Serial.println("Serial1");
#endif

  // Serial2.begin(9600);
}

void loop() {

	if (Serial.available() > 0) {
		digitalWrite(8, HIGH);
    //requerido para que el primer bit enviado tenga
    //suficiente tiempo pra ser enviado
		delayMicroseconds(500);                        

		while (Serial.available() > 0) {
			char c = Serial.read();
#ifdef UNO
			SoftSerial.print(c);
			delayMicroseconds(500); 
#endif

#ifdef MEGA
			Serial1.print(c);
			delayMicroseconds(1000); 
#endif

#ifdef MEGA
		delayMicroseconds(500);
#endif
    // delay(1);
		digitalWrite(8, LOW);
	}
	delay(50);

#ifdef UNO
	if (SoftSerial.available() > 0) {
		delay(10);
		Serial.println();
		Serial.println("SoftSerial RX:");
		while (SoftSerial.available() > 0) {
			char c = SoftSerial.read();
			Serial.print(c);
		}
	}
#endif

#ifdef MEGA
	if (Serial1.available() > 0) {
		delay(10);
		Serial.println();
		Serial.println("Serial1 RX:");
		while (Serial1.available() > 0) {
			char c = Serial1.read();
			Serial.print(c);
		}
	}
#endif
	
	delay(50);

}