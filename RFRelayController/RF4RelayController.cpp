// Do not remove the include below
#include "RF4RelayController.h"
#include <Command.h>

#include <VirtualWire.h>
//#include "Arduino.h"
#include "HardwareSerial.h"

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

String sBuffer;


extern HardwareSerial Serial;
Relay relays[4];

int parse();

Relay createRelay(int port) {
	Relay result=Relay();
	result.port = port;
	result.isOn = false;
	pinMode(port, OUTPUT);
	return result;
}

void setup() {
	Serial.begin(9600);
	Serial.println("setup");

	relays[0] = createRelay(PORT_0);
	relays[1] = createRelay(PORT_1);
	relays[2] = createRelay(PORT_2);
	relays[3] = createRelay(PORT_3);

	vw_set_rx_pin(PORT_RF);
	vw_setup(4000); // Bits per sec
	vw_rx_start(); // Start the receiver PLL running
}

void loop()
{

  vw_wait_rx();
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int port=parse();
    switchState(port);
    Serial.print(port);
    Serial.println();
  }
}

void loop2(){
	String s = String("·:4:D:RFR:H:R::WD:WD");
	Command command = Command::parseCommand(s);
	Serial.println(command.getName());
}

int parse() {
	sBuffer = String((char *) buf);
	int port;
	if (sBuffer.equals("0")) {
		port = PORT_0;
	} else if (sBuffer.equals("1")) {
		port = PORT_1;
	} else if (sBuffer.equals("2")) {
		port = PORT_2;
	} else if (sBuffer.equals("3")) {
		port = PORT_3;
	} else
		port = -1;
	return port;
}

void turnOn(int id) {
	digitalWrite(relays[id].port, HIGH); // set the LED off
	relays[id].isOn = true;

}

void turnOff(int id) {
	digitalWrite(relays[id].port, LOW); // set the LED off
	relays[id].isOn = false;
}

void switchState(int id) {
	if (relays[id].isOn) {
		turnOff(id);
	} else {
		turnOn(id);
	}
}

