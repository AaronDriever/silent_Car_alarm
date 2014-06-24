/*
Silent car alarm Tx end using an exbee and a arduino Fio
*/
#include <XBee.h>


#define triggerPin 9


//SoftwareSerial xbee(2, 3); // RX, TX xbee pins


int triggerState;

long previousMillis = 0; 
long currentMillis = 100;
long interval = 500;

void setup()
{
	//Serial.begin(9600);
	Serial1.begin(9600);
	pinMode(triggerPin, INPUT);	// declare pin 9 to be an output:
}

void loop()
{
	armed();
}

void test()
{
	Serial1.println("hello"); //xbee
}

void armed()
{
	currentMillis = millis(); 
	if((currentMillis - previousMillis) > interval)
	{  
		previousMillis += interval; // save the last time you sent data
		Serial1.println(triggerState);
	} 
}

void test1()
{
	triggerState = digitalRead(triggerPin);
	if (triggerState > 0)
	{  
		Serial1.println(triggerState);
	} 

	else
	{
		test();
	}
}