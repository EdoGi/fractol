/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:58:11 by egiacomi          #+#    #+#             */
/*   Updated: 2021/06/19 17:58:11 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*srcoct;
	unsigned char	*dstoct;

	srcoct = (unsigned char *)src;
	dstoct = (unsigned char *)dest;
	while (n--)
	{
		if (*srcoct == (unsigned char)c)
		{
			*dstoct++ = *srcoct++;
			return (dstoct);
		}
		*dstoct++ = *srcoct++;
	}
	return (NULL);
}
