#include "HardwareTask.h"
#include <iostream>

HardwareTask::HardwareTask(sc_module_name name, Channel& channel) :sc_module(name), channel(channel){
	SC_THREAD(process);
}
void HardwareTask::process(){
	
		int people_count = channel.receive(0);
		if (people_count > 0) {
			std::cout << "Room 0: Lights ON (" << people_count << ")\n";
		}
		else if (people_count==0)
		{
			std::cout << "Room 0: Lights OFF (" << people_count << ")\n";
		}
		else
		{
			std::cout << "Room 0: ERROR (" << people_count << ")\n";
		}
		wait(1, SC_SEC);
	
}