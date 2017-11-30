#include "Polygonn.h"
#include "Point.h"

using namespace std;

int main()
{
	Point* p = new Point[4];
	p[0] = Point(0.0, 0.0);
	p[1] = Point(0.0, 1.0);
	p[2] = Point(1.0, 1.0);
	p[3] = Point(1.0, 0.0);

	Polygonn poly = Polygonn(p, 4);

		
	delete[] p;

	return 0;

}
