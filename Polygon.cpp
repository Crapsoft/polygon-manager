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

void Polygon::scale_by_scalar(double scalar)
{
	double avg_x = 0;
	double avg_y = 0;

	for (int i = 0; i < size; i++)
	{
		avg_x += points[i].getX();
		avg_y += points[i].getY();
	}

	avg_x /= size;
	avg_y /= size;

	Point center = Point(avg_x, avg_y);

	for (int i = 0; i < size; i++)
	{
		double delta_x = points[i].getX() - center.getX();
		points[i].setX(points[i].getX() + delta_x * scalar);

		double delta_y = points[i].getY() - center.getY();
		points[i].setY(points[i].getY() + delta_y * scalar);
	}
}

void Polygon::print_points() const
{
	for (int i = 0; i < size; i++)
	{
		points[i].print_point();
	}
	cout << endl << endl;
}


Polygon::~Polygon()
{
}


void main() {
	Point *p = new Point[5];
	p[0] = Point(0, 0);
	p[1] = Point(3, 0);
	p[2] = Point(3, 3);
	p[3] = Point(1.5, 4.5);
	p[4] = Point(0, 3);

	Polygon poly = Polygon(p, 5);
	cout << "Initial polygon: \n";
	poly.print_points();
	
	poly.scale_by_scalar(2);
	cout << "Multiplied by 2: \n";
	poly.print_points();

	poly.transfer_by_point(Point(2,4));
	cout << "+ (2, 4): \n";
	poly.print_points();
	
	delete [] p;

	system("pause");

}
