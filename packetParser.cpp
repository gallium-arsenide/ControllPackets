#include "packetParser.hpp"

PacketType PacketParser::getPacketType(const RawPacket &packet)
{
	return (PacketType)packet.front();
}

UpdatePacket PacketParser::parseAsUpdate(const RawPacket &packet)
{
	UpdatePacket update;
	update.line_id = packet[1];
	update.line_content.assign(packet.begin() + 1, packet.end());

	return update;
}

ConfigPacket PacketParser::parseAsCofig(const RawPacket &packet)
{
	ConfigPacket config;
	config.line_id = packet[1];
	config.line_color.r = packet[2];
	config.line_color.g = packet[3];
	config.line_color.b = packet[4];

	return config;
}