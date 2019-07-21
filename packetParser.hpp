#pragma once

#include "updatePacket.hpp"
#include "configPacket.hpp"

#include <vector>

using RawPacket = std::vector<byte>;

enum class PacketType
{
	cofig,
	update
};

class PacketParser
{
public:
	static PacketType getPacketType(const RawPacket &packet);

	static UpdatePacket parseAsUpdate(const RawPacket &packet);

	static ConfigPacket parseAsCofig(const RawPacket &packet);
};