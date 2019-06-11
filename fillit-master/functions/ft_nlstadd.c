/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:43:58 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/31 19:59:54 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	ft_nlstadd(t_list *nlst, int **tet)
{
	while (nlst->next)
		nlst = nlst->next;
	nlst->next = ft_nlstnew(tet, (nlst->letter + 1));
}
