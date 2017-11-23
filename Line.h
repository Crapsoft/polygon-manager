#pragma once
#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;
class Line
{private:
	Point A;
	Point B;
	double distance;
public:
	Line(Point _A, Point _B);
	void setA(Point _A);
	void setB(Point _B);

	Point getA();
	Point getB();

	void countDistance();
	double getDistance();

	void drawLine()const;
	~Line();
};

