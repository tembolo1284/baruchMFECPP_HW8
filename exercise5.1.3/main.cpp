#include <iostream>
#include <stdio.h>
#include <vector>
#include "boost/shared_ptr.hpp"
#include <boost/tuple/tuple.hpp>	// Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples
#include <boost/variant.hpp>
#include "boost/variant/static_visitor.hpp"
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
#include "Visitor.hpp"

using namespace std;
using namespace PAULLOPEZ::CAD;
using namespace PAULLOPEZ::CONTAINERS;
namespace PLC = PAULLOPEZ::CAD;
namespace PLCN = PAULLOPEZ::CONTAINERS;
typedef tuple<int, string, double> Person;
typedef boost::variant<Point, Line, Circle> ShapeVariant;

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


void printTuple(boost::tuple<int, string, double>& person) {
	cout << "Name: " << person.get<1>() << endl;
	cout << "Age: " << person.get<0>() << endl;
	cout << "Length: " << person.get<2>() << endl;
}

boost::variant<Point, Line, Circle> variantFunction() {
	char whatShape;
	cout << "What shape would you like to create: Point, Line, or a Circle? (p, l, c)" << endl;
	cin >> whatShape;
	bool checker = true;
	ShapeVariant functionVariant;
	while (checker) {
		if (whatShape == 'p') {
			double num1{};
			double num2{};
			cout << "Please enter two numbers to create coordinates of a point: " << endl;
			cin >> num1;
			cin >> num2;
			Point pt(num1, num2);
			functionVariant = pt;
			checker = false;
			cout << "Your point is: ";
			return functionVariant;
		}
		else if (whatShape == 'l') {
			double num1{}, num2{}, num3{}, num4{};
			cout << "Please enter four numbers to create coordinates of two points for a line: " << endl;
			cin >> num1;
			cin >> num2;
			cin >> num3;
			cin >> num4;
			Line l1(Point(num1, num2), Point(num3, num4));
			functionVariant = l1;
			checker = false;
			cout << "Your Line has following start and end points: ";
			return functionVariant;
		}
		else if (whatShape == 'c') {
			double num1{}, num2{}, num3{};
			cout << "Please enter three numbers: one for the radius and the other for the center point of a circle: " << endl;
			cin >> num1;
			cin >> num2;
			cin >> num3;
			Circle c1(num1, Point(num2, num3));
			functionVariant = c1;
			checker = false;
			cout << "Your Circle has the following characteristics: ";
			return functionVariant;
		}
		else {
			cout << "You didn't enter a valid input." << endl;
			checker = false;
			return functionVariant;
		}
	}

}

int main() {
	using boost::variant;
	//typedef variant<Point, Line, Circle> ShapeVariant;

	Visitor<double> Visitor(2.5, 1.5);
	Point myPoint(1.5,2.0);
	Line myLine(Point(0, 1), myPoint);
	Circle myCircle(2.0, myPoint);

	ShapeVariant myVariant1(myPoint);
	ShapeVariant myVariant2(myLine);
	ShapeVariant myVariant3(myCircle);

	//test visitor on pt (move point)
	cout << "Pt Variant BEFORE move: " << myVariant1 << endl;
	boost::apply_visitor(Visitor, myVariant1);
	cout << "Pt Variant AFTER move: " << myVariant1 << endl;
	cout << "-----Just another way to print out info I thought was cool-----" << endl;
	myPoint = boost::get<Point>(myVariant1);
	cout << "Point after move is: (" << myPoint.X() << "," << myPoint.Y()<<")." << std::endl;
	cout << "--------------------------" << endl;
	//test visitor on line (move start and end points)
	cout << "Line Variant BEFORE move: " << myVariant2 << endl;
	boost::apply_visitor(Visitor, myVariant2);
	cout << "Line Variant AFTER move: " << myVariant2 << endl;

	//test visitor on cirlce (move center of circle)
	cout << "Circle Variant BEFORE move: " << myVariant3 << endl;
	boost::apply_visitor(Visitor, myVariant3);
	cout << "Circle Variant AFTER move: " << myVariant3 << endl;

	
	//cout << variantFunction() << endl; //to test prompt from function separately


	Point ptFromVariant;
	Line lFromVariant;
	Circle cFromVariant;

	try {
		ptFromVariant = boost::get<Point>(variantFunction()); //only works if I choose point in prompt
		//lFromVariant = boost::get<Line>(variantFunction()); //only works if I choose line in prompt
		//cFromVariant = boost::get<Circle>(variantFunction()); //only works if I choose circle in prompt
		cout << "Point from Variant: " << ptFromVariant << endl;
		cout << "Line from Variant: " << lFromVariant << endl;
		cout << "Circle from Variant: " << cFromVariant << endl;
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl;
	}
	return 0;

}