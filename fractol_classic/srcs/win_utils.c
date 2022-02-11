/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:46:56 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:56:31 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	window_finish(t_data *data)
{
	if (data && data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data && data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data && data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
	exit(0);
	return (0);
}

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
