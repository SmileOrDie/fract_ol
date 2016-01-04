/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 13:30:27 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 17:41:57 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_lite_2(int i, int j, t_env *e)
{
	int pos;

	pos = (j * e->img1.sizeline) + i * (e->img1.bpp / 8);
	if (e->fract == 1)
		put_pixel_to_img(e, pos, julia(i, j, e, e->img1), e->img1);
	else if (e->fract == 2)
		put_pixel_to_img(e, pos, mandel(i, j, e, e->img1), e->img1);
	else if (e->fract == 3)
		put_pixel_to_img(e, pos, fract3(i, j, e, e->img1), e->img1);
	else if (e->fract == 4)
		put_pixel_to_img(e, pos, fract4(i, j, e, e->img1), e->img1);
	else if (e->fract == 5)
		put_pixel_to_img(e, pos, fract5(i, j, e, e->img1), e->img1);
	if (e->img2.data)
	{
		pos = (j * e->img2.sizeline) + i * (e->img2.bpp / 8);
		put_pixel_to_img(e, pos, fract5(i, j, e, e->img2), e->img2);
	}
}

void	draw_lite(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < e->width)
	{
		j = 0;
		while (j < e->height)
		{
			draw_lite_2(i, j, e);
			j++;
		}
	}
}

void	color_cmi(t_env *e, t_fract f)
{
	e->c = get_color
		(f.i * (e->color & 0b00001100),
		f.i * (e->color & 0b00110000),
		f.i * (e->color & 0b11000000));
}

void	color_ci(t_env *e, t_fract f)
{
	e->c = get_color
		(f.i * (e->color & 0b00001100) >> 2,
		f.i * (e->color & 0b00110000) >> 4,
		f.i * (e->color & 0b11000000) >> 6);
}

void	color_c(t_env *e)
{
	e->c = get_color
		((e->color & 0b00001100) >> 2,
		(e->color & 0b00110000) >> 4,
		(e->color & 0b11000000) >> 6);
}
