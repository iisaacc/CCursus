#pragma once

#include <iostream>
#include <string>

template< typename T >
class Array
{
	public:
		Array() : _array(new T[0]), _length(0) {};
		Array(size_t length) : _array(new T[length]), _length(length){};
		Array(const Array &other) : _array(new T[other._length]), _length(other._length) {
			for (size_t i = 0; i < _length; i++)
				_array[i] = other._array[i];
		};
		Array &operator=(const Array &other) {
			if(this != &other && this->_array)
			{
				delete[] this->_array;
				this->_length = other._length;
				this->_array = new T[_length];
				for (size_t i = 0; i < _length; i++)
					this->_array[i] = other._array[i];
			}
			return *this;
		};

		T& operator[](size_t index) {
			if (index >= _length)
				throw std::out_of_range("Index out of bounds");
			return (this->_array[index]);
		}

		size_t size() const {
			return _length;
		};
	private:
		T*		_array;
		size_t	_length;
};
