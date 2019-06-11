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

int	const	Fixed::numBits = 2;

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(int i)
{
	std::cout << "Default Constructor called" << std::endl;
	this->rawBits = i << this->numBits;
}

Fixed::Fixed(float f)
{
	std::cout << "Default Constructor called" << std::endl;
	this->rawBits = (int)roundf(f * (1 << this->numBits));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&		Fixed::operator=(Fixed const & assignedValue)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & assignedValue)
		this->rawBits = assignedValue.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->rawBits / (1 << this->numBits));
}

int Fixed::toInt( void ) const
{
	return ( this->rawBits >> this->numBits);
}

std::ostream & operator<<(std::ostream &stream, Fixed const &num)
{
	stream << num.toFloat();
	return stream;
}

