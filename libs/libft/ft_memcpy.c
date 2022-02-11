/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:58:40 by egiacomi          #+#    #+#             */
/*   Updated: 2021/06/19 17:58:40 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*srcoct;
	unsigned char	*dstoct;

	srcoct = (unsigned char *)src;
	dstoct = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	while (n--)
		*dstoct++ = *srcoct++;
	return (dest);
}
