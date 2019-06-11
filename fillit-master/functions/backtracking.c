/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 15:15:26 by asvirido          #+#    #+#             */
/*   Updated: 2017/01/01 16:45:14 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

char		**backtracking(char **map, t_list *tet)
{
	int		y;
	int		x;

	y = 0;
	if (tet == NULL)
		return (map);
	while (((is_place(map, tet)) == 1) && map[y + 3])
	{
		x = 0;
		while (map[y + 3][x + 3])
		{
			if ((place(map, tet, y, x)) == 1)
			{
				fill(map, tet, y, x);
				if (backtracking(map, tet->next))
					return (map);
				else
					deleted(map, tet->letter);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}
