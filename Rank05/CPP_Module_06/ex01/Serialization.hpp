
#include <string>
#include <iostream>
#include <cmath>

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
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};