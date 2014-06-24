//#include <xbee.h>
#include <SoftwareSerial.h>


SoftwareSerial xbee(8, 9); // RX, TX xbee pins

int received1=11;  
unsigned long output1;

void setup(){  
	pinMode(received1, OUTPUT);  
	xbee.begin(9600);  
	Serial.begin(9600);  
}  
void loop()
{  
	if(xbee.available())  
	{  
		output1 = xbee.read();  
		///digitalWrite(received1,output1);
		analogWrite(received1,output1);
		Serial.println(output1);
		//digitalWrite(received1, HIGH);      
	}  
}