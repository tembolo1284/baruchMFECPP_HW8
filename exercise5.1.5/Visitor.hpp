#ifndef Visitor_HPP
#define Visitor_HPP
#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "boost/variant/static_visitor.hpp"
using namespace std;

namespace PAULLOPEZ {
	namespace CONTAINERS {
		using namespace CAD;
		template <typename T>
		class Visitor : public boost::static_visitor<> {
		private:
			double m_x;
			double m_y;
		public:
			Visitor();
			Visitor(double x, double y); //constructor with two nums
			virtual ~Visitor();

			void operator () (Point& p) const; 
			void operator () (Line& l) const;
			void operator () (Circle& c) const;

		};
	}
}

#ifndef Visitor_cpp // Must be the same name as in source file #define
#include "Visitor.cpp"
#endif

#endif