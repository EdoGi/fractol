/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:52:17 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/08 17:55:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	event_init(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &loop_handler, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_handler, data);
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, &mouse_handler, data);
	mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask,
		&pointer_handler, data);
}

int	window_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_error(data, "mlx_init error");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Be Amazed");
	if (data->win_ptr == NULL)
		ft_error(data, "mlx new_win error");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (data->img.img_ptr == NULL)
		ft_error(data, "new_img error");
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (data->img.addr == NULL || data->img.img_ptr == NULL)
		ft_error(data, "img addr error");
	data->fract.img = &data->img;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_error(data, "malloc error");
	ft_memset(data, 0, sizeof(t_data));
	if (fractal_parse(ac, av, data))
		ft_error(data, "fractal parse error");
	if (window_init(data))
	{
		window_finish(data);
		return (ERROR);
	}
	fractal_init(&data->fract, av);
	event_init(data);
	mlx_loop(data->mlx_ptr);
	window_finish(data);
	return (0);
}
