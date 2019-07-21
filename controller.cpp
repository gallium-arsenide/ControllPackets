#include "controller.hpp"


Controller::Controller(Canvas &canvas):canvas(canvas)
{}

void Controller::applyPacket(const UpdatePacket &update)
{
	if (update.line_id >= textLines.size())
		return;

	textLines[update.line_id].content = update.line_content;
}

void Controller::applyPacket(const ConfigPacket &config)
{
	if (config.line_id >= textLines.size())
		textLines.resize(config.line_id + 1);

	textLines[config.line_id].color = config.line_color;
}

void Controller::draw()
{
	for (const auto &line : textLines)
	{
		canvas.drawText(line.content);
	}
}