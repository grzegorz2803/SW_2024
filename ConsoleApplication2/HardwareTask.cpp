#include "HardwareTask.h"
#include <iostream>
#include <Windows.h>
// konstruktor klasy HardwareTask inicjalizuj¹cy process
extern sc_event update_event;
HardwareTask::HardwareTask(sc_module_name name, Channel& channel) :sc_module(name), channel(channel){
	SC_THREAD(process);
}
// funkcja realizuj¹ca zadanie sprzêtowe
void HardwareTask::process(){
	while (true)
	{

		int people_count = channel.receive(0);
		if (people_count > 0) {
			std::cout << "S1" << ": \033[32m Lights ON \033[0m (" << people_count << ")\n";
		}
		else if (people_count == 0) {
			std::cout << "S1" << ": Lights OFF (" << people_count << ")\n";
		}
		else
		{
			std::cout << "S1" << ":\033[31m ERROR \033[0m(" << people_count << ")\n";
			channel.send(0, 0);
		}
		wait(1, SC_SEC);
	}
}