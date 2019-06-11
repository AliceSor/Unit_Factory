/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:43:03 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/18 18:43:45 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

std::cout << std::endl <<(Fixed(5) + Fixed(4)) << std::endl;
std::cout << (Fixed(5.45f) + Fixed(16.7652f)) << std::endl;
std::cout << (Fixed(4) - Fixed(5.1586f)) << std::endl;
std::cout << (Fixed(5) * Fixed(4)) << std::endl;
std::cout << (Fixed(5.1283f) * Fixed(4.11111f)) << std::endl;
std::cout << (Fixed(5) / Fixed(2)) << std::endl;
std::cout << (Fixed(5) / Fixed(0)) << std::endl;


return 0;
}