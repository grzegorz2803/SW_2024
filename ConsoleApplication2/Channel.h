#ifndef CHANNEL_H
#define CHANNEL_H
#include <systemc.h>
// definicja modu�u Channel
SC_MODULE(Channel) {
public:
	SC_HAS_PROCESS(Channel);
	Channel(sc_module_name name);
	void send(int room_id, int people_count);
	int receive(int room_id);

private:
	int rooms[5]; // tablica przechowuj�ca licz� os�b w pokojach 
	sc_mutex room_mutex; // Mutex do synchronizacji dost�pu do tablicy rooms
};
#endif