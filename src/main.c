/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:07:05 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 16:43:45 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		case_fract(char **av, t_env e)
{
	if (av[1][0] == 'j')
		environ_one(e, 1);
	else if (av[1][0] == 'm')
		environ_one(e, 2);
	else if (av[1][0] == 'p')
		environ_one(e, 3);
	else if (av[1][0] == 't')
		environ_one(e, 4);
	else if (av[1][0] == 'l')
		environ_one(e, 5);
	else
	{
		ft_putstr_fd(av[1], 2);
		print_error(3);
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac >= 2)
	{
		if (ft_atoi(av[1]) == 2)
		{
			e.fract = 1;
			ft_envir(e);
		}
		else if (ac > 1 && av[1][0])
			case_fract(av, e);
	}
	else
		print_error(4);
	return (0);
}
