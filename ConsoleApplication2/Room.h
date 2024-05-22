#ifndef  ROOM_H
#define ROOM_H
#include <systemc.h>
#include "Channel.h"
SC_MODULE(Room) {
public:
	SC_HAS_PROCESS(Room);
	Room(sc_module_name name, int room_id, Channel& channel);
	void control_lights();
private:
	int people_count;
	int room_id;
	Channel& channel;
	void wait_for_update();

};
#endif