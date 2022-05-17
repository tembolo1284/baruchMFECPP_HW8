#include <iostream>
#include <stdio.h>
#include <vector>
#include "boost/shared_ptr.hpp"
#include <boost/tuple/tuple.hpp>	// Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples
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
typedef tuple<int, string, double> Person;

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

void printPerson1(int i, string s, double d) {
	cout << "Age of " << s << " is: " << i << "." << endl;
	cout << "Length of " << s << " is: " << d << "." << endl;
}

void printTuple(boost::tuple<int, string, double>& person) {
	cout << "Name: " << person.get<1>() << endl;
	cout << "Age: " << person.get<0>() << endl;
	cout << "Length: " << person.get<2>() << endl;
}

int main() {
	// Using declaration, for readability purposes
	using boost::tuple;
	// Creating tuples
	typedef tuple<int, string, double> Person;

	Person guy1(25, "John", 185);
	Person lady1(30, "Valeria", 150.5);
	

	int firstGuy = guy1.get<0>();
	string secondGuy = guy1.get<1>();
	double thirdGuy = guy1.get<2>();

	int firstLady = lady1.get<0>();
	string secondLady= lady1.get<1>();
	double thirdLady = lady1.get<2>();
	// Print the tuple
	cout << guy1 << endl;

	printTuple(guy1);
	cout << "_______________________" << endl;
	printTuple(lady1);
	//make lady younger and man older (of course!)
	guy1.get<0>() = 45;
	lady1.get<0>() = 21;
	cout << "_______________________" << endl;

	//print with new age
	printTuple(guy1);
	cout << "_______________________" << endl;
	printTuple(lady1);

	return 0;

}