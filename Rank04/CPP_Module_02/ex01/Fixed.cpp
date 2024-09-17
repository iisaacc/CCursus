#include "Fixed.hpp"

//-----------------CONSTRUCT & DESTRUCT------------------

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _fixedPointValue(n * 256){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _fixedPointValue(roundf(f * 256)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : _fixedPointValue(src.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//-------------------OPERATORS-----------------

Fixed	&Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_fixedPointValue = src.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &src) {
	return (out << src.toFloat());
}

//------------------GETTERS & SETTERS------------------------

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

//-----------------------METHODS------------------------

float	Fixed::toFloat() const {
	return (this->_fixedPointValue * 0.00390625);
}

int	Fixed::toInt() const {
	return (this->_fixedPointValue * 0.00390625);
}


