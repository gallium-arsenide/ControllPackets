#pragma once

#include "applyable.hpp"
#include "controller.hpp"

template <typename T>
class Wrapper : public Applyable
{
public:

    Wrapper(T packetInit) : packet{std::move(packetInit)}
    {
    }

    void applyTo(Controller& controller) override
    {
        controller.applyPacket(packet);
    }

private:
    T packet;
};
