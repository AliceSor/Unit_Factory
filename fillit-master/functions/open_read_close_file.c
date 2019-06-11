/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:54:00 by asvirido          #+#    #+#             */
/*   Updated: 2017/01/01 15:17:12 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static t_list	*read_file(int fd, char *buf, char letter)
{
	int			**tetra;
	t_list		*new;
	int			ret;
	int			flag;

	flag = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		if (flag == 1 || letter > 'Z')
			error();
		flag = ft_strlen(buf) == 20 ? flag + 1 : flag;
		tetra = valid(buf);
		ft_bzero(buf, BUF_SIZE);
		if (letter == 'A')
			new = ft_nlstnew(tetra, letter);
		else
			ft_nlstadd(new, tetra);
		letter++;
	}
	if (flag == 0)
		error();
	return (new);
}

t_list			*open_read_close_file(char *file_name)
{
	int		fd;
	char	buf[BUF_SIZE];
	char	letter;
	t_list	*new;

	letter = 'A';
	ft_bzero(buf, BUF_SIZE);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error();
	new = read_file(fd, buf, letter);
	fd = close(fd);
	return (new);
}
