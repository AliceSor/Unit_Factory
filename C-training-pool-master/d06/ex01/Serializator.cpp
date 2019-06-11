#include "Serializator.hpp"

char	randomChar()
{
	char	c;
	int 	i;

	i = rand() % 3;
	switch (i) {
		case 0:
			c = static_cast<char>(48 + (rand() % (57 - 48)));//numbers
			break;
		case 1:
			c = static_cast<char>(65 + (rand() % (90 - 65)));//upper A,B,C
			break;
		case 2:
			c = static_cast<char>(97 + (rand() % (122 - 97)));
			break;
	}
	return (c);

}

void 	*serialize( void )
{
	char *str = new char[20];

	for (int i = 0; i < 8; i++)
		str[i] = randomChar();
	*(reinterpret_cast<int *>(&(str[8]))) = rand();
	for (int i = 12; i < 20; i++)
		str[i] = randomChar();
	return (reinterpret_cast<void *>(str));
}

Data * deserialize( void * raw )
{
	Data *d = new Data;

	d->s1.assign(reinterpret_cast<char *>(raw), 8);
	d->n = *(reinterpret_cast<int *>(reinterpret_cast<char *>(raw) + 8));
	d->s2.assign(reinterpret_cast<char *>(raw) + 12, 8);

	return (d);
}
