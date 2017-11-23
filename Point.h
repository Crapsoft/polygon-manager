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

	const Point operator+(const Point& rhs) const;
	const Point operator-(const Point& rhs) const;
	Point& operator+=(const Point& rhs);
	Point& operator-=(const Point& rhs);
	Point& operator++();
	Point& operator--();

	~Point();
};

