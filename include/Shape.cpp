#include "pch.h"
#include "Shape.h"
#include <fstream>

using namespace std;

Shape::Shape()
{

}


Shape::Shape(string filename)
{
	ifstream file(filename);
	if (file.is_open()) {

		string buffstring;

		file >> buffstring;
		if (buffstring == "settings:") {
			file >> buffstring;
			if (buffstring == "size:") {
				file >> this->size.x;
				file >> this->size.y;
				this->length = this->size.x * this->size.y;
			}
		}
		file >> buffstring;
		char buffchar;
		if (buffstring == "data:") {
			for (size_t i = 0; i < this->length; i++)
			{
				file >> buffchar;
				this->shape.push_back(buffchar);
			}
		}
	}
	file.close();
}

Shape::Shape(std::string left, std::string rigth, std::string up, std::string down) {
	this->setLeft(Shape(left));
	this->setRigth(Shape(rigth));
	this->setUp(Shape(up));
	this->setDown(Shape(down));
}

Shape::~Shape()
{
}

void Shape::loadFromFile(string filename) {

	ifstream file(filename);
	if (file.is_open()) {

		string buffstring;

		file >> buffstring;
		if (buffstring == "settings:") {
			file >> buffstring;
			if (buffstring == "size:") {
				file >> this->size.x;
				file >> this->size.y;
				this->length = this->size.x * this->size.y;
			}
		}
		file >> buffstring;
		char buffchar;
		if (buffstring == "data:") {
			for (size_t i = 0; i < this->length; i++)
			{
				file >> buffchar;
				this->shape.push_back(buffchar);
			}
		}
	}
	file.close();
}


const char* Shape::getData() {
	return shape.c_str();
}

void Shape::setPixel(const vec2& pos,char pixel) {
		
	if ((pos.x >= 0 && pos.x <= this->size.x) && (pos.y >= 0 && pos.y <= this->size.y))
	{
		shape[this->size.x * pos.y + pos.x] = pixel;
	}

}

void Shape::setSize(const vec2& sizes,char pixel) {

	size.x = sizes.x;
	size.y = sizes.y;
	length = size.x * size.y;

	shape.resize(length,pixel);
}

Shape Shape::setText(const std::string& text) {
	this->setSize(vec2(text.size(),1),' ');

	shape = text;
	
	return *this;
}

void Shape::setLeft(Shape shapes) {

	this->shape_left = shapes.getData();
	this->size_left.x = shapes.getSize().x;
	this->size_left.y = shapes.getSize().y;
}

void Shape::setRigth(Shape shapes) {

	this->shape_rigth = shapes.getData();
	this->size_rigth.x = shapes.getSize().x;
	this->size_rigth.y = shapes.getSize().y;

}

void Shape::setUp(Shape shapes) {

	this->shape_up = shapes.getData();
	this->size_up.x = shapes.getSize().x;
	this->size_up.y = shapes.getSize().y;

}

void Shape::setDown(Shape shapes) {

	this->shape_down = shapes.getData();
	this->size_down.x = shapes.getSize().x;
	this->size_down.y = shapes.getSize().y;

}

void Shape::Left() {

	this->shape = this->shape_left;
	this->size.x = this->size_left.x;
	this->size.y = this->size_left.y;
	this->length = this->size.x * this->size.y;

}

void Shape::Rigth() {

	this->shape = this->shape_rigth;
	this->size.x = this->size_rigth.x;
	this->size.y = this->size_rigth.y;
	this->length = this->size.x * this->size.y;
}

void Shape::Up() {

	this->shape = this->shape_up;
	this->size.x = this->size_up.x;
	this->size.y = this->size_up.y;
	this->length = this->size.x * this->size.y;
}

void Shape::Down() {

	this->shape = this->shape_down;
	this->size.x = this->size_down.x;
	this->size.y = this->size_down.y;
	this->length = this->size.x * this->size.y;
}