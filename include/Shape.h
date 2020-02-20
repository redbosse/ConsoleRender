#pragma once
#include "vec2.h"
#include <string>

class Shape
{
public:
	 Shape();
	 Shape(std::string filename);
	 Shape(std::string filename1, std::string filename2, std::string filename3, std::string filename4);
	 void loadFromFile(std::string filename);
	 const char* getData();
	 vec2 getSize() { return size; }
	 size_t getLength() { return length; }
	 void setPixel(const vec2& pos,char pixel);
	 void setSize(const vec2& size,char pixel);
	 Shape setText(const std::string& text);

	 void setLeft(Shape shapes);
	 void setRigth(Shape shapes);
	 void setUp(Shape shapes);
	 void setDown(Shape shapes);

	 void Left();
	 void Rigth();
	 void Up();
	 void Down();


	 ~Shape();
private:
	std::string shape;

	std::string shape_left;
	vec2 size_left;

	std::string shape_rigth;
	vec2 size_rigth;

	std::string shape_up;
	vec2 size_up;

	std::string shape_down;
	vec2 size_down;

	vec2 size;
	size_t length = 0;
};

