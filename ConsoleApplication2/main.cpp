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
					sc_stop();
					break;
				}
				switch (key)
				{
				case '0':
				{
					int current_people = channel.receive(4);
					if (direction)
					{
						current_people--;
					}
					else
					{
						current_people++;
					}
					channel.send(4, current_people);
					break;
				}
				case '1':
				{
					int current_people = channel.receive(0);
					if (direction)
					{
						current_people--;
					}
					else
					{
						current_people++;
					}
					channel.send(0, current_people);
					break;

				}
				case '2':
				{
					int current_people = channel.receive(2);
					if (direction)
					{
						current_people++;
					}
					else
					{
						current_people--;
					}
					channel.send(2, current_people);
					break;
				}
				case '3':
				{
					int current_people1 = channel.receive(0);
					int current_people2 = channel.receive(2);
					if (direction)
					{
						current_people1++;
						current_people2--;
					}
					else
					{
						current_people2++;
						current_people1--;
					}
					channel.send(0, current_people1);
					channel.send(2, current_people2);
					break;
				}
				case '4':
				{
					int current_people1 = channel.receive(0);
					int current_people2 = channel.receive(4);
					if (direction)
					{
						current_people1--;
						current_people2++;
					}
					else
					{
						current_people2--;
						current_people1++;
					}
					channel.send(0, current_people1);
					channel.send(4, current_people2);
					break;
				}
				case '5':
				{
					int current_people1 = channel.receive(3);
					int current_people2 = channel.receive(4);
					if (direction)
					{
						current_people1--;
						current_people2++;
					}
					else
					{
						current_people2--;
						current_people1++;
					}
					channel.send(3, current_people1);
					channel.send(4, current_people2);
					break;
				}
				case '6':
				{
					int current_people1 = channel.receive(3);
					if (direction)
					{
						current_people1++;
					}
					else
					{
						current_people1--;
					}
					channel.send(3, current_people1);
					break;
				}
				case '7':
				{
					int current_people1 = channel.receive(1);
					if (direction)
					{
						current_people1++;
					}
					else
					{
						current_people1--;
					}
					channel.send(1, current_people1);
					break;
				}
				case '8':
				{
					int current_people1 = channel.receive(1);
					if (direction)
					{
						current_people1++;
					}
					else
					{
						current_people1--;
					}
					channel.send(1, current_people1);
					break;
				}
				case '9':
				{
					int current_people1 = channel.receive(1);
					int current_people2 = channel.receive(3);
					if (direction)
					{
						current_people1--;
						current_people2++;
					}
					else
					{
						current_people2--;
						current_people1++;
					}
					channel.send(1, current_people1);
					channel.send(3, current_people2);
					break;
				}
				case 'p':
				{
					int current_people1 = channel.receive(0);
					int current_people2 = channel.receive(1);
					if (direction)
					{
						current_people1++;
						current_people2--;
					}
					else
					{
						current_people2++;
						current_people1--;
					}
					channel.send(0, current_people1);
					channel.send(1, current_people2);
					break;
				}
				default:
					break;
				}
				system("cls");
			}
			
		}
		});
	sc_start();
	keyboard_input.join();
	return 0;
}