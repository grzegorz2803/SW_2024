#include "Room.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
// konstruktor klasy Room inicjalizuj¹cy identyfikator pokoi i kana³u komunikacyjnego 
Room::Room(sc_module_name name,int room_id, Channel& channel) :sc_module(name),room_id(room_id), channel(channel), people_count(0) {

}
// funkcja kontroluj¹ca œwiat³o w pokoju 
void Room::control_lights() {
		people_count = channel.receive(room_id);
		if (people_count > 0) {
			std::cout << "S" << room_id+1 << ": \033[32m Lights ON \033[0m (" << people_count << ")\n";
		}
		else if (people_count == 0) {
			std::cout << "S" << room_id+1 << ": Lights OFF (" << people_count << ")\n";
		}
		else
		{
			std::cout << "S" << room_id+1 << ":\033[31m ERROR \033[0m(" << people_count << ")\n";
			channel.send(room_id, 0); // kasowanie ERROR
		}

	
}

