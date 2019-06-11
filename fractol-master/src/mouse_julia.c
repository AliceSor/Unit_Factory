/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:47:24 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 21:05:06 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int				mouse_julia(int x, int y, t_frct *frct)
{
	if (frct->num_fract == 2)
	{
		frct->julia_a = scale_re(x, frct->lmt);
		frct->julia_b = scale_im(y, frct->lmt);
		create_fractol(frct);
	}
	return (0);
}
