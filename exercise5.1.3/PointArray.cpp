#ifndef PointArray_CPP
#define PointArray_CPP
#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "PointArray.hpp"
#include "ArrayException.hpp"
#include <cmath>
#include <sstream>

namespace PAULLOPEZ {
	namespace CONTAINERS {
		using namespace CAD;
		PointArray::PointArray() : Array<CAD::Point>() {
			//cout << "Default constructor says hello to you." << endl;
		}
		
		PointArray::PointArray(const int n) : Array<CAD::Point>(n) {	
			//cout << "This is another ARRAY constructor." << endl;
		}
		PointArray::PointArray(const PointArray& arr) : Array<CAD::Point>(arr) {
			//cout << "Copy PointArray constructor says Hello to you." << endl;
		}
		
		PointArray::~PointArray() {
			cout << "Bye bye PointARRAY..." << endl;
		}
		double PointArray::Length() const {
			double result{ 0.0 };
			int size = this->Size();
			for (int i = 0; i < size - 1; i++) {
				Point currPt = this->GetElement(i);
				Point nxtPt = this->GetElement(i + 1);
				result += currPt.Distance(nxtPt);
			}
			return result;
		}
		PointArray& PointArray::operator = (const PointArray& source) { // Assignment operator.

			if (this == &source) {
				return *this;
			}
			this->Array<Point>::operator = (source);
			return *this;
		}
	}
}
#endif