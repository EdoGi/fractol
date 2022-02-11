/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:52:23 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:55:49 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(int *)pixel = color;
}
