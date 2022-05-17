#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include <cmath>
#include <sstream>

/////Line part
namespace PAULLOPEZ {
	namespace CAD {
		Line::Line(): startPoint(), endPoint() {
			//Point startPoint;
			//Point endPoint;
			//default constructor. start and end point both (0,0)
			//cout << "Default LINE constructor says hello to you." << endl;
		}

		Line::Line(const Point& pnt1, const Point& pnt2) : startPoint(pnt1), endPoint(pnt2) {
			//startPoint = pnt1;
			//endPoint = pnt2;
			//cout << "This is another LINE constructor." << endl;
		}

		Line::Line(const Line& l) : startPoint(l.startPoint), endPoint(l.endPoint) {
			//startPoint = l.startPoint;
			//endPoint = l.endPoint;
			//cout << "Copy LINE constructor says Hello to you." << endl;
		}
		Line::~Line() {
			//cout << "See you later LINE..." << endl;
		}

		Point Line::start() const {
			//cout << endl << "Start Point is:(" << startPoint.X() << "," << startPoint.Y() << ")" << endl;
			return startPoint;
			//spits out value of x,y for start point
		}

		Point Line::end() const {
			//cout << endl << "End Point is:(" << endPoint.X() << "," << endPoint.Y() << ")" << endl; //spits out value of x,y for start point
			return endPoint;
		}

		void Line::start(const Point& pt) { //set new start point for line
			startPoint = pt;
			//cout << "New start point has been set." << endl;
		}

		void Line::end(const Point& pt) { //set new end point for line
			endPoint = pt;
			//cout << "New end point has been set." << endl;
		}

		string Line::ToString() const {
			std::string s = Shape::ToString();
			stringstream pnt;
			pnt << s << ", Line has Start : (" << startPoint.X() << ", " << startPoint.Y() << "), and an End of : (" << endPoint.X() << ", " << endPoint.Y() << ")" << endl;
			//cout << pnt.str();
			return pnt.str();
		}
		void Line::Draw() const { // Draw.
			cout << "Line Draw function call.";
		}

		double Line::Length() const {
			double result = sqrt(pow(endPoint.X() - startPoint.X(), 2.0) + pow(endPoint.Y() - startPoint.Y(), 2.0));
			return result;
		}

		Line& Line::operator = (const Line& source) { // Assignment operator.

			if (this == &source) {
				return *this;
			}
			startPoint = source.startPoint;
			endPoint = source.endPoint;
			//cout << "Line assignment operator here." << endl;
			return *this;
		}


		ostream& operator << (ostream& os, const Line& l)
		{ // Print Line
			os << "Startpoint: " << l.startPoint << ", Endpoint: " << l.endPoint; //l.ToString();
			return os;
		}

	}
}
