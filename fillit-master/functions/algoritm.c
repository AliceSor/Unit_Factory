/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:36:09 by asoroka           #+#    #+#             */
/*   Updated: 2017/01/01 15:10:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

char	**algoritm(t_list *new)
{
	int		size;
	char	**map;

	size = map_size(new) + 6;
	map = create_map(size);
	while ((backtracking(map, new)) == NULL)
	{
		size++;
		free(map);
		map = create_map(size);
	}
	return (map);
}
