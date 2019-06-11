/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:02:48 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/01 18:57:16 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			buttons(int keycode, t_frct *frct)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		frct->depth++;
		printf("%d\n", frct->depth);
		create_fractol(frct);
	}	
	return (0);
}
