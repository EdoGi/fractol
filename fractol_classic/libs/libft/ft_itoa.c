/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:15:21 by egiacomi          #+#    #+#             */
/*   Updated: 2021/06/23 16:16:15 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_intlen(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_itoalloc(int n)
{
	int		size;
	int		neg;
	char	*allocated;

	neg = 0;
	if (n < 0)
		neg = 1;
	size = ft_intlen(n);
	allocated = (char *)malloc(sizeof(char) * (size + 1));
	if (!allocated)
		return (NULL);
	allocated[size] = '\0';
	if (neg)
		allocated[0] = '-';
	return (allocated);
}

char	*ft_itoa(int n)
{
	char	*numalpha;
	int		intlen;
	int		j;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	numalpha = ft_itoalloc(n);
	if (numalpha == NULL)
		return (0);
	intlen = ft_intlen(n);
	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	j = 1;
	while (intlen-- > i)
	{
		numalpha[intlen] = (n / j) % 10 + '0';
		j *= 10;
	}
	return (numalpha);
}
