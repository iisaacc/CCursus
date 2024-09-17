#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::~Serialization() {}

Serialization::Serialization(Serialization const &obj) {
	(void)obj;
}

Serialization &Serialization::operator=(Serialization const &obj) {
	(void)obj;
	return (*this);
}

uintptr_t	Serialization::serialize(Data* ptr) {
	uintptr_t	serialized;

	serialized = reinterpret_cast<uintptr_t>(ptr);
	return (serialized);
}

Data*		Serialization::deserialize(uintptr_t raw) {
	Data *ptr = new Data;

	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}