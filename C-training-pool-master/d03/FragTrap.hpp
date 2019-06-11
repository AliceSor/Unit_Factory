/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:55:06 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/19 18:55:08 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

class FragTrap
{
public:
	int 				hp;
	static int const 	hpMax;
	int 				energyPoints;
	static int const 	energyPointsMax;
	int 				lvl;
	std::string 		name;
	int 				damageMelee;
	int 				damageRanged;
	int					armor;

	FragTrap();
	FragTrap(std::string const _name);
	FragTrap(FragTrap const & src);
	~FragTrap();
	FragTrap& 			operator=(FragTrap const & assignedValue);

	void 				rangedAttack(std::string const & target);
	void 				meleeAttack(std::string const & target);
	void 				takeDamage(unsigned int amount);
	void 				beRepaired(unsigned int amount);
	void 				vaulthunter_dot_exe(std::string const & target);
	
};

#endif
