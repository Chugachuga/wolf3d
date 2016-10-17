/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:11:24 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/17 15:27:58 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/mlx.h"

int		main(void)
{
	t_z *z;

	if (!(z = (t_z*)malloc(sizeof(t_z))))
		return (0);
	if (ft_putintab(z))
	{
		z->mlx = mlx_init();
		z->win = mlx_new_window(z->mlx, WIN_X, WIN_Y, "Wolf3d");
		z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
		ft_init_var(z);
		ft_do(z);
		mlx_hook(z->win, 2, 1, ft_keyhook, z);
		mlx_loop_hook(z->mlx, ft_core, z);
		mlx_loop(z->mlx);
	}
	return (0);
}
