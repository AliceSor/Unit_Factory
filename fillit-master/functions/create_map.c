/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:31:32 by asoroka           #+#    #+#             */
/*   Updated: 2017/01/01 15:01:44 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static char		**create_string(int size)
{
	char	**s;
	int		y;
	int		x;

	y = 0;
	s = (char**)malloc(sizeof(char*) * (size + 2));
	while (y <= size)
	{
		s[y] = (char*)malloc(sizeof(char) * (size + 1));
		ft_bzero(s[y], size + 1);
		if (y < 3)
		{
			x = 0;
			while (x < size)
			{
				s[y][x] = '~';
				x++;
			}
		}
		y++;
	}
	s[y] = NULL;
	return (s);
}

static char		**fill_tilida(char **s, int size)
{
	int		y;
	int		x;
	int		count;

	count = 0;
	y = 3;
	while (count <= 3)
	{
		x = 0;
		while (x < size)
		{
			s[size - count][x] = '~';
			x++;
		}
		count++;
	}
	return (s);
}

char			**create_map(int size)
{
	int		y;
	int		x;
	char	**s;

	s = create_string(size);
	s = fill_tilida(s, size);
	y = 3;
	while (y < size - 3)
	{
		x = 0;
		while (x < size)
		{
			if (x < 3 || x > size - 4)
				s[y][x] = '~';
			else
				s[y][x] = '.';
			x++;
		}
		y++;
	}
	return (s);
}
