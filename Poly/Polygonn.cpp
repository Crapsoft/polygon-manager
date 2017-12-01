#pragma once
#include "Polygonn.h"

using namespace std;

Polygonn::Polygonn()
{

}

Polygonn::Polygonn(int _size)
{
	size = _size;
	points = new Point[size];	
}


Polygonn::Polygonn(Point* _points, int _size) {
	size = _size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = _points[i];
	}
}

Polygonn::Polygonn(vector<Point> _points)
{
	size = _points.size();
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = _points[i];
	}
}

void Polygonn::transfer_by_x(double x){
	if (points!=NULL)
	{
		for (int i = 0; i < size; i++)
		{
			double old_x = points[i].getX();
			points[i].setX(old_x + x);
			
		}
	}
}

void Polygonn::transfer_by_y(double y) {
	if (points != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			double old_y = points[i].getY();
			points[i].setY(old_y + y);
			
		}
	}
}

void Polygonn::transfer_by_point(Point& p) {
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

void Polygonn::scale_by_scalar(double scalar)
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
		points[i].setX(center.getX() + delta_x * scalar);

		double delta_y = points[i].getY() - center.getY();
		points[i].setY(center.getY() + delta_y * scalar);
	}
}

void Polygonn::print_points() const
{
	for (int i = 0; i < size; i++)
	{
		points[i].print_point();
	}
	cout << endl << endl;
}

void Polygonn::draw() {
	POINT op;
	HWND Desc = GetConsoleWindow();
	HDC hDC = GetDC(Desc);
	SelectObject(hDC, GetStockObject(WHITE_PEN));
	MoveToEx(hDC, 600, 0, &op);
	LineTo(hDC, 600, 600);

	MoveToEx(hDC, 200, 300, &op);
	LineTo(hDC, 1000, 300);
	ReleaseDC(Desc, hDC);

	for (int i = 0; i < size; i++)
	{
		POINT op;
		HWND Desc = GetConsoleWindow();
		HDC hDC = GetDC(Desc);
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		SelectObject(hDC, pen);
		MoveToEx(hDC, points[i].getX() + 600, fabs(points[i].getY() - 300), &op);
		LineTo(hDC, points[i+1].getX() + 600, fabs(points[i + 1].getY() - 300));
		ReleaseDC(Desc, hDC);
	}
}


Polygonn::~Polygonn()
{
	delete[] points;
}



