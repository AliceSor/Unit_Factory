/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:18:05 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 21:21:33 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			*algoritm(t_thrd *t)
{
	int			x;
	int			y;
	double		a;
	double		b;
	int			color;

	y = (*t).y_min;
	b = scale_im(y, (*t).frct->lmt);
	while (y <= (*t).y_max)
	{
		a = scale_re(x, (*t).frct->lmt);
		if (x > WIDTH - 1)
		{
			b = scale_im(y, (*t).frct->lmt);
			y++;
			x = 0;
		}
		if ((*t).frct->num_fract == 1)
			color = mandelbrot(a,b, (*t).frct->depth);
		if ((*t).frct->num_fract == 2)
		   color = julia(a, b, (*t).frct);
		put_pixel(x,y,color, (*t).frct->mlx);
		x++;
	}
	pthread_exit(0);
}
