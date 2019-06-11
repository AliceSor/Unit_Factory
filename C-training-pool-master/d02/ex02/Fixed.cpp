/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:13:50 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/18 17:13:52 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const	Fixed::numBits = 8;

Fixed::Fixed()
{
	//std::cout << "Default Constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(int i)
{
	//std::cout << "Default Constructor called" << std::endl;
	this->rawBits = i << this->numBits;
}

Fixed::Fixed(float f)
{
	//std::cout << "Default Constructor called" << std::endl;
	this->rawBits = (int)roundf(f * (1 << this->numBits));
}

Fixed::Fixed(Fixed const & src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed&					Fixed::operator=(Fixed const & assignedValue)
{
//	std::cout << "Assignation operator called" << std::endl;
	if (this != & assignedValue)
		this->rawBits = assignedValue.getRawBits();
	return *this;
}

int 					Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void 					Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}
		
float 					Fixed::toFloat( void ) const
{
	return ((float)this->rawBits / (1 << this->numBits));
}

int 					Fixed::toInt( void ) const
{
	return ( this->rawBits >> this->numBits);
}


bool					Fixed::operator>(Fixed const & compareValue)
{
	return (this->rawBits > compareValue.rawBits);
}

bool					Fixed::operator<(Fixed const & compareValue)
{
	return (this->rawBits < compareValue.rawBits);
}

bool					Fixed::operator>=(Fixed const & compareValue)
{
	return (this->rawBits >= compareValue.rawBits);
}

bool					Fixed::operator<=(Fixed const & compareValue)
{
	return (this->rawBits <= compareValue.rawBits);
}

bool					Fixed::operator==(Fixed const & compareValue)
{
	return (this->rawBits == compareValue.rawBits);
}

bool					Fixed::operator!=(Fixed const & compareValue)
{
	return (this->rawBits != compareValue.rawBits);
}

Fixed&					Fixed::operator+(Fixed const & value)
{
	Fixed				*res = new Fixed();

	res->rawBits = this->rawBits + value.rawBits;
	return *res;
}

Fixed&					Fixed::operator-(Fixed const & value)
{
	Fixed				*res = new Fixed();

	res->rawBits = this->rawBits - value.rawBits;
	return *res;
}

Fixed&					Fixed::operator*(Fixed const & value)
{
	return (* new Fixed(this->toFloat() * value.toFloat()));
}

Fixed&					Fixed::operator/(Fixed const & value)
{
	return (* new Fixed(this->toFloat() / value.toFloat()));
}

Fixed&					Fixed::operator++(void)
{
	this->rawBits++;
	return(*this);
}

Fixed&					Fixed::operator++(int)
{
	Fixed 	*valueBefore = new Fixed(*this);
	this->rawBits++;
	return *valueBefore;
}

Fixed&					Fixed::operator--(void)
{
	this->rawBits--;
	return(*this);
}

Fixed&					Fixed::operator--(int)
{
	Fixed 	*valueBefore = new Fixed(*this);
	this->rawBits--;
	return *valueBefore;
}

Fixed&			Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}

Fixed&			Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1.getRawBits() > num2.getRawBits()? num1 : num2);
}

Fixed const&		Fixed::min(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}


Fixed const&		Fixed::max(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}


std::ostream & operator<<(std::ostream &stream, Fixed const &num)
{
	stream << num.toFloat();
	return stream;
}
