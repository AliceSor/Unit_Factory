#include <iostream>
#include <string>

template <typename T>

void iter(T * array, size_t n, void (*f)(T &))
{
	for (size_t i = 0; i < n; i++)
		f(array[i]);
}

template <typename T>

void printT(T &data)
{
	std::cout<<data<<std::endl;
}

int main()
{
	char array1[] = "abcdef";
	int array2[] = {1, 2, 3};

	iter(array1, 6, printT);
	iter(array2, 3, printT);

	return 0;
}
