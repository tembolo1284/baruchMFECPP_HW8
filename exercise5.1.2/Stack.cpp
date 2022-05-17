#ifndef Stack_CPP
#define Stack_CPP
#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include <cmath>
#include <sstream>

namespace PAULLOPEZ {
	namespace CONTAINERS {
		template <typename T,int size>
		Stack<T,size>::Stack() : index(0), arr(size) {
			//cout << "Default Stack constructor says hello to you." << endl;
		}
	
		template <typename T, int size>
		Stack<T, size>::Stack(const Stack<T, size>& st) : index(st.index), arr(st.arr) {
			//cout << "Copy Stack constructor says Hello to you." << endl;
		}
		template <typename T, int size>
		Stack<T,size>::~Stack() {
			cout << "Bye bye Stack..." << endl;
		}

		template <typename T, int size>
		Stack<T,size>& Stack<T,size>::operator = (const Stack<T,size>& st) { // Assignment operator.
			if (this == &st) {
				return *this;
			}
				index = st.index;
				arr = st.arr;
				return *this;
		
		}
		template <typename T, int size>
		void Stack<T,size>::Push(const T& obj) {
			try {
				arr[index] = obj; //throw object in last slot of array
				index++; //increment index by 1
			}
			catch (ArrayException&) {
				//cout << "An Array Exception has occurred." << endl;
				throw StackFullException();
			}
			catch (...) {
				cout << "An unhandled exception has occurred.";
			}
		}

		template <typename T, int size>
		T Stack<T,size>::Pop() { 
			try {
				arr[index - 1]; //try this and if no exception is thrown, we are good to proceed.
				index--; //decrement index by 1
				return arr[index];
			}
			catch (ArrayException&) {
				//cout << "An Array Exception has occurred." << endl;
				throw StackEmptyException(); //this needs to be uncommented when testing out Pop()

			}
			catch (...) {
				cout << "An unhandled exception has occurred.";
			}
		}

	}
}

#endif