/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 13:18:48 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 18:13:39 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTAL_H
# define _FRACTAL_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <X11/xlib.h>
# include <X11/cursorfont.h>

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_fract
{
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	int			i;
	double		pi;
	double		pr;
}				t_fract;

typedef struct	s_img
{
	void		*win;
	void		*img;
	char		*data;
	int			sizeline;
	int			bpp;
	int			endian;
	double		cre;
	double		cim;
	int			lastx;
	int			lasty;
	double		index;
	double		indexy;
	double		zoom;
	double		movex;
	double		movey;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	t_img		img1;
	t_img		img2;
	int			width;
	int			height;
	int			color;
	int			maxiterations;
	t_color		c;
	int			fract;
	int			changed;
	int			mouss;
	int			jul;
	int			col;
}				t_env;

t_color			julia(int x, int y, t_env *e, t_img img);
t_color			mandel(int x, int y, t_env *e, t_img img);
t_color			fract3(int x, int y, t_env *e, t_img img);
t_color			fract4(int x, int y, t_env *e, t_img img);
t_color			fract5(int x, int y, t_env *e, t_img img);

void			init(t_env *e);
void			init2(t_env *e);
void			print_error(int i);

int				mouse_hook(int x, int y, t_env *e);
int				mouse2_key(int key, int x, int y, t_env *e);

int				expose_hook(t_env *e);
int				loop_hook(t_env *e);

int				key_hook(int key, t_env *e);

void			put_pixel_to_img(t_env *e, int pos, t_color c, t_img img);
t_color			get_color(int r, int g, int b);

void			draw_lite(t_env *e);
void			color_ci(t_env *e, t_fract f);
void			color_cmi(t_env *e, t_fract f);
void			color_c(t_env *e);

void			environ_one(t_env e, int i);
void			ft_envir(t_env e);

#endif
