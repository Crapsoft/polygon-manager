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

void Polygon::transfer_by_x(int x){
	if (points!=NULL)
	{
		for (int i = 0; i < size; i++)
		{
			int old_x = points[i].getX();
			points[i].setX(old_x + x);
		}
	}
}
Polygon::~Polygon()
{
}
