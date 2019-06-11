#include "Converter.hpp"
#include <ctype.h>

void conv(char *i)
{
	Converter converter(i);

	std::cout<<"char: ";
	try
	{
		char c = static_cast<char>(converter);
		if (isprint(c))
			std::cout<<c;
		else
				std::cout<<"Non displayable";
	}
	catch(std::exception)
	{
		std::cout<<"impossible";
	}
	std::cout << std::endl;

	std::cout<<"int: ";
	try
	{
		double c = static_cast<double>(converter);
		if (c < -2147483648.0 || c > 2147483647.0)
		{
			std::cout<<"impossible";
		}
		else
		{
			int c = static_cast<int>(converter);
			std::cout<<c;
		}
	}
	catch(std::exception)
	{
		std::cout<<"impossible";
	}
	std::cout << std::endl;

	std::cout<<std::fixed;
	std::cout.precision(2);
	std::cout<<"float: ";

	try
	{
		float c = static_cast<float>(converter);
		std::cout<<c<<"f";
	}
	catch(std::exception)
	{
		std::cout<<"impossible";
	}
	std::cout << std::endl;

	std::cout<<std::fixed;
	std::cout.precision(2);
	std::cout<<"double: ";

	try
	{
		double c = static_cast<double>(converter);
		std::cout<<c;
	}
	catch(std::exception)
	{
		std::cout<<"impossible";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		conv(argv[1]);
	}
	return (0);
}
