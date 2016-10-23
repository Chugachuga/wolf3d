/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:10:27 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/23 17:00:36 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <time.h>

int		ft_core(t_z *z)
{
	mlx_destroy_image(z->mlx, z->img);
	ft_init_var(z);
	ft_do(z);
	return (1);
}

int		ft_exitcross(t_z *z)
{
	free(z);
	exit(0);
}

void	ft_frametime(t_z *z)
{
	z->oldtime = z->time;
	z->time = clock();
	z->ftime = (z->time - z->oldtime) / 1000;
	z->rs = 0.1;
}
