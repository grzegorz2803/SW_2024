#include "CPU2.h"
#include "Room.h"

CPU2::CPU2(sc_module_name name, Channel& channel) : sc_module(name), channel(channel) {
	room5 = new Room("Room5", 4, channel);
	SC_THREAD(task5);
}

void CPU2::task5() {

		room5->control_lights();
		wait(1, SC_SEC);
	
}