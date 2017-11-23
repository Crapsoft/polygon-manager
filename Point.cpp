#include "Point.h"
#include <iostream>
using namespace std;
Point::Point(double _x, double _y) : x(_x), y(_y) {
}


Point::Point()
{
	this->x = 0.0;
	this->y = 0.0;
}

void Point::setX(double _x) {
	this->x = _x;
}


void Point::setY(double _y) {
	this->y = _y;
}

double Point::getX() {
	return x;
}


double Point::getY() {
	return y;
}

const Point Point::operator+(const Point& rhs) const {
	return Point(*this) += rhs;
}

const Point Point::operator-(const Point& rhs) const {
	return Point(*this) -= rhs;
}


Point& Point::operator+=(const Point& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}


Point& Point::operator-=(const Point& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}


Point& Point::operator++() { //prefix
	x++;
	y++;
	return *this;
}


Point& Point::operator--() { //prefix
	x--;
	y--;
	return *this;
}



Point::~Point()
{
}
