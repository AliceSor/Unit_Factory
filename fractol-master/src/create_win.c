/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:31:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/25 18:35:40 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_mlx			*create_win(void)
{
	t_mlx		*nw;

	nw = (t_mlx *)malloc(sizeof(t_mlx) + 1);
	nw->mlx = mlx_init();
	nw->win = mlx_new_window(nw->mlx, WIDTH, HEIGHT, "fractol");
	return (nw);
}
