
#include <ADRIIOT_lightDimmer.h>

lightDimmerManagment relay_managment;
int 			relayId;
int 			relay2Id;

void setup()
{
	relay_managment.create 		(2, relayId);
	relay_managment.create 		(16, relay2Id);
	// relay_managment.setPullup 	(relayId, true);
	relay_managment.module(relayId)->close();
	relay_managment.module(relay2Id)->close();
}

uint8_t dim;
void loop()
{
	dim+=1;
	relay_managment.module(relayId)->dim(map(dim, 0, 255, 0, 1024));
	relay_managment.module(relay2Id)->dim(map(dim, 0, 255, 0, 1024));
	delay(25);
	// delay(1);
  // increase the LED brightness

}