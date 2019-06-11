/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:14:03 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/18 17:14:04 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		static int  const numBits;//8
		int rawBits;
	public:
		Fixed ();
		Fixed(int i);
		Fixed(float f);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed&		operator=(Fixed const & assignedValue);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator<<(std::ostream &stream, Fixed const &num);

#endif
