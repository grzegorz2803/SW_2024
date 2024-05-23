#ifndef CPU1_H
#define CPU1_H

#include <systemc.h>
#include "Channel.h"
#include "HardwareTask.h"
#include "Room.h"
SC_MODULE(CPU1) {
public:
	SC_HAS_PROCESS(CPU1);
	CPU1(sc_module_name name, Channel& channel);

private:
	void task2();
	void task3();
	void task4();
	HardwareTask* hw_t;
	Channel& channel;
	Room* room1;
	Room* room2;
	Room* room3;
	Room* room4;
};

#endif