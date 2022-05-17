#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "StackException.hpp"
#include <cmath>
#include <sstream>


StackFullException::StackFullException() {
	//cout << this->GetMessage() << endl;
}
StackEmptyException::StackEmptyException() {
	//cout << this->GetMessage() << endl;
}

string StackFullException::GetMessage() const {
	return "Stack is full.";
}

string StackEmptyException::GetMessage() const {
	return "Stack is empty.";
}