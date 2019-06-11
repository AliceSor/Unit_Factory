/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:25:49 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 21:21:09 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int				main(int argc, char **argv)
{
	t_frct		*frct;
	
	if (argc != 2)
	{
		return (0);
		}
	frct = (t_frct *)malloc(sizeof(t_frct));
	frct->num_fract = atoi(argv[1]);
	frct->lmt = set_limits(frct);
	frct->mlx = create_win();
	frct->depth = 50;
	if (frct->num_fract == 2)
	{
		frct->julia_a = scale_re(WIDTH / 2, frct->lmt);
		frct->julia_b = scale_im(HEIGHT / 2, frct->lmt);
	}
	create_fractol(frct);
	mlx_hook(frct->mlx->win, 2, 5, buttons, frct);
	mlx_mouse_hook(frct->mlx->win, zoom, frct);
	mlx_hook(frct->mlx->win, 6, 0, mouse_julia, frct);
	mlx_loop(frct->mlx->mlx);
	return (0);
}
