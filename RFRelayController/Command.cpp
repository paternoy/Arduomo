/*
 * Command.cpp
 *
 *  Created on: Jan 29, 2012
 *      Author: xum
 */
#include "Command.h"

#include "HardwareSerial.h"
#include <WString.h>

extern HardwareSerial Serial;
char * commandBuf = new char[BUFFER_LEN];

Command::Command(String _name, String* args) {
	this->name = (String) NULL;
	int i = 0;
	for (unsigned int i = 0; i < sizeof(args); ++i) {
		this->arguments[i] = String(args[i]);
	}
}

Command::~Command() {

}

String Command::getArgument(int i) {
	return this->arguments[i];
}

String Command::getName() {
	return this->name;
}

Command Command::parseCommand(String text) {
	Command result = Command();

	text.toCharArray(commandBuf, BUFFER_LEN);
	result.name = strtok_r(commandBuf, ":", &commandBuf);

	char* arg;
	result.arguments = new String[MAX_ARGS];
	int i = 0;
	while ((arg = strtok_r(commandBuf, ":", &commandBuf)) != NULL) {
		Serial.println(arg);
		result.arguments[i] = String(arg);
		i++;
	}

	return result;
}

