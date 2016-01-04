/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 17:58:24 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 18:13:52 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_color			julia(int x, int y, t_env *e, t_img img)
{
	t_fract		f;

	f.newre = 2 * (x - e->width / 2) / (0.5 * img.zoom * e->width) + img.movex;
	f.newim = (y - e->height / 2) / (0.5 * img.zoom * e->height) + img.movey;
	f.i = -1;
	while (++f.i < e->maxiterations)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = (f.oldre * f.oldre - f.oldim * f.oldim) + img.cre;
		f.newim = (2 * f.oldre * f.oldim) + img.cim;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	if (f.i != e->maxiterations)
		e->col == 1 ? color_ci(e, f) : color_cmi(e, f);
	else
		color_c(e);
	return (e->c);
}

t_color			mandel(int x, int y, t_env *e, t_img img)
{
	t_fract		f;

	f.pr = 2 * (x - e->width / 2) / (0.5 * img.zoom * e->width) + img.movex;
	f.pi = (y - e->height / 2) / (0.5 * img.zoom * e->height) + img.movey;
	f.i = -1;
	f.newre = img.cre;
	f.newim = img.cim;
	while (++f.i < e->maxiterations)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = (f.oldre * f.oldre - f.oldim * f.oldim) + f.pr;
		f.newim = (2 * f.oldre * f.oldim) + f.pi;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	if (f.i != e->maxiterations)
		e->col == 1 ? color_ci(e, f) : color_cmi(e, f);
	else
		color_c(e);
	return (e->c);
}

t_color			fract3(int x, int y, t_env *e, t_img img)
{
	t_fract		f;

	f.newre = 2 * (x - e->width / 2) / (0.5 * img.zoom * e->width) + img.movex;
	f.newim = (y - e->height / 2) / (0.5 * img.zoom * e->height) + img.movey;
	f.i = -1;
	while (++f.i < e->maxiterations)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = pow(f.oldre, 3) - (f.oldre * f.oldim * f.oldim) + img.cre;
		f.newim = (3 * f.oldre * f.oldre * f.oldim) - pow(f.oldim, 3) + img.cim;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	if (f.i != e->maxiterations)
		e->col == 1 ? color_ci(e, f) : color_cmi(e, f);
	else
		color_c(e);
	return (e->c);
}

t_color			fract4(int x, int y, t_env *e, t_img img)
{
	t_fract		f;

	f.pr = 2 * (x - e->width / 2) / (0.5 * img.zoom * e->width) + img.movex;
	f.pi = (y - e->height / 2) / (0.5 * img.zoom * e->height) + img.movey;
	f.i = -1;
	f.newre = img.cre;
	f.newim = img.cim;
	while (++f.i < e->maxiterations)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = pow(f.oldre, 3) - (f.oldre * f.oldim * f.oldim) + f.pr;
		f.newim = (3 * f.oldre * f.oldre * f.oldim) - pow(f.oldim, 3) + f.pi;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	if (f.i != e->maxiterations)
		e->col == 1 ? color_ci(e, f) : color_cmi(e, f);
	else
		color_c(e);
	return (e->c);
}

t_color			fract5(int x, int y, t_env *e, t_img img)
{
	t_fract		f;

	f.newre = 2 * (x - e->width / 2) / (0.4 * img.zoom * e->width) + img.movex;
	f.newim = (y - e->height / 2) / (0.4 * img.zoom * e->height) + img.movey;
	f.i = -1;
	while (++f.i < e->maxiterations)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = (cos(f.oldre * f.oldre - f.oldim * f.oldim)) + img.cre;
		f.newim = (2 * f.oldre * f.oldim) + img.cim;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	if (f.i != e->maxiterations)
		e->col == 1 ? color_ci(e, f) : color_cmi(e, f);
	else
		color_c(e);
	return (e->c);
}
