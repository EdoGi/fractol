/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogi <edogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:22:39 by egiacomi          #+#    #+#             */
/*   Updated: 2023/02/08 00:18:29 by edogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../libs/mlx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_W 500
# define WIN_H 500

# define TRUE 1
# define FALSE 0

# define ZOOMIN 4
# define ZOOMOUT 5

# define ERROR 1

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define ITER_MAX 100

typedef struct s_complex
{
	double		re;
	double		im;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		range_x[2];
	int		range_y[2];
}	t_img;

typedef struct s_fract
{
	void		(*ft_render)(t_img *img, struct s_fract fractal);
	int			(*ft_color)(int, int);
	int			c;
	t_complex	param;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		amp_im;
	double		amp_re;
	double		x_pos;
	double		y_pos;
	int			render;
	int			iter_max;
	t_img		*img;
}	t_fract;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_fract	fract;
}	t_data;

/* === MAIN === */
int		main(int ac, char **av);
int		window_init(t_data *data);
void	event_init(t_data *data);

/* === PARSE === */
void	*fract_type(char *set);
int		fractal_parse(int ac, char **av, t_data *data);
void	julia_parse(char **av, t_data *data);
void	*color_parse(char color);
void	help_user(t_data *data);

/* === EVENT === */
int		loop_handler(t_data *data);
int		pointer_handler(int x, int y, t_data *data);
int		key_handler(int keycode, t_data *data);
int		mouse_handler(int button, int x, int y, t_data *data);

/* === UTILS === */
int		ft_isfloat(char *str);
void	ft_error(t_data *data, const char *ft_name);
int		window_finish(t_data *data);
void	put_pixel_img(t_img img, int x, int y, int color);
int		get_px_color(int x, int y, t_img img);

/* === FRACTAL === */
void	fractal_init(t_fract *fract, char **av);
void	all_init(t_fract *fract);
void	julia_init(t_fract *fract, char **av);
void	mandelbrot_set(t_img *img, t_fract fract);
void	julia_set(t_img *img, t_fract fract);
void	bship_set(t_img *img, t_fract fract);
void	arrow_set(t_img *img, t_fract fract);
void	corn_set(t_img *img, t_fract fract);
int		mandelbrot_count(int count_w, int count_h, int iter, t_fract fract);
int		julia_count(int count_w, int count_h, int iter, t_fract fract);
int		bship_count(int count_w, int count_h, int iter, t_fract fract);
int		arrow_count(int count_w, int count_h, int iter, t_fract fract);
int		corn_count(int count_w, int count_h, int iter, t_fract fract);

/* === FEATURES === */
void	zoom_in(t_fract *fract);
void	zoom_out(t_fract *fract);
void	move(int keycode, t_data *data);
void	move_left(t_fract *fract, double ratio);
void	move_right(t_fract *fract, double ratio);
void	move_up(t_fract *fract, double ratio);
void	move_down(t_fract *fract, double ratio);
void	reset(t_fract *image);

/* === COLOR === */
int		color_multi(int iter_max, int iter);
int		color_red(int iter_max, int iter);
int		color_green(int iter_max, int iter);
int		color_shape(int iter_max, int iter);
int		color_white(int iter_max, int iter);
void	change_color(t_fract *fract);

#endif
