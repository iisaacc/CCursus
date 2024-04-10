#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(float const px, float const py): x(px), y(py) {
}

Point::Point(const Point &other) {
	this->x = other.x;
	this->y = other.y;
}

Point::~Point() {
}

Point &Point::operator=(const Point &other) {
	this->x = other.x;
	this->y = other.y;
	return (*this);
}

Fixed Point::get_X() const{
	return (this->x);
}

Fixed Point::get_Y() const{
	return (this->y);
}

void	Point::set_X(Fixed x) {
	this->x = x;
}

void	Point::set_Y(Fixed y) {
	this->y = y;
}