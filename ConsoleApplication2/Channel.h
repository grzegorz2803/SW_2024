#ifndef CHANNEL_H
#define CHANNEL_H
#include <systemc.h>
// definicja modu³u Channel
SC_MODULE(Channel) {
public:
	SC_HAS_PROCESS(Channel);
	Channel(sc_module_name name);
	void send(int room_id, int people_count);
	int receive(int room_id);

private:
	int rooms[5]; // tablica przechowuj¹ca liczê osób w pokojach 
	sc_mutex room_mutex; // Mutex do synchronizacji dostêpu do tablicy rooms
};
#endif