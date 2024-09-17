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

//Reinterpret_cast is used to convert one pointer to another type of data without changing the actual bites data.
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