#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP
#include <iostream>
#include <string>
using namespace std;

class ArrayException { //Point is derived class of Shape
private:
public:
	//ArrayException(); //constructor
	virtual string GetMessage() const = 0;
};

class OutOfBoundsException : public ArrayException { //OutOfBounds is derived class of ArrayException
private:
	int index;
public:
	OutOfBoundsException(int index); //constructor with int param
	string GetMessage() const;
};

class ArraySizeException : public ArrayException { //ArraySizeException is derived class of ArrayException
private:
	int index;
public:
	ArraySizeException(int index); //constructor with int param
	string GetMessage() const;
};

#endif