#ifndef Array_CPP
#define Array_CPP
#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include <cmath>
#include <sstream>

namespace PAULLOPEZ {
	namespace CONTAINERS {
		template <typename T>
		Array<T>::Array() {
			size = 10;
			table = new T[dSize];
			//cout << "Default POINT constructor says hello to you." << endl;
		}
		template <typename T>
		Array<T>::Array(const int n) {
			size = n;
			table = new T[n];
			//cout << "This is another ARRAY constructor." << endl;
		}
		template <typename T>
		Array<T>::Array(const Array<T>& arr) {
			size = arr.size;
			table = new T[size];
			for (int i = 0; i < size; i++) {
				table[i] = arr.table[i];
			}
			//cout << "Copy POINT constructor says Hello to you." << endl;
		}
		template <typename T>
		Array<T>::~Array() {
			//for (int i = 0; i < this->size; i++) {
				//delete[] this->table[i];
			//}
			delete[] table;
			cout << "Bye bye ARRAY..." << endl;
		}
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source) { // Assignment operator.

			if (this == &source) {
				return *this;
			}
			delete[] table;
			size = source.size;
			table = new T[size];
			for (int i = 0; i < source.size; i++) {
				table = source.table;
			}
			return *this;
		}
		template <typename T>
		T& Array<T>::operator [] (int index) { // Read and write version
				if (index >= size || index < 0) {
					throw OutOfBoundsException(index);
				}
				else {
					return table[index];
				}
		}
		template <typename T>
		const T& Array<T>::operator [] (int index) const { // Read only version
			if (index >= size || index < 0) {
				throw OutOfBoundsException(index);
			}
			else {
				return table[index];
			};
		}
		template <typename T>
		int Array<T>::Size() const {
		return size; //spits out size of array for this array	
		}
		template <typename T>
		void Array<T>::SetElement(const T& pt, const int n) {
				if (n >= size || n < 0) {
					throw OutOfBoundsException(n);
				}
				else {
					table[n] = pt;
				}
		}
		template <typename T>
		T Array<T>::GetElement(const int n) const {
				if (n >= size || n < 0) {
					throw OutOfBoundsException(n); 
				}
				else {
					return table[n];
				}
		}
	}
}

#endif