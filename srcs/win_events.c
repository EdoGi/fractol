/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:05:53 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:56:08 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	loop_handler(t_data *data)
{
	data->img.range_x[0] = 0;
	data->img.range_x[1] = WIN_W;
	data->img.range_y[0] = 0;
	data->img.range_y[1] = WIN_H;
	if (data->fract.render == TRUE)
	{	
		data->fract.ft_render(&data->img, data->fract);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_ptr, 0, 0);
		data->fract.render = FALSE;
	}
	return (0);
}

int	pointer_handler(int x, int y, t_data *data)
{
	if (data->fract.ft_render == &julia_set
		&& x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H)
	{
		data->fract.param.re = ((x - WIN_W / 2) * data->fract.amp_re / WIN_W);
		data->fract.param.im = ((WIN_H / 2) - y) * data->fract.amp_im / WIN_H;
		data->fract.render = TRUE;
	}
	return (0);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		window_finish(data);
	else if (keycode == XK_i)
		zoom_in(&data->fract);
	else if (keycode == XK_o)
		zoom_out(&data->fract);
	else if (keycode == XK_r)
		reset(&data->fract);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_data *data)
{
	double	ratio;

	(void)ratio;
	ratio = 0.1;
	(void)y;
	(void)x;
	if (button == ZOOMIN)
		zoom_in(&data->fract);
	else if (button == ZOOMOUT)
		zoom_out(&data->fract);
	return (0);
}
