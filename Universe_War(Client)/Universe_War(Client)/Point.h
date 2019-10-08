#pragma once
struct Point
{
	float x;
	float y;

	Point() :x{ 0 }, y{ 0 }{}
	Point(float x, float y) :x{ x }, y{ y }{}
	Point(const Point& other) :x{ other.x }, y{ other.y }{}

	Point operator+(const Point& rhs) const
	{
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator-(const Point& rhs) const
	{
		return Point(x - rhs.x, y - rhs.y);
	}
	Point& operator+=(const Point& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Point operator*(const float& f) const
	{
		return Point(x*f, y*f);
	} 
};

float Length(const Point& tmp);

bool Collision(const Point& a, const Point& b, float range);