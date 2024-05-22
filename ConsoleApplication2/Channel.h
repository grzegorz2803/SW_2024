#ifndef CHANNEL_H
#define CHANNEL_H
#include <systemc.h>

SC_MODULE(Channel) {
public:
	SC_HAS_PROCESS(Channel);
	Channel(sc_module_name name);

}
#endif // !CHANNEL_H
