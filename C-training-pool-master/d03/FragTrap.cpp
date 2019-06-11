/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:54:52 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/19 18:54:54 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::hpMax = 100;
FragTrap::energyPointsMax = 100;

FragTrap::FragTrap()
{
	this->hp = 100;
	this->energyPoints = 100;
	this->lvl = 1;
	this->name = "FR4G-TP";
	this->damageMelee = 30;
	this->damageRanged = 20;
	this->armor = 5;
}

FragTrap::FragTrap(std::string const _name)
{
	this->hp = 100;
	this->energyPoints = 100;
	this->lvl = 1;
	this->name = _name;
	this->damageMelee = 30;
	this->damageRanged = 20;
	this->armor = 5;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = srs;
}

~FragTrap()
{
	std::cout<< "It's suppose to be my last words..."<<std::endl;
}

FragTrap& 			FragTrap::operator=(FragTrap const & assignedValue)
{
	if (*this != src)
	{
		this->hp = src.hp;
		this->energyPoints = src.energyPoints;
		this->lvl = src.lvl;
		this->name = src.name;
		this->damageMelee = src.damageMelee;
		this->damageRanged = src.damageRanged;
		this->armor = src.armor;
	}
}

void 				FragTrap::rangedAttack(std::string const & target)
{
	if (this->energyPoints > 25)
	{
		std::cout<< "FR4G-TP <" 
			<< this->name 
			<< "> attacks <"
			<< target.name
			<< "> at range, causing <"
			<< this.damageRanged
			<< "> points of damage !"
			<<std::endl;

		target.takeDamage(this->damageRanged);
	}
	else
		std::cout<< "I have no energy!"<<std::endl;

}

void 				FragTrap::meleeAttack(std::string const & target)
{
	if (this->energyPoints > 25)
	{
		std::cout<< "FR4G-TP <" 
			<< this->name 
			<< "> attacks <"
			<< target.name
			<< "> at melee, causing <"
			<< this.damageMelee
			<< "> points of damage !"
			<<std::endl;

		target.takeDamage(this->damageMelee);
	}
	else
		std::cout<< "I have no energy!"<<std::endl;
}

void 				FragTrap::takeDamage(unsigned int amount)
{
	if (this->hp + this->armor > (int)amount)
	{
		this->hp -= ((int)amount - this->armor);
		std::cout<<this->name<< " just take some damage, and his current HP is: "<< this->hp<<std::endl;
	}
	else
	{
		this->hp = 0;
		std::cout<< "To many damage for "<< this->name <<std::endl;
	}
}

void 				FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 25)
	{
		this->hp = (this->hp + (int)amount >= 100) ? 100 : this->hp += (int)amount;
		std::cout<< "Well done!"<<std::endl;
	}
	else
		std::cout<< "I have no energy!"<<std::endl;
}

void 				vaulthunter_dot_exe(std::string const & target)
{
	//не успеваю уже
}

	// void 				vaulthunter_dot_exe(std::string const & target);