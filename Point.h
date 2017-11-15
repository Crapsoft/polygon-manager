#pragma once
class Point
{
private:
	double x;
	double y;
public:
	Point(double _x, double _y);
	Point();

	void setX(double _x);
	void setY(double _y);

	double getX();
	double getY();

	Point* operator+(Point& p2);
	Point* operator-(Point& p2);
	~Point();
};

