/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:17:00 by asvirido          #+#    #+#             */
/*   Updated: 2016/12/31 19:57:12 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static void		ft_put(char *s1)
{
	int		i;

	i = 3;
	while (s1[i])
	{
		if (s1[i] == '.')
			write(1, &s1[i], 1);
		else if (s1[i] >= 'A' && s1[i] <= 'Z')
			write(1, &s1[i], 1);
		i++;
	}
}

void			ft_print(char **s)
{
	int		i;
	int		j;

	j = 0;
	i = 3;
	while (s[j])
		j++;
	while (s[i] && i < j - 4)
	{
		ft_put(s[i]);
		write(1, "\n", 1);
		i++;
	}
}
