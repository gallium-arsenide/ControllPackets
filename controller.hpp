#pragma once

#include "updatePacket.hpp"
#include "configPacket.hpp"
#include "canvas.hpp"

#include <vector>
#include <string>

struct TextLine
{
	std::string content;
	Color color;
};

class Controller
{
private:
	std::vector<TextLine> textLines;
	Canvas &canvas;

public:

	Controller(Canvas &canvas);

	void applyPacket(const UpdatePacket &update);

	void applyPacket(const ConfigPacket &config);

	void draw();
};