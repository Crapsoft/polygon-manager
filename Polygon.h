#pragma once
#include "Point.h"
#include <iostream>
class Polygon
{
private:
	Point* points;
	int size;
public:
	Polygon(int _size);
	Polygon( Point* _points ,int _size);
	void transfer_by_x(int x);
	void transfer_by_y(int y);
	~Polygon();
};

