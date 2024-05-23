#ifndef  ROOM_H
#define ROOM_H
#include <systemc.h>
#include "Channel.h"
// modu³ Room 
SC_MODULE(Room) {
public:
	SC_HAS_PROCESS(Room);
	Room(sc_module_name name, int room_id, Channel& channel);
	void control_lights();
private:
	int people_count; // liczba osób w pokojach
	int room_id; // identyfikator pokoju 
	Channel& channel; // referencje do kana³u komunikacyjnego 

};
#endif