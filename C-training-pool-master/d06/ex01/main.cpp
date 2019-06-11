#include "Serializator.hpp"

int		main()
{
	srand(time(NULL));
	void *ptr = serialize();
	Data *d = deserialize(ptr);

	std::cout<<"s1: "<<d->s1<<std::endl;
	std::cout<<"n: "<<d->n<<std::endl;
	std::cout<<"s2: "<<d->s2<<std::endl;

	return (0);
}
