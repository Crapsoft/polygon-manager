#include "Point.h"

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

Point* Point::operator+( Point& p2) {
	Point* new_point = new Point();
	double new_x = this->x + p2.getX();
	double new_y = this->y + p2.getY();
	return new Point(new_x, new_y);
}

Point* Point::operator-(Point& p2) {
	Point* new_point = new Point();
	double new_x = this->x - p2.getX();
	double new_y = this->y - p2.getY();
	return new Point(new_x, new_y);
}


Point::~Point()
{
}
