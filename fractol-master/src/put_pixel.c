/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:57:02 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/21 14:46:47 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			put_pixel(int x, int y, int color, t_mlx *mlx)
{
	int			i;
/* write(1, "put_2\n", 6); */
	i = mlx->ls * y / 4 + x;
	if (i < WIDTH * HEIGHT && i > 0)
		mlx->imdata[i] = color;
		/* write(1, "PUT_2\n", 6);; */
}
