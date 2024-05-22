#include "Room.h"
#include <iostream>
extern sc_event update_event;
Room::Room(sc_module_name name,int room_id, Channel& channel) :sc_module(name),room_id(room_id), channel(channel), people_count(0) {
	SC_THREAD(control_lights);
}
void Room::control_lights() {


wait_for_update();
		people_count = channel.receive(room_id);
		if (people_count > 0) {
			std::cout << "Room " << room_id << ": Lights ON (" << people_count << ")\n";
		}
		else if (people_count == 0) {
			std::cout << "Room " << room_id << ": Lights OFF (" << people_count << ")\n";
		}
		else
		{
			std::cout << "Room " << room_id << ": ERROR (" << people_count << ")\n";
		}

	
	
}

void Room::wait_for_update() {
	wait(update_event);
}