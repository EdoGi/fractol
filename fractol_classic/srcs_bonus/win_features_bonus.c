/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_features_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:22:59 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:52:11 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	zoom_in(t_fract *fract)
{
	fract->min_im += 0.1 * fract->amp_im;
	fract->max_im -= 0.1 * fract->amp_im;
	fract->min_re += 0.1 * fract->amp_re;
	fract->max_re -= 0.1 * fract->amp_re;
	fract->amp_im = fract->max_im - fract->min_im;
	fract->amp_re = fract->max_re - fract->min_re;
	fract->render = TRUE;
}

void	zoom_out(t_fract *fract)
{
	fract->min_im -= 0.1 * fract->amp_im;
	fract->max_im += 0.1 * fract->amp_im;
	fract->min_re -= 0.1 * fract->amp_re;
	fract->max_re += 0.1 * fract->amp_re;
	fract->amp_im = fract->max_im - fract->min_im;
	fract->amp_re = fract->max_re - fract->min_re;
	fract->render = TRUE;
}

void	change_color(t_fract *fract)
{
	if (fract->c > 4)
		fract->c = 0;
	if (fract->c == 0)
		fract->ft_color = color_parse('M');
	if (fract->c == 1)
		fract->ft_color = color_parse('R');
	if (fract->c == 2)
		fract->ft_color = color_parse('G');
	if (fract->c == 3)
		fract->ft_color = color_parse('S');
	if (fract->c == 4)
		fract->ft_color = color_parse('W');
	fract->render = TRUE;
	fract->c++;
}

void	reset(t_fract *fract)
{
	fract->min_re = -2.0;
	fract->max_re = 2.0;
	fract->min_im = -2.0;
	fract->max_im = 2.0;
	fract->amp_im = fract->max_im - fract->min_im;
	fract->amp_re = fract->max_re - fract->min_re;
	fract->render = TRUE;
}
