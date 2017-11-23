#include "Line.h"
#include <Windows.h>
#include <stdlib.h>


Line::Line(Point _A, Point _B)
{
	A = _A;
	B = _B;
	countDistance();
}



void Line::setA(Point _A) {
	A = _A;
}
void Line::setB(Point _B) {
	B = _B;
}

Point Line::getA() {
	return A;
}

Point Line::getB() {
	return B;
}

void Line::countDistance() {
	 distance = sqrt(pow((B.getX() - A.getX()), 2) + pow((B.getY() - A.getY()), 2));
}

double Line::getDistance() {
	return distance;
}

//void Line::drawLine()const {
//	float x;
//	HDC hDC = GetDC(GetConsoleWindow());
//	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
//	SelectObject(hDC, Pen);
//	//MoveToEx(hDC, 0, 85, NULL);
//	//LineTo(hDC, 200, 85);
//	//MoveToEx(hDC, 100, 0, NULL);
//	//LineTo(hDC, 100, 170);
//	for (x = -8.0f; x <= 8.0f; x += 0.1f) // O(100,85) - center
//	{
//		double x1 = A.getX();
//		double y1 = A.getY();
//		MoveToEx(hDC, x1 + 100,y1 , NULL);//10 - scale
//		LineTo(hDC, 10 * x + 100,100);
//		//MoveToEx(hDC, 10 * x + 100,100, NULL);//10 - scale
//		//LineTo(hDC, 10 * x + 100,100);
//	}
//}
int main(){
	Line l(Point(3.4, 10), Point(2.3, 3.5));
	l.drawLine();
	system("pause");
	return 0;
}
Line::~Line()
{
}
