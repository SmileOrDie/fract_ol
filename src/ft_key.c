/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:10:04 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 12:07:31 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	key_hook_ter(int key, t_env *e)
{
	if (key == 'p')
		e->color += 5;
	else if (key == 'm')
		e->col = e->col == 1 ? 0 : 1;
	else if (key == 'r')
		init(e);
	else if (key == 's')
		e->mouss = e->mouss == 1 ? 0 : 1;
	else if (key == 'j')
		e->jul = e->jul == 1 ? 0 : 1;
	else if (key == 'i')
		e->maxiterations += 1;
	else if (key == 'u')
		e->maxiterations -= 1;
	e->changed = 1;
}

void	key_hook_bis(int key, t_env *e)
{
	if (key == 65362)
	{
		if (e->jul == 0)
			e->img2.movey += 0.001;
		else
			e->img1.movey += 0.001;
	}
	else if (key == 65363)
	{
		if (e->jul == 0)
			e->img2.movex -= 0.001;
		else
			e->img1.movex -= 0.001;
	}
	else if (key == 65361)
	{
		if (e->jul == 0)
			e->img2.movex += 0.001;
		else
			e->img1.movex += 0.001;
	}
	key_hook_ter(key, e);
}

int		key_hook(int key, t_env *e)
{
	if (key == 65307)
		exit(0);
	else if (key == 65451)
	{
		if (e->jul == 0)
			e->img2.zoom += 1;
		else
			e->img1.zoom += 1;
	}
	else if (key == 65453)
	{
		if (e->jul == 0)
			e->img2.zoom -= 1;
		else
			e->img1.zoom -= 1;
	}
	else if (key == 65364)
	{
		if (e->jul == 0)
			e->img2.movey -= 0.001;
		else
			e->img1.movey -= 0.001;
	}
	key_hook_bis(key, e);
	return (0);
}
