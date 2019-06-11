#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

class Converter
{
	public:
		std::string		data;

		Converter(std::string const _data);
		~Converter();
		Converter(Converter const &src);
		Converter &operator=(Converter const &value);

		operator std::string const &(void) const;
		operator float() const;
		operator char() const;
		operator int() const;
		operator  double() const;

	 	class ExceptionConv : public std::exception
		 {
		 	public:
				   ExceptionConv();
				   ~ExceptionConv() throw();
				   char const *what(void) const throw();
		 };

};

std::ostream &operator<<(std::ostream &os, Converter const &converter);

#endif
