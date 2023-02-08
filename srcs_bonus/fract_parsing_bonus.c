/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogi <edogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:50:12 by egiacomi          #+#    #+#             */
/*   Updated: 2023/02/08 00:25:02 by edogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	help_user(t_data *data)
{
	ft_putstr_fd("\033[1mUsage:\033[0m ./Blow_Your_Mind <fractal set> <color mode> ", 1);
	ft_putstr_fd("<optional : Julia Parameters>\n", 1);
	ft_putstr_fd("\n\033[1m\tFractal sets :\033[0m\n - Mandelbrot\n - Julia ", 1);
	ft_putstr_fd("(to add parameters to Julia's set, check bellow)\n", 1);
	ft_putstr_fd(" - Burn \n - Arrow \n - Corn \n", 1);
	ft_putstr_fd("\n\033[1m\tColor mode :\033[0m\n - \033[31mR\033[0m : Red\n - \033[32mG\033[0m : Green\n", 1);
	ft_putstr_fd(" - \033[34mB\033[0m : Blue\n - \033[35mM\033[0m : Multi\n", 1);
	ft_putstr_fd("\n\033[1m\tJulia's parameters :\033[0m\n Enter two floats numbers", 1);
	ft_putstr_fd(" from -2 to 2 [DON'T FORGET \".0\" after the number]", 1);
	ft_putstr_fd("\n\033[1m\tExamples :\033[0m\n\t./Blow_Your_Mind M B", 1);
	ft_putstr_fd("\n\t./Blow_Your_Mind J R -1.0 0.75\n", 1);
	ft_putstr_fd("\n\033[1m\tINVALID JULIA'S PARAMETER WILL BE CONSIDERED AS 0 !\033[0m\n", 1);
	ft_putstr_fd("\n\n\033[1mGuide to Use the Program :\033[0m\n", 1);
	ft_putstr_fd(" - Use 'WASD' keys to move\n - Use 'I' and 'O' keys to zoom in and out\n", 1);
	ft_putstr_fd(" - Press 'C' to change color\n - Press 'R' to reset position\n", 1);
	ft_putstr_fd(" - Press 'Esc' to exit the program\n\n", 1);
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
	if (!ft_strncmp(set, "Burn", ft_strlen("Burn")))
		return (&bship_set);
	if (!ft_strncmp(set, "Arrow", ft_strlen("Arrow")))
		return (&arrow_set);
	if (!ft_strncmp(set, "Corn", ft_strlen("Corn")))
		return (&corn_set);
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
