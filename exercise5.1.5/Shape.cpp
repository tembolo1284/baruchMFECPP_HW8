
#define _USE_MATH_DEFINES
#include "Shape.hpp"
#include <cmath>
#include <sstream>
#include <stdlib.h>

		Shape::Shape() {
			id = rand() % 1000 + 1; //random number from 1 to 1000
			//default constructor. 
			//cout << "Default SHAPE constructor says hello to you." << endl;
		}
		Shape::Shape(const Shape& s) {
			id = s.id;
			//cout << "Copy SHAPE constructor says Hello to you." << endl;
		}
		Shape::~Shape() {
			//cout << "See you later SHAPE..." << endl;
		}
		string Shape::ToString() const {
			stringstream sh;
			sh << "ID:" << id;
			//cout << sh.str();
			return sh.str();
		}
		int Shape::ID() const {
			return id; //spits out value of id
		}
		Shape& Shape::operator = (const Shape& s) { // Assignment operator.
			if (this == &s) {
				return *this;
			}
			id = s.id;
			//cout << "This is an assignment SHAPE operator." << endl;
			return *this;
		}

		void Shape::Print() const {
			string str = ToString();
			cout << str;
		}