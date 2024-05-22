#include "HardwareTask.h"
#include <iostream>
extern sc_event update_event;
HardwareTask::HardwareTask(sc_module_name name, Channel& channel) :sc_module(name), channel(channel){
	SC_THREAD(process);
}
void HardwareTask::process(){
	while (true)
	{
		wait(update_event);

		int people_count = channel.receive(0);
		if (people_count > 0) {
			std::cout << "Room 0: Lights ON (" << people_count << ")\n";
		}
		else if (people_count == 0)
		{
			std::cout << "Room 0: Lights OFF (" << people_count << ")\n";
		}
		else
		{
			std::cout << "Room 0: ERROR (" << people_count << ")\n";
		}
	}
	
}