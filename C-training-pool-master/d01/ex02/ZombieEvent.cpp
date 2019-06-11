/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:47:21 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/17 20:47:24 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ZombieEvent.hpp"

void		ZombieEvent::setZombieType(std::string _type)
{
	this->type = _type;
}

Zombie*		ZombieEvent::newZombie(std::string _name)
{
	Zombie *zombie = new Zombie;
	zombie->name = _name;
	zombie->type = this->type;

	return (zombie);
}