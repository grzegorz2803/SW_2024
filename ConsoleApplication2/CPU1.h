#ifndef CPU1_H
#define CPU1_H

#include <systemc.h>
#include "Channel.h"
#include "HardwareTask.h"
SC_MODULE(CPU1) {
public:
	SC_HAS_PROCESS(CPU1);
	CPU1(sc_module_name name, Channel& channel);

private:
	void task2();
	void task3();
	void task4();

	Channel& channel;
	HardwareTask* hw_task1;
};

#endif