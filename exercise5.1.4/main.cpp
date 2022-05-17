#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <iomanip>
//Boost libraries
#include "boost/shared_ptr.hpp"
#include <boost/tuple/tuple.hpp>	// Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples
#include <boost/variant.hpp>
#include "boost/variant/static_visitor.hpp"
#include <boost/random.hpp> // Convenience header file
#include <boost/Random/detail/const_mod.hpp> 
//Boost libs end
#include <ctime>// std::time
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
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);
	
	map<int, double> statistics; // Structure to hold outcome + frequencies
	int outcome{}, rolls{1000}; // Current outcome and how many rolls of die
	double cnt1{}, cnt2{}, cnt3{}, cnt4{}, cnt5{}, cnt6{}; // counts for each face of die
	
	for (int i = 0; i < rolls; i++) {
		outcome = six(myRng);
		switch (outcome) {
		case 1:
			cnt1 += 1;
			continue;
		case 2:
			cnt2 += 1;
			continue;
		case 3:
			cnt3 += 1;
			continue;
		case 4:
			cnt4 += 1;
			continue;
		case 5:
			cnt5 += 1;
			continue;
		case 6:
			cnt6 += 1;
			continue;
		default:
			cout << "Houston we have a problem.";
		}
	}
	
	statistics[1] = cnt1 / rolls;
	statistics[2] = cnt2 / rolls;
	statistics[3] = cnt3 / rolls;
	statistics[4] = cnt4 / rolls;
	statistics[5] = cnt5 / rolls;
	statistics[6] = cnt6 / rolls;
	double sum = statistics[1] + statistics[2] + statistics[3] + statistics[4] + statistics[5] + statistics[6];

	cout << "Total rolls: " << rolls << endl;
	cout << "For Value 1 we have: " << fixed << setprecision(5) << statistics[1] << "%" << endl;
	cout << "For Value 2 we have: " << fixed << setprecision(5) << statistics[2] << "%" << endl;
	cout << "For Value 3 we have: " << fixed << setprecision(5) << statistics[3] << "%" << endl;
	cout << "For Value 4 we have: " << fixed << setprecision(5) << statistics[4] << "%" << endl;
	cout << "For Value 5 we have: " << fixed << setprecision(5) << statistics[5] << "%" << endl;
	cout << "For Value 6 we have: " << fixed << setprecision(5) << statistics[6] << "%" << endl;
	cout << "Total sum of percentages: " << fixed << setprecision(1) << sum * 100 << "%" << endl;
	
	return 0;

}