/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:22:59 by egiacomi          #+#    #+#             */
/*   Updated: 2022/02/10 18:56:15 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
