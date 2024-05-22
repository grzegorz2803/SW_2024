#include <systemc.h>
#include "CPU1.h"
#include "CPU2.h"
#include "Channel.h"
#include <thread>
#include <iostream>
#include <functional>
#include <cstdlib>
#include <conio.h>
sc_event update_event;
bool direction = false;
char key;
int sc_main(int, char* []) {
	Channel channel("channel");
	CPU1 cpu1("CPU1", channel);
	CPU2 cpu2("CPU2", channel);
	std::thread keyboard_input([&channel]() {
		
		while (true)
		{
			if (_kbhit()) {
				key = _getch();
				if (key == 'k') {
					direction = !direction;
					std::cout << direction << "\n";
					continue;
				}
				if (key=='q')
				{
					break;
				}
				
			}
			
		}
		});
	sc_start();
	keyboard_input.join();
	return 0;
}