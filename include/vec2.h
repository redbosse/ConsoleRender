#pragma once
class vec2
{
public:
	vec2() {}
	vec2(short x, short y) :x(x), y(y) {}
	vec2(const vec2& vec) { x = vec.x; y = vec.y; }

	vec2 operator+(const vec2& v) {
		return vec2(x + v.x, y + v.y);
	}
	vec2 operator-(const vec2& v) {
		return vec2(x - v.x, y - v.y);
	}
	vec2& operator=(const vec2& v) {
		this->x = v.x;
		this->y = v.y;
		return *this;
	}

	short x = 0, y = 0;

};

