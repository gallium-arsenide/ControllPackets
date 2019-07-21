#pragma once

#include <memory>
#include <map>
#include "applyable.hpp"
#include "parser.hpp"

class PacketParser
{
public:
    PacketParser();
    std::unique_ptr<Applyable> parse(const RawPacket &packet);

private:
    std::map<PacketType, std::unique_ptr<Parser>> parsers;

    PacketType getPacketType(const RawPacket &packet);

//	static UpdatePacket parseAsUpdate(const RawPacket &packet);

//	static ConfigPacket parseAsCofig(const RawPacket &packet);
};
