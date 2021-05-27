#include <iostream>
using namespace std;

//#define DEBUG

struct Axis { int x; int y; } axis1, axis2;

void GetP1xy(Axis& axis1)
{
	cout << "Enter x1:";
	cin >> axis1.x;
	cout << "Enter y1:";
	cin >> axis1.y;
}

void GetP2xy(Axis& axis2)
{
	cout << "Enter x2:";
	cin >> axis2.x;
	cout << "Enter y2:";
	cin >> axis2.y;
}

bool CompareAxis(Axis& axis1, Axis& axis2)
{
	return axis1.x == axis2.x || axis1.y == axis2.y;
}

void PrintResult(bool parallel)
{
	cout << "Line is " << (!parallel ? "not " : "") << "parallel" << endl;
}

int main()
{
	GetP1xy(axis1);
	GetP2xy(axis2);

#ifdef DEBUG
	cout << axis1.x << endl << axis1.y << endl << axis2.x << endl << axis2.y << endl;
#endif // DEBUG

	PrintResult(CompareAxis(axis1, axis2));
}