/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:54:54 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/20 19:01:07 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_lmt			set_limits(t_frct *frct)
{
	t_lmt		lmt;

	if (frct)
		lmt.re_min = -2;
	lmt.re_max = 0.5;
	lmt.im_min = -1.25;
	lmt.im_max = 1.25;
	lmt.re_range = (lmt.re_max - lmt.re_min) / WIDTH;
	lmt.im_range = (lmt.im_max - lmt.im_min) / HEIGHT;
	return (lmt);
}
