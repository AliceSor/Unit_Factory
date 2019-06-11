/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:47:33 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/17 20:47:39 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class 			ZombieEvent
{
	public :
		std::string type;
		std::string name;

	 Zombie*	newZombie(std::string _name);
	 void		setZombieType(std::string _type);
};

#endif