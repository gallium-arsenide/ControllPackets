#pragma once

class Controller;

class Applyable
{
public:
    virtual ~Applyable() = default;
    virtual void applyTo(Controller&) = 0;
};
