/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:54:16 by asoroka           #+#    #+#             */
/*   Updated: 2018/01/17 19:54:42 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony pony = Pony("ponyInHeapName");
}

void	ponyOnTheStack()
{
	Pony *pony = new Pony("ponyInStackName");
	delete pony;
}  

int		main()
{
	ponyOnTheHeap(); 
	ponyOnTheStack();

	return (0);
}