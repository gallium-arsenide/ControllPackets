#pragma once

#include <memory>
#include <vector>
#include "applyable.hpp"

enum class PacketType
{
    cofig,
    update
};

using byte = unsigned char;
using RawPacket = std::vector<byte>;

class Parser
{
public:
    virtual ~Parser() = default;
    virtual std::unique_ptr<Applyable> parse(const RawPacket &packet) = 0;
    virtual PacketType getType() const = 0;
};

template <PacketType type>
class TypedParser : public Parser
{
public:
    PacketType getType() const override
    {
        return type;
    }
};
