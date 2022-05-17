#ifndef PointArray_HPP
#define PointArray_HPP
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Array.hpp"
using namespace std;

namespace PAULLOPEZ {
	namespace CONTAINERS {
		using namespace CAD;
		class PointArray : public Array<Point> {
		public:
			PointArray(); //default constructor 
			PointArray(const int n); //initialization with variable
			PointArray(const PointArray& arr); //Copy constructor
			~PointArray(); //destructor
			PointArray& operator = (const PointArray& source); // Assignment operator.
			double Length() const; //Length function
		};
	}
}
#endif