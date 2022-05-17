#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "ArrayException.hpp"
#include <cmath>
#include <sstream>

//OutofBoundsException::OutofBoundsException() {}
OutOfBoundsException::OutOfBoundsException(int index = -1) {}
ArraySizeException::ArraySizeException(int index = -1) {}

string OutOfBoundsException::GetMessage() const {
	return "Your input is out of bounds.\n";
}

string ArraySizeException::GetMessage() const {
	return "Error! Arrays are not the same size.\n";
}