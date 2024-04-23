#include "Brain.hpp"

Brain::Brain() {
}

Brain::~Brain() {
}

Brain::Brain(const Brain &other) {
	*this = other;
}

Brain	&Brain::operator=(const Brain &other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}
