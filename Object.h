#pragma once
#include "Shape.h"
#include <vector>

using namespace std;

class Object
{
public:
	Object();
	Object(Shape shape,char alphapixel,const vec2& pos);
	~Object();
	void generateGollisionPoint();
	void setPosition(const vec2& pos);
	void setShape(Shape shape,char alphaPixel);
	int getSize();
	vec2 at(int index);

private:
	char alphaPixel;
	vec2 position;
	Shape shape;
	size_t size;
	vector<vec2> collisionPoint;
};

