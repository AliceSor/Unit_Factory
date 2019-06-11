#include "Converter.hpp"

Converter::Converter(std::string const _data)
{
	this->data = _data;
};
Converter::~Converter(){};
Converter::Converter(Converter const &src)
{
	*this = src;
}

Converter &Converter::operator=(Converter const &value)
{
	this->data = value.data;
	return (*this);
}

// Converter::operator std::string const &() const
// {
// 	return (this->data);
// }

Converter::operator int() const
{
	int res = std::atoi(this->data.c_str());

	if (errno)
	{
		errno = 0;
		throw(ExceptionConv());
	}
	return (res);
}

Converter::operator char() const
{
	char res = static_cast<char>(std::atoi(this->data.c_str()));

	if (errno)
	{
		errno = 0;
		throw(ExceptionConv());
	}
	return (res);
}

Converter::operator float() const
{
	float res = static_cast<float>(std::atof(this->data.c_str()));

	if (errno)
	{
		errno = 0;
		throw(ExceptionConv());
	}
	return (res);
}

Converter::operator  double() const
{
	double res = std::strtod(this->data.c_str(), NULL);

	if (errno)
	{
		errno = 0;
		throw(ExceptionConv());
	}
	return (res);
}

Converter::ExceptionConv::ExceptionConv() {}
Converter::ExceptionConv::~ExceptionConv() throw() {};

char const *Converter::ExceptionConv::what(void) const throw()
{
	errno = 0;
	return ("Not convertable");
}

std::ostream &operator<<(std::ostream &os, Converter const &converter)
{
	os<<converter.data;
	return (os);
}
