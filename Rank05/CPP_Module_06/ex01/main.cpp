#include "Serialization.hpp"

int	main()
{
	Data *ptr = new Data;
	uintptr_t	serialize;
	Data		*deserialize;

	ptr->n = 10;

	serialize = Serialization::serialize(ptr);
	deserialize = Serialization::deserialize(serialize);
	std::cout << "Data pointer was converted to uintptr_t and converted back to Data pointer without losing information. The Dta->n content is still: " << deserialize->n << std::endl;
}