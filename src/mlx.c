/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 13:18:27 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 15:04:57 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_color			get_color(int r, int g, int b)
{
	t_color		get;

	get.r = r;
	get.g = g;
	get.b = b;
	return (get);
}

void			put_pixel_to_img(t_env *e, int pos, t_color c, t_img img)
{
	if (img.endian)
	{
		img.data[pos] =
			mlx_get_color_value(e->mlx, c.r);
		img.data[pos + 1] =
			mlx_get_color_value(e->mlx, c.g);
		img.data[pos + 2] =
			mlx_get_color_value(e->mlx, c.b);
	}
	else
	{
		img.data[pos] =
			mlx_get_color_value(e->mlx, c.b);
		img.data[pos + 1] =
			mlx_get_color_value(e->mlx, c.g);
		img.data[pos + 2] =
			mlx_get_color_value(e->mlx, c.r);
	}
}

int				expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->img1.win, e->img1.img, 0, 0);
	if (e->img2.data)
		mlx_put_image_to_window(e->mlx, e->img2.win, e->img2.img, 0, 0);
	return (0);
}

int				loop_hook(t_env *e)
{
	if (e->changed == 1)
	{
		draw_lite(e);
		mlx_put_image_to_window(e->mlx, e->img1.win, e->img1.img, 0, 0);
		if (e->img2.data)
			mlx_put_image_to_window(e->mlx, e->img2.win, e->img2.img, 0, 0);
		e->changed = 0;
	}
	return (0);
}
