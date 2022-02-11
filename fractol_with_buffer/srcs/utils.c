/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:46:56 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/08 00:04:12 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_isfloat(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			point++;
			if (point > 1)
				return (0);
		}
		else if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		i++;
	}
	if (point != 1)
		return (0);
	return (1);
}

void	ft_error(t_data *data, const char *ft_name)
{
	ft_putstr_fd("Error: ", 2);
	perror(ft_name);
	window_finish(data);
}
