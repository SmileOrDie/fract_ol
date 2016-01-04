/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:06:01 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 17:26:24 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		end_mouse(t_env *e, int x, int y)
{
	e->changed = 1;
	e->img1.lastx = x;
	e->img1.lasty = y;
	e->img2.lastx = x;
	e->img2.lasty = y;
}

int			mouse_hook(int x, int y, t_env *e)
{
	if (e->jul == 1)
	{
		if (e->mouss == 1)
		{
			if (e->img1.lastx != x && e->img1.lastx != 0)
				e->img1.cre += (e->img1.lastx - x) * 0.001;
			if (e->img1.lasty != y && e->img1.lasty != 0)
				e->img1.cim += (e->img1.lasty - y) * 0.001;
		}
	}
	else
	{
		if (e->mouss == 1)
		{
			if (e->img2.lastx != x)
				e->img2.cre += (e->img2.lastx - x) * 0.001;
			if (e->img2.lasty != y)
				e->img2.cim += (e->img2.lasty - y) * 0.001;
		}
	}
	end_mouse(e, x, y);
	return (0);
}

int			mouse2_key(int key, int x, int y, t_env *e)
{
	x = y;
	if (e->jul == 1)
	{
		if ((key == 5 || key == 3))
			e->img1.zoom -= 1;
		if ((key == 6 || key == 1))
			e->img1.zoom += 1;
	}
	else
	{
		if ((key == 5 || key == 3))
			e->img2.zoom -= 1;
		if ((key == 6 || key == 1))
			e->img2.zoom += 1;
	}
	y = x;
	e->changed = 1;
	return (0);
}
