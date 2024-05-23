#ifndef HARDWARE_TASK_H
#define HARDWARE_TASK_H
#include <systemc.h>
#include "Channel.h"
// definicja modu³u zadania sprzêtowego 
SC_MODULE(HardwareTask) {
public:
	SC_HAS_PROCESS(HardwareTask);
	HardwareTask(sc_module_name name, Channel& channel);
	void process(); // funkcja do zadania sprzêtowego
private:
	Channel& channel; // referencja do kana³u komunikacyjnego 
};
#endif