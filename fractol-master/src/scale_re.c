/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_re.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:39:55 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/20 20:28:33 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double			scale_re(int x, t_lmt l)
{
		return (x * l.re_range + l.re_min);
}

double			scale_im(int y, t_lmt l)
{
	return (y * l.im_range + l.im_min);
}
