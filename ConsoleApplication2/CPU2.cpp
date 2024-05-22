#include "CPU2.h"
#include "Room.h"
#include <thread>
#include <chrono>

CPU2::CPU2(sc_module_name name, Channel& channel) : sc_module(name), channel(channel) {
	room5 = new Room("Room5", 4, channel);
	SC_THREAD(task5);
}

void CPU2::task5() {
	while (true)
	{


		room5->control_lights();
		wait(1, SC_SEC);
		//std::this_thread::sleep_for(std::chrono::seconds(1));

	}
}