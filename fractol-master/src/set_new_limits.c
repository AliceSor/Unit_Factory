/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_limits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:47:22 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/26 18:49:09 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			set_new_limits(t_frct *frct, int x, int y, double mult)
{
	t_lmt		lmt;
	t_lmt		new_lmt;
	double		pos_re;
	double		pos_im;

	lmt = frct->lmt;
	pos_re = scale_re(x, lmt);
	pos_im = scale_im(y, lmt);
	new_lmt.re_max = lmt.re_max * mult + pos_re * (1 - mult);
	new_lmt.re_min = lmt.re_min * mult + pos_re * (1 - mult);
	new_lmt.im_max = lmt.im_max * mult + pos_im * (1 - mult);
	new_lmt.im_min = lmt.im_min * mult + pos_im * (1 - mult);
	new_lmt.re_range = (new_lmt.re_max - new_lmt.re_min) / WIDTH;
	new_lmt.im_range = (new_lmt.im_max - new_lmt.im_min) / HEIGHT;
	frct->lmt = new_lmt;
}
