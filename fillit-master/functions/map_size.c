/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:31:55 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/31 18:10:27 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int		map_size(t_list *tet)
{
	int		x;
	int		count;
	t_list	*tmp;

	tmp = tet;
	count = 0;
	x = 2;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	while (4 * count > x * x)
		x++;
	return (x);
}
