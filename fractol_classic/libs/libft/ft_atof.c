/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:26:49 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 17:07:41 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int	ft_c_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (0);
		++charset;
	}
	return (1);
}

int	ft_is_charset(const char *str, char *charset)
{
	int	i;

	i = 0;
	while (!ft_c_in_charset(str[i], charset) && str[i])
		++i;
	if (str[i] == '\0')
		return (0);
	return (1);
}

long long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	return (ret * sign);
}

double	ft_atof(char *str)
{
	double			result;
	int				i;
	unsigned int	len;

	i = 0;
	result = 0.0;
	if (ft_is_charset(str, "-+.0123456789"))
		return (0.0);
	result = (double)ft_atol(str);
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] == '.' && str[i + 1])
	{
		++i;
		len = ft_strlen(str) - i;
		result += (double)ft_atol(str + i) / pow(10, len);
	}
	return (result);
}
