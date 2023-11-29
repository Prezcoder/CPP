
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class Array
{
	public:
		Array() : _size(0), _array(new T()) {};
		Array(unsigned int n) : _size(n), _array(new T[n]) {};
		Array(Array const &copy) {
			if (this != &copy)
			{
				_size = copy._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = copy._array[i];
			}
		}
		~Array() {delete [] _array;}
		Array &operator=(Array const &copy) {
			if (this != &copy)
			{
				delete [] _array;
				_size = copy._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = copy._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int i) {
			if (i >= _size)
				throw OutOfRangeException();
			return _array[i];
		}

		unsigned int size() const {return _size;}

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "Out of range.";}
		};

	private:
		unsigned int _size;
		T *_array;
};

#endif