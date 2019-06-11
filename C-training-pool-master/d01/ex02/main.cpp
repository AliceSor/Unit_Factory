/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:48:13 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/17 20:48:14 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <cstdlib>

void	randomChump()
{
	ZombieEvent *event = new ZombieEvent();
	Zombie 		*z;
	std::string name;
	std::string setNames[3];
	int 		i;

	i = 0;
	std::cout << "enter names"<< std::endl;
	while (i < 3)
	{
		std::getline(std::cin, setNames[i]);
		i++;
	}
	name = setNames[rand() % 3];
	event->type = "ordinary_zombie";
	z = event->newZombie(name);
	z->announce(z);

	delete z;
	delete event;
}

int		main()
{
	randomChump();
	return (0);
}