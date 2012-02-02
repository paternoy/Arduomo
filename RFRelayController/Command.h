/*
 * Command.h
 *
 *  Created on: Jan 29, 2012
 *      Author: xum
 */

#ifndef COMMAND_H_
#define COMMAND_H_
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif


static const unsigned int BUFFER_LEN=50;
static const unsigned int MAX_ARGS=5;

class Command {
public:
	String name;
	String * arguments;
public:
	Command();
	Command(String _name, String* args);
	String getName();
	String getArgument(int i);
	~Command();
	static Command parseCommand(String text);
};


#endif /* COMMAND_H_ */
