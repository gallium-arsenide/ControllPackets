#include "controller.hpp"
#include "packetParser.hpp"

#include <iostream>
#include <deque>
#include <vector>

int main()
{
	std::deque<std::vector<byte>> incoming_messages =
	{
		{0,0,255,0,0},
		{0,1,123,56,35},
		{1,0,49,50,51,0},
		{1,1,97,98,99,0}
	};
	
	Canvas canvas;
	Controller controller(canvas);

	UpdatePacket update;
	ConfigPacket config;

	while (!incoming_messages.empty())
	{
		switch (PacketParser::getPacketType(incoming_messages.front()))
		{
			case PacketType::cofig:
				config = PacketParser::parseAsCofig(incoming_messages.front());
				controller.applyPacket(config);
				break;
			case PacketType::update:
				update = PacketParser::parseAsUpdate(incoming_messages.front());
				controller.applyPacket(update);
				break;
			default:
				std::cout << "unknown packet type\n";
				return 1;
		}
		controller.draw();
		incoming_messages.pop_front();
	}
}