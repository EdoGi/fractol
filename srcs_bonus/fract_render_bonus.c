/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:11:58 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:52:06 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	mandelbrot_count(int count_w, int count_h, int iter, t_fract fract)
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
		x_new = pow(z.re, 2.0) - pow(z.im, 2.0) + fract.param.re;
		z.im = 2 * z.re * z.im + fract.param.im;
		z.re = x_new;
		iter++;
	}
	return (iter);
}

int	julia_count(int count_w, int count_h, int iter, t_fract fract)
{
	t_complex	z;
	double		x_new;

	z.re = ((count_w - WIN_W / 2) * fract.amp_re / WIN_W)
		+ fract.x_pos;
	z.im = ((WIN_H / 2) - count_h) * fract.amp_im / WIN_H
		+ fract.y_pos;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(z.re, 2.0) - pow(z.im, 2.0) + fract.param.re;
		z.im = 2 * z.re * z.im + fract.param.im;
		z.re = x_new;
		iter++;
	}
	return (iter);
}

void	mandelbrot_set(t_img *img, t_fract fract)
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
			iter = mandelbrot_count(count_w, count_h, 0, fract);
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

void	julia_set(t_img *img, t_fract fract)
{
	int	count_h;
	int	count_w;
	int	color;
	int	iter;

	count_h = img->range_y[0] - 1;
	while (++count_h < img->range_y[1])
	{
		count_w = img->range_x[0] - 1;
		while (++count_w < img->range_x[1])
		{
			iter = julia_count(count_w, count_h, 0, fract);
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
