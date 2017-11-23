#include "Polygon.h"


Polygon::Polygon(int _size)
{
	size = _size;
	points = new Point[size];	
}


Polygon::Polygon(Point* _points, int _size) {
	size = _size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = _points[i];
	}
}

void Polygon::transfer_by_x(double x){
	if (points!=NULL)
	{
		for (int i = 0; i < size; i++)
		{
			double old_x = points[i].getX();
			points[i].setX(old_x + x);
			
		}
	}
}

void Polygon::transfer_by_y(double y) {
	if (points != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			double old_y = points[i].getY();
			points[i].setY(old_y + y);
			
		}
	}
}

void Polygon::transfer_by_point(Point& p) {
	if (points != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			double old_y = points[i].getY();
			double old_x = points[i].getX();
			points[i].setY(old_y + p.getY());
			points[i].setX(old_x + p.getX());
		}
	}
}

//void main() {
//	Point* p = new Point[5];
//	for (int i = 0; i < 5; i++)
//	{
//		Point point(1.0, 1.0);
//		p[i] = point;
//	}
//	Polygon *polygon = new Polygon(p, 5);
//	polygon->transfer_by_point(Point(2,4));
//	system("pause");
//
//}
Polygon::~Polygon()
{
}
