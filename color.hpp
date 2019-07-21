#pragma once

using byte = unsigned char;

struct Color
{
	byte r, g, b;

	Color()
	{
		r = g = b = 0;
	}
};