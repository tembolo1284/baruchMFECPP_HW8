#ifndef Array_HPP
#define Array_HPP
#include <iostream>
#include <string>
#include "ArrayException.hpp"
using namespace std;

namespace PAULLOPEZ {
	namespace CONTAINERS {
		using namespace CAD;
		template <typename T> 
		class Array {
		private:
			static int dSize; 
			int size;
			T* table; //used to be CAD::Point*

		public:
			Array(); //constructor that creates array with 10 points in it
			Array(const int n); //initialization with dynamic variable
			Array(const Array<T>& arr); //Copy constructor
			~Array(); //destructor
			
			Array<T>& operator = (const Array<T>& source); // Assignment operator.
			T& operator [] (int index); // read and write version
			const T& operator [] (const int index) const; //read only version

			static int DefaultSize(); //get default size.  
			static void DefaultSize(const int n); //set default size. 

			int Size() const; //Size function
			void SetElement(const T& pt, const int n); //Setter
			T GetElement(const int n) const; //Getter
		};

		template <typename T>
		int Array<T>::dSize = 10; //instantiating the static variable.
		
		template <typename T>
		int Array<T>::DefaultSize() { //gets default size
			return dSize; 
		}

		template <typename T>
		void Array<T>::DefaultSize(const int n) { //sets default size
			dSize = n; 	
		}
	}
}

#ifndef Array_cpp // Must be the same name as in source file #define
#include "Array.cpp"
#endif

#endif