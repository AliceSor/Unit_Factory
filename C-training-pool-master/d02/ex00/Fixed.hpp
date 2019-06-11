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

class Fixed
{
	private:
		static int  const numBits;
		int rawBits;
	public:
		Fixed ();
		Fixed(Fixed const & src);
		~Fixed();

		Fixed&		operator=(Fixed const & assignedValue);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
