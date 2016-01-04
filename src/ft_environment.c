/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 18:03:59 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 16:49:47 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		ft_envir_bis(t_env e)
{
	draw_lite(&e);
	mlx_expose_hook (e.img1.win, expose_hook, &e);
	mlx_expose_hook (e.img2.win, expose_hook, &e);
	mlx_hook(e.img1.win, 2, 3, key_hook, &e);
	mlx_hook(e.img2.win, 2, 3, key_hook, &e);
	mlx_hook(e.img1.win, MotionNotify, PointerMotionMask, mouse_hook, &e);
	mlx_hook(e.img2.win, MotionNotify, PointerMotionMask, mouse_hook, &e);
	mlx_mouse_hook(e.img1.win, mouse2_key, &e);
	mlx_mouse_hook(e.img2.win, mouse2_key, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
}

void		ft_envir(t_env e)
{
	e.width = 512;
	e.height = 512;
	if (!(e.mlx = mlx_init()))
		print_error(1);
	e.img1.img = mlx_new_image(e.mlx, e.width, e.height);
	e.img1.data =
		mlx_get_data_addr
		(e.img1.img, &e.img1.bpp, &e.img1.sizeline, &e.img1.endian);
	e.img2.img = mlx_new_image(e.mlx, e.width, e.height);
	e.img2.data =
		mlx_get_data_addr
		(e.img2.img, &e.img2.bpp, &e.img2.sizeline, &e.img2.endian);
	e.img2.win =
		mlx_new_window(e.mlx, e.width, e.height, "< 2->fractal > Project");
	e.img1.win =
		mlx_new_window(e.mlx, e.width, e.height, "< 1->fractal > Project");
	init(&e);
	ft_envir_bis(e);
}

void		environ_one(t_env e, int i)
{
	e.img2.data = (NULL);
	e.width = 1024;
	e.height = 720;
	e.fract = i;
	if (!(e.mlx = mlx_init()))
		print_error(1);
	e.img1.img = mlx_new_image(e.mlx, e.width, e.height);
	e.img1.data =
		mlx_get_data_addr
		(e.img1.img, &e.img1.bpp, &e.img1.sizeline, &e.img1.endian);
	e.img1.win =
		mlx_new_window(e.mlx, e.width, e.height, "< fractal > Project");
	init(&e);
	draw_lite(&e);
	mlx_expose_hook(e.img1.win, expose_hook, &e);
	mlx_hook(e.img1.win, 2, 3, key_hook, &e);
	mlx_hook(e.img1.win, MotionNotify, PointerMotionMask, mouse_hook, &e);
	mlx_mouse_hook(e.img1.win, mouse2_key, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
}
