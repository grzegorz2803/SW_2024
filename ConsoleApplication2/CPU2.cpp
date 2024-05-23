#include "CPU2.h"
#include "Room.h"
#include <thread>
#include <chrono>
#include<Windows.h>
// konstruktor klasy CPU2 inicjalizuj¹cy pokoje i zadania sprzêtowe 
CPU2::CPU2(sc_module_name name, Channel& channel) : sc_module(name), channel(channel) {
	room5 = new Room("Room5", 4, channel);
	SC_THREAD(task5);
}
// funkcja do kontroli œwiat³a w pomieszczeniu 
void CPU2::task5() {
	while (true)
	{


		room5->control_lights();
		wait(1, SC_SEC);
		Sleep(500);

	}
}