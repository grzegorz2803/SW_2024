#ifndef HARDWARE_TASK_H
#define HARDWARE_TASK_H
#include <systemc.h>
#include "Channel.h"
// definicja modu�u zadania sprz�towego 
SC_MODULE(HardwareTask) {
public:
	SC_HAS_PROCESS(HardwareTask);
	HardwareTask(sc_module_name name, Channel& channel);
	void process(); // funkcja do zadania sprz�towego
private:
	Channel& channel; // referencja do kana�u komunikacyjnego 
};
#endif