#include <systemc.h>
#include "CPU1.h"
#include "CPU2.h"
#include "Channel.h"
#include <thread>
#include <iostream>
#include <functional>
#include <cstdlib>
#include <conio.h>
bool direction = false; // zmienna dla kierunku 
char key; // zmienna dla klawisza z klawiatury 
// g³ówna funkcja programu
int sc_main(int, char* []) {
	Channel channel("channel"); // utworzenie kana³u komunikacyjnego 
	CPU1 cpu1("CPU1", channel); // utworzenie CPU1
	CPU2 cpu2("CPU2", channel); // utworzenie CPU2
	direction ? std::cout << "Kierunek: gora, lewo \n" : std::cout << "Kierunek: dol, prawo \n"; // wyœwietlamy kierunek 
	std::thread keyboard_input([&channel]() { // w¹tek obs³uguj¹cy wejœcie z klawiatury 
		
		while (true)
		{
			if (_kbhit()) { // oczekiwanie na klawisz 
				key = _getch(); // pobieranie klawisza
				
				if (key == 'k') { // zmiana kierunku jesli "k"
					direction = !direction;
					direction ? std::cout << "Kierunek: gora, lewo \n" : std::cout << "Kierunek: dol, prawo \n";
										continue;
				}
				if (key=='q') // zamkniêcie symulacji jeœli "q"
				{
					sc_stop();
					break;
				}
				// wymiana informacji z kana³em komunikacyjnym w zale¿noœci od wejœcia i kierunku 
				switch (key)
				{
				case '0':
				{
					int current_people = channel.receive(4);
					if (direction)
					{
						(current_people--)<0?current_people=-1:current_people; // zabezpieczenie przed ujemn¹ liczb¹ osób w pokoju 
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
						(current_people--)<0?current_people=-1:current_people;
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
						(current_people--)<0?current_people=-1:current_people;
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
						
						current_people2--;
						if (current_people2 < 0) { // zabezpieczenie przed przejsciem z pustego pokuju do innego 
							current_people2 = -1;

						}
						else
						{
							current_people1++;
						}
					}
					else
					{
						
						current_people1--;
						if (current_people1 < 0) {
							current_people1 = -1;
						}
						else
						{
							current_people2++;
						}
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
						if (current_people1 < 0) {
							current_people1 = -1;
						}
						else
						{
							current_people2++;
						}
					}
					else
					{
						current_people2--;
						if (current_people2 < 0) {
							current_people2 = -1;
						}
						else
						{
							current_people1++;
						}
					
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
						if (current_people1 < 0) {
							current_people1 = -1;
						}
						else
						{
							current_people2++;
						}
				
					}
					else
					{
						current_people2--;
						if (current_people2 < 0) {
							current_people2 = -1;
						}
						else
						{
							current_people1++;
						}
				
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
						(current_people1--)<0?current_people1=-1:current_people1;
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
						(current_people1--)<0?current_people1=-1:current_people1;
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
						(current_people1--)<0?current_people1=-1:current_people1;
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
						if (current_people1 < 0) {
							current_people1 = -1;
						}
						else
						{
							current_people2++;
						}
					
					}
					else
					{
						current_people2--;
						if (current_people2 < 0) {
							current_people2 = -1;
						}
						else
						{
							current_people1++;
						}
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
						current_people2--;
						if (current_people2 < 0) {
							current_people2 = -1;
						}
						else
						{
							current_people1++;
						}
					}
					else
					{
					
						current_people1--;
						if (current_people1 < 0) {
							current_people1 = -1;
						}
						else
						{
							current_people2++;
						}
					}
					channel.send(0, current_people1);
					channel.send(1, current_people2);
					break;
				}
				default:
					break;
				}
				system("cls"); // czyszczenie ekranu
			}
			
		}
		});
	sc_start(); // pocz¹tek symulacji 
	keyboard_input.join();
	return 0;
}