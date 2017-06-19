#include <iostream>
#ifndef COLOR_HPP
#define COLOR_HPP

struct Color
{
	Color();
	Color(float d);
	Color(float a, float b, float c);
	void setColor(float r, float g, float b);


	float r;
	float g;
	float b;
};


#endif