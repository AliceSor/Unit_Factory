/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:44:59 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/31 18:33:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void			fill(char **map, t_list *tet, int y, int x)
{
	map[y + (int)DEF1][x + (int)DEF2] = tet->letter;
	map[y + (int)DEF3][x + (int)DEF4] = tet->letter;
	map[y + (int)DEF5][x + (int)DEF6] = tet->letter;
	map[y + (int)DEF7][x + (int)DEF8] = tet->letter;
}
