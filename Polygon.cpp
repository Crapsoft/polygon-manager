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

void Polygon::draw() {
	POINT op;
	HWND Desc = GetConsoleWindow();
	HDC hDC = GetDC(Desc);
	SelectObject(hDC, GetStockObject(WHITE_PEN));
	MoveToEx(hDC, 600, 0, &op);
	//тут малюю декартову площину
	LineTo(hDC, 600, 600);
	MoveToEx(hDC, 200, 300, &op);
	LineTo(hDC, 1000, 300);
	ReleaseDC(Desc, hDC);
	//міняю колір ручки
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hDC, pen);
	//з першої точки до останньої
	MoveToEx(hDC, points[0].getX() + 600, fabs(points[0].getY() - 300), &op);
	LineTo(hDC, points[size - 1].getX() + 600, fabs(points[size - 1].getY() - 300));
	//від першої по порядку до size - 1, бо лінія між першою і останньою вже намальвана
	for (int i = 0; i < size - 1; i++)
	{
		MoveToEx(hDC, points[i].getX() + 600, fabs(points[i].getY() - 300), &op);
		LineTo(hDC, points[i+1].getX() + 600, fabs(points[i+1].getY() - 300));
	}
}


Polygon::~Polygon()
{
}



