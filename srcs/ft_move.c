/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:28:45 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/17 15:14:02 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_movefront(t_z *z)
{
	if (z->new1[(int)(z->posx + z->dirx)][(int)z->posy] == 0)
		z->posx += z->dirx;
	if (z->new1[(int)z->posx][(int)(z->posy + z->diry)] == 0)
		z->posy += z->diry;
}

void	ft_moveback(t_z *z)
{
	if (z->new1[(int)(z->posx - z->dirx)][(int)z->posy] == 0)
		z->posx -= z->dirx;
	if (z->new1[(int)z->posx][(int)(z->posy - z->diry)] == 0)
		z->posy -= z->diry;
}

void	ft_rotright(t_z *z)
{
	z->tmpdirx = z->dirx;
	z->dirx = z->dirx * cos(-z->rs) - z->diry * sin(-z->rs);
	z->diry = z->tmpdirx * sin(-z->rs) + z->diry * cos(-z->rs);
	z->tmpplanex = z->planex;
	z->planex = z->planex * cos(-z->rs) - z->planey * sin(-z->rs);
	z->planey = z->tmpplanex * sin(-z->rs) + z->planey * cos(-z->rs);
}

void	ft_rotleft(t_z *z)
{
	z->tmpdirx = z->dirx;
	z->dirx = z->dirx * cos(z->rs) - z->diry * sin(z->rs);
	z->diry = z->tmpdirx * sin(z->rs) + z->diry * cos(z->rs);
	z->tmpplanex = z->planex;
	z->planex = z->planex * cos(z->rs) - z->planey * sin(z->rs);
	z->planey = z->tmpplanex * sin(z->rs) + z->planey * cos(z->rs);
}

int		ft_keyhook(int keycode, t_z *z)
{
	ft_frametime(z);
	if (keycode == 53)
	{
		free(z);
		exit(0);
	}
	if (keycode == 126)
		ft_movefront(z);
	if (keycode == 125)
		ft_moveback(z);
	if (keycode == 124)
		ft_rotright(z);
	if (keycode == 123)
		ft_rotleft(z);
	return (1);
}
