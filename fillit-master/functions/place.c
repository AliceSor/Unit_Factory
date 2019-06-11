/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:16:34 by asoroka           #+#    #+#             */
/*   Updated: 2017/01/01 14:54:42 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int		place(char **map, t_list *tet, int y, int x)
{
	if (map[y + (int)DEF1][x + (int)DEF2] == '.' &&
			map[y + (int)DEF3][x + (int)DEF4] == '.' &&
			map[y + (int)DEF5][x + (int)DEF6] == '.' &&
			map[y + (int)DEF7][x + (int)DEF8] == '.')
		return (1);
	return (0);
}
