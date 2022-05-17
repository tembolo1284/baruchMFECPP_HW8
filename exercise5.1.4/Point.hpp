
#ifndef Point_HPP
#define Point_HPP
#include <iostream>
#include <string>
#include "Shape.hpp"
using namespace std;

namespace PAULLOPEZ {
	namespace CAD {

		class Point:public Shape { //Point is derived class of Shape
		private:
			double x;
			double y; //x and y coordinates, respectively.
		public:
			Point(); //constructor
			Point(double x_val, double y_val); //initialization with x and y values

			Point(const Point& pt); //copy constructor

			explicit Point(double bothVals); //initialization for both x and y values
			

			~Point(); //destructor

			double X() const; //Getter
			double Y() const; //Getter

			//operator time
			Point operator - () const; // Negate the coordinates.
			Point operator * (double factor) const; // Scale the coordinates.
			Point operator + (const Point& p) const; // Add coordinates.
			bool operator == (const Point& p) const; // Equally compare operator.
			Point& operator = (const Point& source); // Assignment operator.
			Point& operator *= (double factor); // Scale the coordinates & assign.

			void X(double newX_val) { x = newX_val; }; //hoping this is what you guys mean by default inline. Setter
			void Y(double newY_val) { y = newY_val; }  //Setter

			string ToString() const; //returns cout string description of the point
			void Draw() const;

			double Distance() const; //calc dist from current point to origin
			double Distance(Point& p1) const; //calc dist from curr pt to point passed in function

			friend ostream& operator << (ostream& os, const Point& pt);

		};
		inline double Point::X() const {
			return x; //spits out value of x
		}
		inline double Point::Y() const {
			return y; //spits out value of y	

		}
	}
}
#endif