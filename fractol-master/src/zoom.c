/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:18:09 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/26 15:28:17 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

int			zoom(int kc, int x, int y, t_frct *frct)
{
	double	mult;

	mult = 0;
	if (kc != 5 && kc != 4 && mult == 0)
		return (0);
	mult = (kc == 5) ? 0.9 : 1.1;
	set_new_limits(frct, x, y, mult);
	/*paint new image*/
	create_fractol(frct);
	return (0);
}
