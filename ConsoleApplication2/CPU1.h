#ifndef CPU1_H
#define CPU1_H

#include <systemc.h>
#include "Channel.h"
#include "HardwareTask.h"
#include "Room.h"
// definicja modu≥u CPU1
SC_MODULE(CPU1) {
public:
	SC_HAS_PROCESS(CPU1);
	CPU1(sc_module_name name, Channel& channel);

private:
	void task2(); // funkcja kontrolujπca úwiat≥a w pojach 
	void task3();
	void task4();
	HardwareTask* hw_t; // wkaünik do zadania sprzÍtowego
	Channel& channel; // referencja do kana≥u komunikacyjnego
	Room* room1; // wskaüniki do pokoi 
	Room* room2;
	Room* room3;
	Room* room4;
};

#endif