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
		
		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
		float 				toFloat( void ) const;
		int 				toInt( void ) const;

		static Fixed		&min(Fixed &num1, Fixed &num2);
		static Fixed		&max(Fixed &num1, Fixed &num2);
		static Fixed const	&min(Fixed const &num1, Fixed const &num2);
		static Fixed const	&max(Fixed const &num1, Fixed const &num2);

		Fixed&				operator=(Fixed const & assignedValue);

		bool				operator>(Fixed const & compareValue);//1
		bool				operator<(Fixed const & compareValue);//2
		bool				operator>=(Fixed const & compareValue);//3
		bool				operator<=(Fixed const & compareValue);//4
		bool				operator==(Fixed const & compareValue);//5
		bool				operator!=(Fixed const & compareValue);//6

		Fixed&				operator+(Fixed const & value);//1
		Fixed&				operator-(Fixed const & value);//2
		Fixed&				operator*(Fixed const & value);//3
		Fixed&				operator/(Fixed const & value);//4

		Fixed				&operator++(void);
		Fixed				&operator++(int);
		Fixed				&operator--(void);
		Fixed				&operator--(int);



};

std::ostream  				&operator<<(std::ostream &stream, Fixed const &num);

#endif