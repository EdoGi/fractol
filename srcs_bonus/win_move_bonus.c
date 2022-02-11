/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:31:59 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:51:54 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	move_up(t_fract *fract, double ratio)
{
	int	mv_pix;
	int	x;
	int	y;

	mv_pix = ratio * WIN_H;
	x = 0;
	while (++x <= WIN_W)
	{
		y = WIN_H + 1;
		while (--y - mv_pix >= 0)
			put_pixel_img(*fract->img, x, y,
				get_px_color(x, y - mv_pix, *fract->img));
	}
	fract->max_im += ratio * fract->amp_im;
	fract->min_im += ratio * fract->amp_im;
	fract->img->range_x[0] = 0;
	fract->img->range_x[1] = WIN_W;
	fract->img->range_y[0] = 0;
	fract->img->range_y[1] = mv_pix;
	fract->amp_im = fract->max_im - fract->min_im;
	fract->y_pos += ratio * fract->amp_im;
	fract->ft_render(fract->img, *fract);
}

void	move_down(t_fract *fract, double ratio)
{
	int	mv_pix;
	int	x;
	int	y;

	mv_pix = ratio * WIN_H;
	x = 0;
	while (++x <= WIN_W)
	{
		y = -1;
		while (++y + mv_pix <= WIN_H)
			put_pixel_img(*fract->img, x, y,
				get_px_color(x, y + mv_pix, *fract->img));
	}
	fract->img->range_x[0] = 0;
	fract->img->range_x[1] = WIN_W;
	fract->img->range_y[0] = WIN_H - mv_pix;
	fract->img->range_y[1] = WIN_H;
	fract->max_im -= ratio * fract->amp_im;
	fract->min_im -= ratio * fract->amp_im;
	fract->amp_im = fract->max_im - fract->min_im;
	fract->y_pos -= ratio * fract->amp_im;
	fract->ft_render(fract->img, *fract);
}

void	move_right(t_fract *fract, double ratio)
{
	int	mv_pix;
	int	x;
	int	y;

	mv_pix = ratio * WIN_W;
	x = -1;
	while (++x + mv_pix <= WIN_W)
	{
		y = -1;
		while (++y <= WIN_H)
			put_pixel_img(*fract->img, x, y,
				get_px_color(x + mv_pix, y, *fract->img));
	}
	fract->img->range_x[0] = WIN_W - mv_pix;
	fract->img->range_x[1] = WIN_W;
	fract->img->range_y[0] = 0;
	fract->img->range_y[1] = WIN_H;
	fract->max_re += ratio * fract->amp_re;
	fract->min_re += ratio * fract->amp_re;
	fract->amp_re = fract->max_re - fract->min_re;
	fract->x_pos += ratio * fract->amp_re;
	fract->ft_render(fract->img, *fract);
}

void	move_left(t_fract *fract, double ratio)
{
	int	mv_pix;
	int	x;
	int	y;

	mv_pix = ratio * WIN_W;
	x = WIN_W;
	while (--x - mv_pix >= 0)
	{
		y = -1;
		while (++y <= WIN_H)
			put_pixel_img(*fract->img, x, y,
				get_px_color(x - mv_pix, y, *fract->img));
	}
	fract->img->range_x[0] = 0;
	fract->img->range_x[1] = mv_pix;
	fract->img->range_y[0] = 0;
	fract->img->range_y[1] = WIN_H;
	fract->max_re -= ratio * fract->amp_re;
	fract->min_re -= ratio * fract->amp_re;
	fract->amp_re = fract->max_re - fract->min_re;
	fract->x_pos -= ratio * fract->amp_re;
	fract->ft_render(fract->img, *fract);
}

void	move(int keycode, t_data *data)
{
	double	ratio;

	ratio = 0.1;
	if (keycode == XK_a || keycode == XK_Left)
		move_left(&data->fract, ratio);
	if (keycode == XK_w || keycode == XK_Up)
		move_up(&data->fract, ratio);
	if (keycode == XK_d || keycode == XK_Right)
		move_right(&data->fract, ratio);
	if (keycode == XK_s || keycode == XK_Down)
		move_down(&data->fract, ratio);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
