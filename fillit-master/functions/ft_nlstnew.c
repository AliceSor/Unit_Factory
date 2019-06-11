/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:23:28 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/29 15:35:55 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

t_list		*ft_nlstnew(int **tet, char let)
{
	t_list	*nw;

	nw = (t_list *)malloc(sizeof(t_list));
	if (nw)
	{
		nw->tetrim = tet;
		nw->letter = let;
		nw->next = NULL;
		return (nw);
	}
	else
		return (NULL);
}
