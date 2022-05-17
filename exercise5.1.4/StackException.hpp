#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP
#include <iostream>
#include <string>
using namespace std;

class StackException { 
public:
	virtual string GetMessage() const = 0;
};

class StackFullException : public StackException { //Full Exception is derived class of StackException
private:
	int index = 0;
public:
	StackFullException(); //constructor with int param
	string GetMessage() const;
};

class StackEmptyException : public StackException { //Empty Exception is derived class of StackException
private:
	int index = 0;
public:
	StackEmptyException(); //constructor with int param
	string GetMessage() const;
};

#endif