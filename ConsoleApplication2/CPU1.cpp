#include "CPU1.h"
#include "Room.h"

CPU1::CPU1(sc_module_name name, Channel& channel) :sc_module(name), channel(channel) {
	hw_task1 = new HardwareTask("HardwareTask1", channel);
	room2 = new Room("Room2", 1, channel);
	room3 = new Room("Room3", 2, channel);
	room4 = new Room("Room4", 3, channel);
	SC_THREAD(task2);
	SC_THREAD(task3);
	SC_THREAD(task4);
}

void CPU1::task2() {
	
	while (true)
	{


		room2->control_lights();
		wait(10000, SC_SEC);
	}
}

void CPU1::task3() {
	
	while (true)
	{

		room3->control_lights();
		wait(10000, SC_SEC);
	}
}
void CPU1::task4() {

	while (true)
	{


		room4->control_lights();
		wait(10000, SC_SEC);
	}
}
