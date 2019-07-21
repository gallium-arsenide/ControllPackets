#include "updatePacket.hpp"
#include "configPacket.hpp"
#include "packetParser.hpp"
#include "wrapper.hpp"

class UpdateParser : public TypedParser<PacketType::update>
{
    std::unique_ptr<Applyable> parse(const RawPacket &packet) override
    {
        UpdatePacket update;
        update.line_id = packet[1];
        update.line_content.assign(packet.begin() + 1, packet.end());

        return std::make_unique<Wrapper<UpdatePacket>>(update);
    }
};

class ConfigParser : public TypedParser<PacketType::cofig>
{
    std::unique_ptr<Applyable> parse(const RawPacket &packet) override
    {
        ConfigPacket config;
        config.line_id = packet[1];
        config.line_color.r = packet[2];
        config.line_color.g = packet[3];
        config.line_color.b = packet[4];

        return std::make_unique<Wrapper<ConfigPacket>>(config);
    }
};

PacketType PacketParser::getPacketType(const RawPacket &packet)
{
    return static_cast<PacketType>(packet.front());
}

PacketParser::PacketParser()
{
    parsers.insert({PacketType::update, std::make_unique<UpdateParser>()});
    parsers.insert({PacketType::cofig, std::make_unique<ConfigParser>()});
}

std::unique_ptr<Applyable> PacketParser::parse(const RawPacket &packet)
{
    auto parser = parsers.find(getPacketType(packet));

    if (parser == parsers.end())
    {
        // error, throw, return empty packet or something
        return nullptr;
    }

    return parser->second->parse(packet);
}
