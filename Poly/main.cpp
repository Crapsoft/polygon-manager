#define _CRT_SECURE_NO_WARNINGS
#include "Polygonn.h"
#include <string>
#include <exception>

using namespace std;

void hello();
void help();
Polygonn add();
void print_db(vector<Polygonn> v);
void print_cur(int cur, vector<Polygonn> v);

int main()
{
	vector<Polygonn> database;

	int cur = 0;

	hello();

	string command;

	cin >> command;

	while (command != "-exit")
	{
		if (command == "-h")
		{
			help();
		}
		else if (command == "-add")
		{
			database.push_back(add());
		}
		else if (command == "-list")
		{
			print_db(database);
		}
		else if (command == "-cur")
		{
			print_cur(cur, database);
		}
		else if (command == "-sw")
		{
			cout << "Please enter the number of desired polygon: ";
			int in;
			try {
				cin >> in;
				if (in > database.size() || in < 1)
				{
					cout << "Out of range, try again" << endl << endl;
				}
				else
				{
					cur = in;
					cout << "Switched the current polygon to Poly " << cur << endl << endl;
				}
			}
			catch (exception e)
			{
				cout << "Invalid argument \n\n";
			}
		}
		else if (command == "-shiftX")
		{
			cout << "Please enter the OX shift value: ";
			double shift;
			cin >> shift;

			database[cur - 1].transfer_by_x(shift);
		}
		else if (command == "-shiftY")
		{
			cout << "Please enter the OY shift value: ";
			double shift;
			cin >> shift;

			database[cur - 1].transfer_by_y(shift);
		}
		else if (command == "-move")
		{
			double x, y;
			cout << "Please enter desired vector: ";
			cin >> x;
			cin >> y;
			database[cur - 1].transfer_by_point(Point(x,y));
		}
		else if (command == "-scale")
		{
			cout << "Please enter the scalar: ";
			double scalar;
			cin >> scalar;
			database[cur - 1].scale_by_scalar(scalar);
		}
		else if (command != "-exit")
		{
			cout << "Wrong command, please use PolyGon carefully ";
			cout << endl << endl;
		}
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "Thank you for using PolyGon 1.2.0!";
	cout << endl << endl;

	/*Point* p = new Point[4];
	p[0] = Point(0.0, 0.0);
	p[1] = Point(0.0, 1.0);
	p[2] = Point(1.0, 1.0);
	p[3] = Point(1.0, 0.0);

	Polygonn poly = Polygonn(p, 4);
	poly.print_points();

	poly.draw();

	poly.scale_by_scalar(1);
	poly.print_points();

	poly.draw();*/

	system("pause");
	delete[] p;

	return 0;

}

void hello()
{
	cout << "Welcome to PolyGon 1.2.0!" << endl;
	cout << "Type -h for additional help" << endl;
	cout << endl;
}

void help()
{
	cout << "-add       Add a new Polygon" << endl;
	cout << "-list      Display available polygons" << endl;
	cout << "-cur       Show the current polygon" << endl;
	cout << "-sw        Change the current polygon" << endl;
	cout << "-shiftX    Move the current Polygon by X axis" << endl;
	cout << "-shiftY    Move the current Polygon by Y axis" << endl;
	cout << "-move      Move the current Polygon by vector" << endl;
	cout << "-scale     Scale the current polygon by scalar" << endl;
	cout << "-h         Display help" << endl;
	cout << "-exit      Exit PolyGon" << endl;
}

Polygonn add()
{
	cout << "Yay, you can create you own polygon now!" << endl;
	cout << "Please input points until you want to stop, then type in \"S\"" << endl;
	vector<Point> temp;
	char x, y;
	while (true)
	{
		cin >> x;
		if (x == 'S')
		{
			break;
		}
		cin >> y;
		temp.push_back(Point(x, y));
	}

	Polygonn poly(temp);

	return poly;
}

void print_db(vector<Polygonn> v)
{
	cout << "Currently available polygons: " << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << "Poly" << (i + 1) << ':' << endl;
		v[i].print_points();
	}

	if (v.size() == 0)
	{
		cout << "There are no polygons available ";
	}

	cout << endl << endl;
}

void print_cur(int cur, vector<Polygonn> v)
{
	if (cur == 0)
	{
		cout << "No polygon currently selected " << endl << endl;
	}
	else
	{
		cout << "Poly " << cur << ':' << endl;
		v[cur - 1].print_points();
	}
}