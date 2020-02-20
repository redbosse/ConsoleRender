#include "pch.h"
#include "Object.h"


Object::Object()
{
}

Object::Object(Shape shape, char alphapixel, const vec2& pos)
{
	this->position.x = pos.x;
	this->position.y = pos.y;

	this->shape = shape;
	this->alphaPixel = alphapixel;
}

Object::~Object()
{
}

void Object::generateGollisionPoint() {

	for (size_t i = 0; i < shape.getSize().y; i++)
	{
		for (size_t j = 0; j < shape.getSize().x; j++)
		{
			if (shape.getData()[i * shape.getSize().x + j] != alphaPixel)
			{
				this->collisionPoint.push_back(vec2(i + position.x, j + position.y));
				this->size++;
			}
		}
	}
	
}

void Object::setPosition(const vec2& pos) {

	this->position.x = pos.x;
	this->position.y = pos.y;
}

void Object::setShape(Shape shape,char alphaPixel) {

	this->shape = shape;
	this->alphaPixel = alphaPixel;
	

}

vec2 Object::at(int index) {

	return this->collisionPoint[index];
}

int Object::getSize() {

	return this->size;

}