/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:15:50 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:52:07 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	all_init(t_fract *fract)
{
	fract->min_re = -2.0;
	fract->max_re = 1.0;
	fract->min_im = -1.5;
	fract->max_im = 1.5;
	fract->x_pos = -0.5;
	fract->y_pos = 0;
}

void	julia_init(t_fract *fract, char **av)
{
	fract->min_re = -2.0;
	fract->max_re = 2.0;
	fract->min_im = -2.0;
	fract->max_im = 2.0;
	if (av[3] && ft_isfloat(av[3]))
		fract->param.re = ft_atof(av[3]);
	if (av[4] && ft_isfloat(av[4]))
		fract->param.im = ft_atof(av[4]);
	fract->x_pos = 0.0;
	fract->y_pos = 0.0;
}

void	fractal_init(t_fract *fract, char **av)
{
	if (fract->ft_render == &mandelbrot_set
		|| fract->ft_render == &bship_set
		|| fract->ft_render == &arrow_set
		|| fract->ft_render == &corn_set)
		all_init(fract);
	else if (fract->ft_render == &julia_set)
		julia_init(fract, av);
	fract->amp_im = fract->max_im - fract->min_im;
	fract->amp_re = fract->max_re - fract->min_re;
	fract->iter_max = ITER_MAX;
	fract->c = 0;
	fract->render = TRUE;
}
