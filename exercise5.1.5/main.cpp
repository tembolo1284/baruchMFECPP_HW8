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
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
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
	using namespace boost::math;
	double lambda{ 2.0 }; //lambda # of events
	double scaleParameter = 0.5;
	poisson_distribution<> myPoisson(lambda);
	exponential_distribution<> myExponential(scaleParameter);

	cout << "Mean of Poisson: " << mean(myPoisson) << ", std dev of Poisson: " << standard_deviation(myPoisson) << endl;
	cout << "Mean of Exponential: " << mean(myExponential) << ", std dev of Exponential: " << standard_deviation(myExponential) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf Poisson: " << pdf(myPoisson, x) << endl;
	cout << "cdf Poisson: " << cdf(myPoisson, x) << endl;

	cout << "pdf Exponential: " << pdf(myExponential, x) << endl;
	cout << "cdf Exponential: " << cdf(myExponential, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n*******Poisson distribution*******: \n";
	cout << "mean: " << mean(myPoisson) << endl;
	cout << "variance: " << variance(myPoisson) << endl;
	cout << "median: " << median(myPoisson) << endl;
	cout << "mode: " << mode(myPoisson) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
	cout << "kurtosis: " << kurtosis(myPoisson) << endl;
	cout << "characteristic function: " << chf(myPoisson, x) << endl;
	cout << "hazard: " << hazard(myPoisson, x) << endl;

	cout << "\n*******Exponential distribution*******: \n";
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;

	double val = 13.0;
	cout << endl << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;
	vector<double> pdfList;
	vector<double> cdfList;
	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j){
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));
		val += h;
	}
	for (long j = 0; j < pdfList.size(); ++j) {
		cout << pdfList[j] << ", ";
	}
	cout << "\n";
	cout << "------------------------------" << endl;

	for (long j = 0; j < cdfList.size(); ++j){
		cout << cdfList[j] << ", ";
	}
	return 0;

}