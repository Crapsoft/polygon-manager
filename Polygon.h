#pragma once
#include "Point.h"
#include <iostream>
#include <windows.h>

using namespace std;

class Polygon
{
private:
	Point* points;
	int size;
public:
	Polygon(int _size);
	Polygon( Point* _points ,int _size);
	void transfer_by_x(double x);
	void transfer_by_y(double y);
	void transfer_by_point(Point& p);
	void scale_by_scalar(double scalar);
	void print_points()const;
	void draw();
	~Polygon();
};

