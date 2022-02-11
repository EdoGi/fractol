/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:55:21 by egiacomi          #+#    #+#             */
/*   Updated: 2021/06/19 17:55:21 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (*lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			if ((*del))
				(*del)((*lst)->content);
			free(*lst);
			(*lst) = tmp;
		}
	}
}
