#ifndef CPU2_H
#define CPU2_H

#include <systemc.h>
#include "Channel.h"
#include "Room.h"
SC_MODULE(CPU2) {
public:
	SC_HAS_PROCESS(CPU2);
	CPU2(sc_module_name name, Channel& channel);
private:
	void task5();
	Room* room5;
	Channel& channel;
};
#endif