
#include <string>
#include <iostream>
#include <cstdint> // Para uintptr_t

struct Data {
	int n;
};

class Serialization {
	private:
		Serialization();
		~Serialization();
		Serialization(Serialization const &obj);
		Serialization &operator=(Serialization const &obj);

	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);
};