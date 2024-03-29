/*==================================
CARX


=================================*/



int RXLED = 17;  // The RX LED has a defined Arduino pin
// The TX LED was not so lucky, we'll need to use pre-defined
// macros (TXLED1, TXLED0) to control that.
// (We could use the same macros for the RX LED too -- RXLED1,
//  and RXLED0.)

void setup()
{
	pinMode(RXLED, OUTPUT);  // Set RX LED as an output // TX LED is set as an output behind the scenes
	Serial.begin(9600);      // This pipes to the serial monitor, this is the line to the USB
	Serial1.begin(9600);     // This is the UART, this is the line to the xbee
	delay(5000);             // allows xbee to boot
	Serial1.println("B");    // Puts the Xbee in RF mode
	delay(10);
}

void loop()
{
	Serial.println("Hello world");  // Print "Hello World" to the Serial Monitor
	Serial1.println("Hello!");      // Print "Hello!" over hardware UART

	digitalWrite(RXLED, LOW);       // set the LED on
	TXLED0;                         // TX LED is not tied to a normally controlled pin
	delay(1000);                    // wait for a second
	digitalWrite(RXLED, HIGH);      // set the LED off
	TXLED1;
	delay(1000);                    // wait for a second
}
