#include "Serialization.hpp"

int	main()
{
	Data *ptr = new Data;
	uintptr_t	serialize;
	Data		*deserialize;

	ptr->n = 10;

	serialize = Serialization::serialize(ptr);
	deserialize = Serialization::deserialize(serialize);

	std::cout << "Hemos convertido el puntero Data 'ptr' a uintptr_t y lo hemos vuelto a convertir  un puntero Data sin perder información. El contenido de Data->n sigue siendo: " << deserialize->n << std::endl;
}