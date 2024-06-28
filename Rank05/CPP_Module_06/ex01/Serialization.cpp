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
	
}

Data*		Serialization::deserialize(uintptr_t raw) {

}