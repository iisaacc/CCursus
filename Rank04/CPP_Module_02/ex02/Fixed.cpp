#include "Fixed.hpp"

//-----------------CONSTRUCT & DESTRUCT------------------

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(int const n) : _fixedPointValue(n * 256){
}

Fixed::Fixed(float const f) : _fixedPointValue(roundf(f * 256)) {
}

Fixed::Fixed(Fixed const &src) : _fixedPointValue(src.getRawBits()) {
}
Fixed::~Fixed() {
}

//-------------------OPERATORS-----------------

Fixed	&Fixed::operator=(Fixed const &src) {
	if (this != &src) {
		this->_fixedPointValue = src.getRawBits();
	}
	return *this;
}

Fixed	&Fixed::operator++(void) {
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	this->_fixedPointValue++;
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	this->_fixedPointValue--;
	return (tmp);
}

bool	Fixed::operator<(Fixed const &other) const {
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator>(Fixed const &other) const {
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool	Fixed::operator<=(Fixed const &other) const {
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator>=(Fixed const &other) const {
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator==(Fixed const &other) const {
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(Fixed const &other) const {
	return (this->_fixedPointValue != other._fixedPointValue);
}

float	Fixed::operator+(Fixed const &other) const {
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(Fixed const &other) const {
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(Fixed const &other) const {
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(Fixed const &other) const {
	return (this->toFloat() / other.toFloat());
}

std::ostream &operator<<(std::ostream &out, Fixed const &src) {
	return (out << src.toFloat());
}

//------------------GETTERS & SETTERS------------------------

int	Fixed::getRawBits() const {
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

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed1._fixedPointValue < fixed2._fixedPointValue)
		return (fixed1);
	else
		return (fixed2);
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed1._fixedPointValue > fixed2._fixedPointValue)
		return (fixed1);
	else
		return (fixed2);
}



