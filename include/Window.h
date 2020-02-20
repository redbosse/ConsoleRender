#pragma once
#include "vec2.h"
#include "Shape.h"

class Window
{
public:
	Window() {};
	Window(const vec2& winSize,const char& pixel);
	void setWindowSize(const vec2& sizeWindow);
	void setPixel(const vec2& pos,const char& pixel);
	char getPixel(const vec2& pos);
	char* getData();
	void draw(Shape shape, const vec2& position, const char& clear_sy);
	void clear();
	~Window();
private:
	char* winMatrix;
	char* clearMatrix;
	size_t length;
	vec2 windowSize;
};

