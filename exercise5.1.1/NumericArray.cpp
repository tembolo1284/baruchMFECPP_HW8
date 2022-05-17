#ifndef NumericArray_CPP
#define NumericArray_CPP
#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include "Array.hpp"
#include <cmath>
#include <sstream>

namespace PAULLOPEZ {
	namespace CONTAINERS {
		template <typename T>
		NumericArray<T>::NumericArray() : Array<T>() {
			//cout << "Default POINT constructor says hello to you." << endl;
		}
		template <typename T>
		NumericArray<T>::NumericArray(const int n) : Array<T>(n) {
			//cout << "This is another ARRAY constructor." << endl;
		}
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& arr) : Array<T>(arr) {
			//cout << "Copy POINT constructor says Hello to you." << endl;
		}
		template <typename T>
		NumericArray<T>::~NumericArray() {
			cout << "Bye bye NumericARRAY..." << endl;
		}

		template <typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& arr1) const {
			double result{};
			int thisSize = this->Size();
			if (thisSize != arr1.Size()) {
				throw ArraySizeException(thisSize);
			}
			else {
				for (int i = 0; i < thisSize; i++) {
					result += this->GetElement(i) * arr1.GetElement(i);
				}
			}
			return result;
		}

		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source) { // Assignment operator.
			if (this == &source) {
				return *this;
			}
			//delete[] this->Array<T>::table;
			this->Array<T>::operator = (source);
			return *this;
		}
		
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (double factor) const { // scalar mult
			NumericArray<double> result(this->Size());
			int j = this->Size();
			for (int i = 0; i < j; i++) {
				result.SetElement(this->GetElement(i) * factor, i);
			}
			return result;
		}

		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source) const {
			NumericArray<T> result(this->Size());
			int thisSize = this->Size();
			if (thisSize != source.Size()) {
				throw ArraySizeException(thisSize);
			}
			else {
				for (int i = 0; i < thisSize; i++) {
					result.SetElement(this->GetElement(i) + source.GetElement(i),i);
				}
			}
			return result;
		}
	}
}

#endif