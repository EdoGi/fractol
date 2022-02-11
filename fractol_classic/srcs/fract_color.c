/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:28:54 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 17:23:48 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	color_multi(int iter_max, int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	(void)iter_max;
	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8)
		+ ((int)(255.999 * b));
	return (color);
}

int	color_red(int iter_max, int iter)
{
	double	r;
	int		color;

	r = cos(((double)iter / (double)iter_max)) * 127 + 128;
	color = (int)0x010000 * r;
	return (color);
}

int	color_green(int iter_max, int iter)
{
	double	g;
	double	color;

	g = -255 * (double)iter / (double)iter_max + 255;
	color = (int)0x000100 * g;
	return (color);
}

int	color_shape(int iter_max, int iter)
{
	double	r;
	double	g;
	double	b;
	double	color;

	r = ((double)iter / (double)iter_max) * -255 + 255;
	g = ((double)iter / (double)iter_max) * -255 + 255;
	b = ((double)iter / (double)iter_max) * -255 + 255;
	color = ((int)(255 * r) << 16) + ((int)(255 * g) << 8)
		+ ((int)(255 * b));
	return (color);
}

int	color_white(int iter_max, int iter)
{
	(void)iter;
	(void)iter_max;
	return (0xFFFFFF);
}
