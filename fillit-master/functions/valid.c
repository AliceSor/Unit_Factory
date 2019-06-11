/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:40:49 by asvirido          #+#    #+#             */
/*   Updated: 2016/12/31 20:02:49 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static void		fu_map_valid(char *s)
{
	int		i;
	int		n;
	int		sharpe;
	int		dot;

	dot = 12;
	i = 0;
	sharpe = 4;
	n = (ft_strlen(s) == 22 ? 5 : 4);
	while (s[i])
	{
		if (s[i] == '#')
			sharpe--;
		if (s[i] == '.')
			dot--;
		if (s[i] == '\n')
			n--;
		i++;
	}
	if (n != 0 || sharpe != 0 || dot != 0)
		error();
}

static char		**fu_figure_valid(char *s)
{
	int		y;
	int		x;
	int		count;
	char	**s1;

	y = -1;
	count = 0;
	s1 = ft_strsplit(s, '\n');
	while (++y <= 3)
	{
		x = -1;
		while (s1[y][++x])
		{
			if (s1[y][x] == '#')
			{
				count = x <= 3 && s1[y][x + 1] == '#' ? count + 1 : count;
				count = x >= 1 && s1[y][x - 1] == '#' ? count + 1 : count;
				count = y < 3 && s1[y + 1][x] == '#' ? count + 1 : count;
				count = y >= 1 && s1[y - 1][x] == '#' ? count + 1 : count;
			}
		}
	}
	if (count != 6 && count != 8)
		error();
	return (s1);
}

static void		fu_valid_slesh_n(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len == 22 && s[4] == '\n' && s[9] == '\n' && s[14] == '\n'
			&& s[19] == '\n' && s[20] == '\n')
		return ;
	else if (len == 20 && s[4] == '\n' && s[9] == '\n' && s[14] == '\n'
			&& s[19] == '\n')
		return ;
	else
		error();
}

static int		**coordinate_x_y(char **s, int **array)
{
	int		y;
	int		x;
	int		i;

	i = 1;
	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				array[i][0] = y;
				array[i][1] = x;
				i++;
			}
			x++;
		}
		y++;
	}
	return (array);
}

int				**valid(char *s)
{
	char	**s1;
	int		**array;
	int		i;

	i = 1;
	array = (int**)malloc(sizeof(int*) * 5);
	while (i <= 4)
	{
		array[i] = (int*)malloc(sizeof(int) * 3);
		i++;
	}
	fu_map_valid(s);
	fu_valid_slesh_n(s);
	s1 = fu_figure_valid(s);
	array = coordinate_x_y(s1, array);
	return (array);
}
