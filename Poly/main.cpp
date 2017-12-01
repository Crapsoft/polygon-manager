#define _CRT_SECURE_NO_WARNINGS
#include "Polygonn.h"
#include <string>
#include <exception>
#include <cstdlib>

using namespace std;

void hello();
void help();
Polygonn* add();
void print_db(vector<Polygonn*> v);
void print_cur(int cur, vector<Polygonn*> v);
int swichh(vector<Polygonn*> v);
void shiftX(vector<Polygonn*> v, int cur);
void shiftY(vector<Polygonn*> v, int cur);
void move(vector<Polygonn*> v, int cur);
void scale(vector<Polygonn*> v, int cur);


int main()
{
	vector<Polygonn*> database;

	int cur = 0;

	hello();

	string command;

	cin >> command;

	vector<Point> temp;
	string x, y;

	while (command != "-exit")
	{
		if (command == "-h")
		{
			help();
		}
		else if (command == "-add")
		{
			cout << "Yay, you can create you own polygon now!" << endl;
			cout << "Please input points until you want to stop, then type in \"S\"" << endl;
			
			while (temp.size() > 0)
			{
				temp.pop_back();
			}

			while (true)
			{
				cin >> x;
				if (x == "S")
				{
					break;
				}
				cin >> y;
				temp.push_back(Point(stod(x), stod(y)));
			}

			Polygonn *poly = new Polygonn(temp);
			
			database.push_back(poly);

			cout << "Created new polygon";
			cout << endl << endl;
		}
		else if (command == "-list")
		{
			cout << "Currently available polygons: " << endl;

			for (int i = 0; i < database.size(); i++)
			{
				cout << "Poly" << (i + 1) << ':' << endl;
				database[i]->print_points();
			}

			if (database.size() == 0)
			{
				cout << "There are no polygons available ";
				cout << endl << endl;
			}			
		}
		else if (command == "-cur")
		{
			print_cur(cur, database);
		}
		else if (command == "-sw")
		{
			cur = swichh(database);
		}
		else if (command == "-shiftX")
		{
			shiftX(database, cur);
		}
		else if (command == "-shiftY")
		{
			shiftY(database, cur);
		}
		else if (command == "-move")
		{
			move(database, cur);
		}
		else if (command == "-scale")
		{
			scale(database, cur);
		}
		else if (command != "-exit")
		{
			cout << "Wrong command, please use PolyGon carefully ";
			cout << endl << endl;
		}

		cout << '>';
		cin >> command;
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "Thank you for using PolyGon 1.2.0!";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << endl << endl;

	system("pause");
	

	return 0;

}

void hello()
{
	cout << "Welcome to PolyGon 1.2.0!" << endl;
	cout << "Type -h for additional help" << endl;
	cout << endl;
	cout << '>';
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
	cout << endl << endl;
}

Polygonn* add()
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
			cout << "Created new polygon";
			cout << endl << endl;
			break;
		}
		cin >> y;
		temp.push_back(Point(x, y));
	}

	Polygonn *poly = new Polygonn(temp);

	return poly;
}

void print_db(vector<Polygonn*> v)
{
	cout << "Currently available polygons: " << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << "Poly" << (i + 1) << ':' << endl;
		v[i]->print_points();
	}

	if (v.size() == 0)
	{
		cout << "There are no polygons available ";
	}

	cout << endl << endl;
}

void print_cur(int cur, vector<Polygonn*> v)
{
	if (cur == 0)
	{
		cout << "No polygon currently selected ";
		cout << endl << endl;
	}
	else
	{
		cout << "Poly " << cur << ':' << endl;
		v[cur - 1]->print_points();
	}
	
}

int swichh(vector<Polygonn*> v)
{
	cout << "Please enter the number of desired polygon: ";
	int in;
	try {
		cin >> in;
		if (in > v.size() || in < 1)
		{
			cout << "Out of range, try again" << endl << endl;
		}
		else
		{
			cout << "Switched the current polygon to Poly " << in << endl << endl;
			return in;
		}
	}
	catch (exception e)
	{
		cout << "Invalid argument \n\n";
	}
}

void shiftX(vector<Polygonn*> v, int cur)
{
	if (cur == 0)
	{
		cout << "No polygon chosen!!";
		cout << endl << endl;
		return;
	}

	cout << "Please enter the OX shift value: ";
	double shift;
	cin >> shift;

	v[cur - 1]->transfer_by_x(shift);

	cout << "Operation successfull" << endl << endl;
}

void shiftY(vector<Polygonn*> v, int cur)
{
	if (cur == 0)
	{
		cout << "No polygon chosen!!";
		cout << endl << endl;
		return;
	}

	cout << "Please enter the OY shift value: ";
	double shift;
	cin >> shift;

	v[cur - 1]->transfer_by_y(shift);

	cout << "Operation successfull" << endl << endl;
}

void move(vector<Polygonn*> v, int cur)
{
	if (cur == 0)
	{
		cout << "No polygon chosen!!";
		cout << endl << endl;
		return;
	}

	double x, y;
	cout << "Please enter desired vector: ";
	cin >> x;
	cin >> y;
	v[cur - 1]->transfer_by_point(Point(x, y));

	cout << "Operation successfull" << endl << endl;
}

void scale(vector<Polygonn*> v, int cur)
{
	if (cur == 0)
	{
		cout << "No polygon chosen!!";
		cout << endl << endl;
		return;
	}

	cout << "Please enter the scalar: ";
	double scalar;
	cin >> scalar;
	v[cur - 1]->scale_by_scalar(scalar);

	cout << "Operation successfull" << endl << endl;
}