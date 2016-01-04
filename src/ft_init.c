/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:10:25 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 18:16:04 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init(t_env *e)
{
	e->mouss = 0;
	e->changed = 0;
	e->color = 255;
	e->img1.zoom = 1;
	e->img2.zoom = 1;
	e->img1.movex = 0;
	e->img1.movey = 0;
	e->img2.movex = 0;
	e->img2.movey = 0;
	e->maxiterations = 300;
	e->img2.cre = 0;
	e->img2.cim = 0;
	e->img1.lastx = 0;
	e->img1.lasty = 0;
	e->img2.lastx = 0;
	e->img2.lasty = 0;
	e->jul = 1;
	init2(e);
}

void	init2(t_env *e)
{
	e->col = 1;
	if (e->fract == 1 || e->fract == 3)
	{
		e->img1.cre = -0.7;
		e->img1.cim = 0.27015;
		e->img1.zoom = 1;
	}
	else
	{
		e->img1.cre = 0;
		e->img1.cim = 0;
		e->img1.zoom = 1;
	}
}

void	print_error(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("env is not valide!\n", 2);
		exit(0);
	}
	else if (i == 2)
	{
		ft_putstr_fd("\narg valid is :\n\n", 2);
		ft_putstr_fd("j : for julia\n", 2);
		ft_putstr_fd("m : for mandelbrot\n", 2);
		ft_putstr_fd("P : for fract3\n", 2);
		ft_putstr_fd("t : for fract4\n", 2);
		ft_putstr_fd("l : for fract5\n", 2);
		exit(0);
	}
	else if (i == 3)
	{
		ft_putstr_fd(" : was not define\n", 2);
		print_error(2);
	}
	else if (i == 4)
	{
		ft_putstr_fd("give an argument\n", 2);
		print_error(2);
	}
}
