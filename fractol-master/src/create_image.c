/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 18:15:57 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/26 14:53:46 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


void			create_image(t_mlx *mlx)
{
	int			bpss;
	int			endian;

	if (mlx->imdata)
		mlx_destroy_image(mlx->mlx, mlx->im);
	mlx->im = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->imdata = (int *)mlx_get_data_addr(mlx->im, &bpss, &mlx->ls, &endian);
}
