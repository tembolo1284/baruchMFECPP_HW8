#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <cmath>
#include <sstream>

//////Circle magic time

namespace PAULLOPEZ {
	namespace CAD {
		Circle::Circle() : radius(0.0), center(0.0,0.0) {
			//radius = 0.0;
			//Point pt; //default constructor. 
			//cout << "Default CIRCLE constructor says hello to you." << endl;
		}

		Circle::Circle(const double& r, const Point& pt) : radius(r), center(pt) {
			//radius = r; //setting radius equal to r
			//center = pt; //setting Point center equal to pt passed by ref
			//cout << "This is another CIRCLE constructor." << endl;
		}

		Circle::Circle(const Circle& c) : radius(c.radius), center(c.center) {
			//radius = c.radius;
			//center = c.center;
			//cout << "Copy CIRCLE constructor says Hello to you." << endl;
		}

		Circle::~Circle() {
			cout << "See you later CIRCLE..." << endl;
		}

		double Circle::rad() const {
			return radius; //spits out value of radius
		}

		Point Circle::ctr() const {
			return center; //spits out Point center	
		}

		void Circle::rad(const double& newR_value) {
			radius = newR_value;
			cout << "radius has been set." << endl;
		}

		void Circle::ctr(const Point& pt) {
			center = pt;
			cout << "new center has been set." << endl;
		}

		string Circle::ToString() const {
			std::string s = Shape::ToString();

			stringstream pnt;
			pnt << s << ", The Circle has area: " << M_PI * radius * radius << ", diameter: " << 2 * radius << ", and a Circumference of: " << 2 * M_PI * radius << endl;
			//cout << pnt.str();
			return pnt.str();
		}

		void Circle::Draw() const { // Draw.
			cout << "Circle Draw function call.";
		}

		double Circle::Area() const {
			double result = M_PI * radius * radius;
			return result;
		}

		double Circle::Circumference() const {
			double result = 2 * M_PI * radius;
			return result;
		}

		double Circle::Diameter() const {
			double result = 2 * radius;
			return result;
		}

		Circle& Circle::operator = (const Circle& source) { // Assignment operator.

			if (this == &source) {
				return *this;
			}
			radius = source.radius;
			center = source.center;
			cout << "Circle assignment operator says hello." << endl;
			return *this;
		}

		ostream& operator << (ostream& os, const Circle& c)
		{ // Print Circle
			os << c.ToString();
			return os;
		}

	}
}
