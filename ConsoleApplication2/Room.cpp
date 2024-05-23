#include "Room.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
extern sc_event update_event;
Room::Room(sc_module_name name,int room_id, Channel& channel) :sc_module(name),room_id(room_id), channel(channel), people_count(0) {

}
void Room::control_lights() {

		//wait_for_update();
		people_count = channel.receive(room_id);
		if (people_count > 0) {
			std::cout << "Room " << room_id << ": \033[32m Lights ON \033[0m (" << people_count << ")\n";
		}
		else if (people_count == 0) {
			std::cout << "Room " << room_id << ": Lights OFF (" << people_count << ")\n";
		}
		else
		{
			std::cout << "Room " << room_id << ":\033[31m ERROR \033[0m(" << people_count << ")\n";
			channel.send(room_id, 0);
		}
		Sleep(1000);
	
}

void Room::wait_for_update() {
	wait(update_event);
}