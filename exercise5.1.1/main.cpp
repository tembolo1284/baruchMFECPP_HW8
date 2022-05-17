#include <iostream>
#include <stdio.h>
#include <vector>
#include "boost/shared_ptr.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"
#include "PointArray.hpp"
#include "NumericArray.hpp"
#include "Stack.hpp"

using namespace std;
using namespace PAULLOPEZ::CAD;
using namespace PAULLOPEZ::CONTAINERS;
namespace PLC = PAULLOPEZ::CAD;
namespace PLCN = PAULLOPEZ::CONTAINERS;
void print(const Point& pnt) {
	cout << "Your point is: (" << pnt.X() << "," << pnt.Y() << ")" << endl;
}
void print(const Line& l) {
	l.start();
	l.end();
}
void print(const Circle& c) {
	cout << endl << "Radius is: " << c.rad() << endl;
	Point pnt = c.ctr();
	cout << "X coordinate of center is: " << pnt.X() << endl;
	cout << "Y coordinate of center is: " << pnt.Y() << endl;
}

int main() {
	typedef boost::shared_ptr<Shape> ShapePtr;
	Array<ShapePtr> ShapeArray(3);
	ShapePtr Ptr1(new Point(2.1, 3.5));
	ShapePtr Ptr2(new Line(Point(1.2, 0.75), Point(-1, -2)));
	ShapePtr Ptr3(new Circle(2.5, Point(1, 1)));

	ShapeArray.SetElement(Ptr1, 0);
	ShapeArray.SetElement(Ptr2, 1);
	ShapeArray.SetElement(Ptr3, 2);

	Ptr1->Print();
	Ptr2->Print();
	Ptr3->Print();
	cout << "Address of first element: " << ShapeArray.GetElement(0) << endl;
	cout << "Address of second element: " << ShapeArray.GetElement(1) << endl;
	cout << "Address of third element: " << ShapeArray.GetElement(2) << endl;

	return 0;

}