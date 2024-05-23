#include "Channel.h"
// konstruktor klasy Channel inicjalizuj¹cy tablice rooms zerami
Channel::Channel(sc_module_name name) :sc_module(name) {
	for (int i = 0; i < 5; i++)
	{
		rooms[i] = 0;
	}
}
// funkcja wysy³aj¹ca liczbê osób do odpowiedniego pokoju
void Channel::send(int room_id, int people_count) {
	room_mutex.lock();
	rooms[room_id] = people_count;
	room_mutex.unlock();
}
// funkcja odbieraj¹ca liczê osób z odpowieniego pokoju
int Channel::receive(int room_id) {
	int count;
	room_mutex.lock();
	count = rooms[room_id];
	room_mutex.unlock();
	return count;
}
