/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:31:59 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/08 23:08:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_up(t_data *data, double ratio)
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
			put_pixel_img(data, x, y,
				get_px_color(x, y - mv_pix, data));
	}
	data->fract.max_im += ratio * data->fract.amp_im;
	data->fract.min_im += ratio * data->fract.amp_im;
	data->fract.img->range_x[0] = 0;
	data->fract.img->range_x[1] = WIN_W;
	data->fract.img->range_y[0] = 0;
	data->fract.img->range_y[1] = mv_pix;
	data->fract.amp_im = data->fract.max_im - data->fract.min_im;
	data->fract.y_pos += ratio * data->fract.amp_im;
	data->fract.ft_render(data, data->fract);
}

void	move_down(t_data *data, double ratio)
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
			put_pixel_img(data, x, y,
				get_px_color(x, y + mv_pix, data));
	}
	data->fract.img->range_x[0] = 0;
	data->fract.img->range_x[1] = WIN_W;
	data->fract.img->range_y[0] = WIN_H - mv_pix;
	data->fract.img->range_y[1] = WIN_H;
	data->fract.max_im -= ratio * data->fract.amp_im;
	data->fract.min_im -= ratio * data->fract.amp_im;
	data->fract.amp_im = data->fract.max_im - data->fract.min_im;
	data->fract.y_pos -= ratio * data->fract.amp_im;
	data->fract.ft_render(data, data->fract);
}

void	move_right(t_data *data, double ratio)
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
			put_pixel_img(data, x, y,
				get_px_color(x + mv_pix, y, data));
	}
	data->fract.img->range_x[0] = WIN_W - mv_pix;
	data->fract.img->range_x[1] = WIN_W;
	data->fract.img->range_y[0] = 0;
	data->fract.img->range_y[1] = WIN_H;
	data->fract.max_re += ratio * data->fract.amp_re;
	data->fract.min_re += ratio * data->fract.amp_re;
	data->fract.amp_re = data->fract.max_re - data->fract.min_re;
	data->fract.x_pos += ratio * data->fract.amp_re;
	data->fract.ft_render(data, data->fract);
}

void	move_left(t_data *data, double ratio)
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
			put_pixel_img(data, x, y,
				get_px_color(x - mv_pix, y, data));
	}
	data->fract.img->range_x[0] = 0;
	data->fract.img->range_x[1] = mv_pix;
	data->fract.img->range_y[0] = 0;
	data->fract.img->range_y[1] = WIN_H;
	data->fract.max_re -= ratio * data->fract.amp_re;
	data->fract.min_re -= ratio * data->fract.amp_re;
	data->fract.amp_re = data->fract.max_re - data->fract.min_re;
	data->fract.x_pos -= ratio * data->fract.amp_re;
	data->fract.ft_render(data, data->fract);
}

void	move(int keycode, t_data *data)
{
	double	ratio;

	ratio = 0.1;
	if (keycode == XK_a || keycode == XK_Left)
		move_left(data, ratio);
	if (keycode == XK_w || keycode == XK_Up)
		move_up(data, ratio);
	if (keycode == XK_d || keycode == XK_Right)
		move_right(data, ratio);
	if (keycode == XK_s || keycode == XK_Down)
		move_down(data, ratio);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
