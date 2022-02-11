/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:50:12 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 19:20:33 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	help_user(t_data *data)
{
	ft_putstr_fd("Usage: ./Blow_Your_Mind <fractal set> <color mode> ", 1);
	ft_putstr_fd("<optional : Julia Parameters>\n", 1);
	ft_putstr_fd("\n\tFractal sets :\n - Mandelbrot\n - Julia ", 1);
	ft_putstr_fd("(to add parameters to Julia's set, check bellow)\n", 1);
	ft_putstr_fd(" - Burn \n - Arrow \n - Corn \n", 1);
	ft_putstr_fd("\n\tColor mode :\n - R : Red\n - G : Green\n", 1);
	ft_putstr_fd(" - B : Blue\n - M : Multi\n", 1);
	ft_putstr_fd("\n\tJulia's parameters :\n Enter two floats numbers", 1);
	ft_putstr_fd(" from -2 to 2 [DON'T FORGET \".0\" after the number]", 1);
	ft_putstr_fd("\n\tExamples :\n\t./Blow_Your_Mind M B", 1);
	ft_putstr_fd("\n\t./Blow_Your_Mind J R -1.0 0.75\n", 1);
	ft_putstr_fd("\n\tINVALID JULIA'S PARAMETER WILL BE CONSIDERED AS 0 !\n", 1);
	if (data)
	{
		free(data);
		data = NULL;
	}
	exit (0);
}

void	*fract_type(char *set)
{
	if (!ft_strncmp(set, "Mandelbrot", ft_strlen("Mandelbrot")))
		return (&mandelbrot_set);
	if (!ft_strncmp(set, "Julia", ft_strlen("Julia")))
		return (&julia_set);
	else
		return (NULL);
}

void	julia_parse(char **av, t_data *data)
{
	if (data->fract.ft_render != &julia_set)
		help_user(data);
	if (av[3] && ft_isfloat(av[3]))
		data->fract.param.re = ft_atof(av[3]);
	if (av[4] && ft_isfloat(av[4]))
		data->fract.param.im = ft_atof(av[4]);
	if (data->fract.param.re < -2 || data->fract.param.re > 2
		|| data->fract.param.im < -2 || data->fract.param.im > 2)
		help_user(data);
}

int	fractal_parse(int ac, char **av, t_data *data)
{
	if (ac <= 2 || ac > 5 || ac == 4)
		help_user(data);
	data->fract.ft_render = fract_type(av[1]);
	if (data->fract.ft_render == NULL)
		help_user(data);
	if (ft_strlen(av[2]) > 1)
		help_user(data);
	if (ac == 5)
		julia_parse(av, data);
	data->fract.ft_color = color_parse(av[2][0]);
	if (data->fract.ft_color == NULL)
		help_user(data);
	return (0);
}

void	*color_parse(char color)
{
	if (color == 'R' || color == 'r')
		return (&color_red);
	if (color == 'G' || color == 'g')
		return (&color_green);
	if (color == 'S' || color == 's')
		return (&color_shape);
	if (color == 'M' || color == 'm')
		return (&color_multi);
	if (color == 'W' || color == 'w')
		return (&color_white);
	else
		return (NULL);
}
