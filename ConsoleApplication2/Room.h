#ifndef  ROOM_H
#define ROOM_H
#include <systemc.h>
#include "Channel.h"
SC_MODULE(Room) {
public:
	SC_HAS_PROCESS(Room);
	Room(sc_module_name name, Channel& channel);
	void control_lights();
private:
	int people_count;
	Channel& channel;
};
#endif