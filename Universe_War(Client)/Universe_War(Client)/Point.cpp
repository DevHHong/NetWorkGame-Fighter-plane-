#include "stdafx.h"
#include"Point.h"

float Length(const Point& tmp)
{
	return	sqrtf(tmp.x*tmp.x + tmp.y*tmp.y);
}

bool Collision(const Point& a, const Point& b, float range)
{
	if (Length(a - b) < range)
		return true;
	else
		return false;
}

