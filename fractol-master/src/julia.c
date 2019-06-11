/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:54:39 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 20:35:07 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

int				julia(double a, double b, t_frct *frct)
{
	double		a0;
	double		b0;
	double		temp;
	int			iter;

	a0 = frct->julia_a;
	b0 = frct->julia_b;
	iter = 0;
	while (iter < frct->depth)
	{
		temp = (a * a) - (b * b);
		b = 2 * a * b + b0;
		a = temp + a0;
		if ((a * a + b * b) > 4)
			break ;
		iter++;
	}
	/* if (iter < depth)  */
	/* { */
	/* 	temp = log( a*a + b*b ) / 2; */
	/* 	iter = iter + 1 - log( temp / log(2) ) / log(2); */
	/* } */
	return ((iter < frct->depth) ? (iter + 0.1) * 0x0F0F0F : 0xFFFFFF);
}
