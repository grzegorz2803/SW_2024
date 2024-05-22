#ifndef HARDWARE_TASK_H
#define HARDWARE_TASK_H
#include <systemc.h>
#include "Channel.h"
SC_MODULE(HardwareTask) {
public:
	SC_HAS_PROCESS(HardwareTask);
	HardwareTask(sc_module_name name, Channel& channel);
	void process();
private:
	Channel& channel;
};
#endif