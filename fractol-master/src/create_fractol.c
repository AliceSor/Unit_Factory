/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:02:24 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 21:21:30 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			create_fractol(t_frct *frct)
{
	int			y;
	pthread_t	id[5];
	t_thrd		*thrd;
	int			i;

	i = 0;
	thrd = (t_thrd *)malloc(sizeof(t_thrd) * 5);
	create_image(frct->mlx);
	while (i < 4)
	{
		thrd[i].frct = frct;
		thrd[i].y_min = (HEIGHT * i) / 4;
		thrd[i].y_max = (HEIGHT * (i + 1))/ 4;
		pthread_create(&id[i], NULL, (void *(*)(void *))algoritm, &thrd[i]);
		i++;
	}
	i = -1;
	while (++i < 4)
		pthread_join(id[i], NULL);
	mlx_put_image_to_window(frct->mlx->mlx, frct->mlx->win, frct->mlx->im, 0, 0);
}
