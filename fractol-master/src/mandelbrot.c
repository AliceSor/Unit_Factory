/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 18:30:33 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 19:54:18 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

int				mandelbrot(double a0, double b0, int depth)
{
	double		a;
	double		b;
	double		temp;
	int			iter;

	a = 0;
	b = 0;
	iter = 0;
	while (iter < depth)
	{
		temp = (a * a) - (b * b);
		b = 2 * a * b + b0;
		a = temp + a0;
		if ((a * a + b * b) > 4)
			break ;
		iter++;
	}
	if (iter < depth) 
	{
		temp = log( a*a + b*b ) / 2;
		iter = iter + 1 - log( temp / log(2) ) / log(2);
	}
	return ((iter < depth) ? (iter + 0.1) * 0x0F0F0F : 0xFFFFFF);
}
