/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 20:00:56 by asvirido          #+#    #+#             */
/*   Updated: 2016/12/31 20:00:58 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int		main(int argc, char **argv)
{
	t_list	*new;
	char	**s;

	if (argc != 2)
		ft_putstr("usage: ./fillit source_file");
	else
	{
		new = open_read_close_file(argv[1]);
		s = algoritm(new);
		ft_print(s);
	}
	return (0);
}
