/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:27 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:52:10 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	corn_count(int count_w, int count_h, int iter, t_fract fract)
{
	t_complex	z;
	double		x_new;

	fract.param.re = ((count_w - WIN_W / 2) * fract.amp_re / WIN_W)
		+ fract.x_pos;
	fract.param.im = ((WIN_H / 2) - count_h) * fract.amp_im / WIN_H
		+ fract.y_pos;
	z.re = 0;
	z.im = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(z.re, 5) - 10 * pow(z.re, 3) * pow(z.im, 2)
			+ 5 * z.re * pow(z.im, 4) + fract.param.re;
		z.im = -5 * pow(z.re, 4) * z.im + 10 * pow(z.re, 2) * pow(z.im, 3)
			- pow(z.im, 5) + fract.param.im;
		z.re = x_new;
		iter++;
	}
	return (iter);
}

void	corn_set(t_img *img, t_fract fract)
{
	int	count_h;
	int	count_w;
	int	color;
	int	iter;

	count_h = img->range_y[0] - 1;
	while (++count_h < WIN_H && count_h < img->range_y[1])
	{
		count_w = img->range_x[0] - 1;
		while (++count_w < WIN_W && count_w < img->range_x[1])
		{
			iter = corn_count(count_w, count_h, 0, fract);
			if (iter < fract.iter_max)
			{
				color = fract.ft_color(fract.iter_max, iter);
				put_pixel_img(*img, count_w, count_h, color);
			}
			else
				put_pixel_img(*img, count_w, count_h, BLACK);
		}
	}
}
