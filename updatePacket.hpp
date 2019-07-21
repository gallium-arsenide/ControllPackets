#pragma once

#include <string>

struct UpdatePacket
{
	size_t line_id;
	std::string line_content;
};