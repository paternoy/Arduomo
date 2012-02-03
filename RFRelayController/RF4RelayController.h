// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef RF4RelayController_H_
#define RF4RelayController_H_
#include "Arduino.h"
//add your includes for the project RF4RelayController here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project RF4RelayController here



//add your function definitions for the project RFRelayController here

static boolean ON_STATE=false;
static boolean OFF_STATE=true;

static int PORT_RF=2;

static int PORT_0=7;
static int PORT_1=6;
static int PORT_2=5;
static int PORT_3=4;

static int NUM_RELAYS = 4;

class Relay
{
  public:
	int port;
	boolean isOn;
};


void encendre (int port);
void apagar (int port);
void switchState(int id);



//Do not add code below this line
#endif /* RF4RelayController_H_ */
