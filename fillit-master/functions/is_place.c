/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:22:08 by asoroka           #+#    #+#             */
/*   Updated: 2017/01/01 16:44:12 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int		is_place(char **map, t_list *tet)
{
	int		y;
	int		x;
	int		len_map;

	y = 0;
	len_map = ft_strlen(map[0]);
	while (y + 4 <= len_map)
	{
		x = 0;
		while (x + 4 <= len_map)
		{
			if (map[y + (int)DEF1][x + (int)DEF2] == '.'
					&& map[y + (int)DEF3][x + (int)DEF4] == '.'
					&& map[y + (int)DEF5][x + (int)DEF6] == '.'
					&& map[y + (int)DEF7][x + (int)DEF8] == '.')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
