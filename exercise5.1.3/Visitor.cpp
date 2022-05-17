#ifndef Visitor_CPP
#define Visitor_CPP
#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "Visitor.hpp"
#include <boost/variant.hpp>
#include "boost/variant/static_visitor.hpp"
#include <cmath>
#include <sstream>

namespace PAULLOPEZ {
	namespace CONTAINERS {
		using namespace CAD;
		template <typename T>
		Visitor<T>::Visitor() : m_x(0), m_y(0) {
		}

		template <typename T>
		Visitor<T>::Visitor(double x, double y) : m_x(x), m_y(y) {
		}

		template <typename T>
		Visitor<T>::~Visitor() {
			//bye bye nice to have you VISIT;
		}
		
		template <typename T>
		void Visitor<T>::operator () (Point& p) const{
			p.X(p.X() + m_x); // visitor tickles the point p1 + p2 = new location p3
			p.Y(p.Y() + m_y);
		}
		template <typename T>
		void Visitor<T>::operator () (Line& l) const {
			l.start(l.start() + Point(m_x, m_y)); //visitor tweaks the start point and end point by Point(m_x and m_y)
			l.end(l.end() + Point(m_x, m_y));
		}
		template <typename T>
		void Visitor<T>::operator () (Circle& c) const {
			c.ctr(c.ctr() + Point(m_x, m_y)); // visitor moves the center center + Point(x,y) of Visitor object
		}
	}
}

#endif


