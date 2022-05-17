#define _USE_MATH_DEFINES
#include "Point.hpp"
#include <cmath>
#include <sstream>
using namespace std;

namespace PAULLOPEZ {
	namespace CAD {
	Point::Point() : x(0), y(0), Shape() {
			//cout << "Default POINT constructor says hello to you." << endl;
	}

		Point::Point(double newX_val, double newY_val) : x(newX_val), y(newY_val), Shape() {
			//cout << "This is another POINT constructor." << endl;
		}

		Point::Point(const Point& pt) : x(pt.x), y(pt.y), Shape(pt) {
			//x = pt.x;
			//y = pt.y;
			//cout << "Copy POINT constructor says Hello to you." << endl;
		}

		Point::Point(double bothVals) : x(bothVals), y(bothVals), Shape() { //new constructor for the exercise
			//x = newX_val;
			//y = newY_val; //initialize new x and y values
			//cout << "This is another POINT constructor." << endl;
		}

		Point::~Point() {
			cout << "See you later POINT..." << endl;
		}


		string Point::ToString() const {
			std::string s = Shape::ToString();
			stringstream pnt;
			pnt << s << ", Point(" << x << "," << y << ")" << endl;
			//cout << pnt.str();
			return pnt.str();
		}

		double Point::Distance() const {
			double result = sqrt(pow(x, 2.0) + pow(y, 2.0)); //(x^2 + y^2)^.05
			return result;
		}

		double Point::Distance(Point& p1) const {
			double result = sqrt(pow(x - p1.x, 2.0) + pow(y - p1.y, 2.0)); // ((x2-x1)^2 + (y2-y1)^2)^0.5
			return result;

		}

		Point Point::operator - () const { // Negate the coordinates.
			return Point(-x, -y);
		}

		Point Point::operator * (double factor) const {  // Scale the coordinates.
			return Point(x * factor, y * factor);
		}
		Point Point::operator + (const Point& p) const {// Add coordinates.
			Point result;
			result.x = x + p.x;
			result.y = y + p.y;
			return result;
		}
		bool Point::operator == (const Point& p) const { // Equally compare operator.
			return ((x == p.x) && (y == p.y));
		}

		Point& Point::operator = (const Point& source) { // Assignment operator.

			if (this == &source) {
				return *this;
			}
			x = source.x;
			y = source.y;
			//cout << "This is a POINT assignment operator." << endl;
			return *this;
		}

		Point& Point::operator *= (double factor) { // Scale the coordinates & assign.
			Point result;
			result = (*this) * factor;
			*this = result; //doing this so I can specifically return *this below
			return *this;
		}

		ostream& operator << (ostream& os, const Point& pt)
		{ // Print Point
			os << "(" << pt.x << "," << pt.y << ")";//pt.ToString();
			return os;
		}

		void Point::Draw() const { // Draw.
			cout << "Point Draw function call.";
		}

	}//namespace CAD
} //namespace PAULLOPEZ
