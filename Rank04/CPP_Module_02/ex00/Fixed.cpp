#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : _fixedPointValue(src.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_fixedPointValue = src.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

