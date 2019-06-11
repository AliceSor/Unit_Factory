/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:26:18 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/17 19:35:27 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony (std::string _ponyName)
{
	this->ponyName = _ponyName;
	std::cout << ponyName <<" Created!"<< std::endl;
}
Pony::~Pony ()
{
	std::cout << ponyName << " Destroed!"<< std::endl;
}
