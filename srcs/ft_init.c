/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:32:38 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/23 17:00:06 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_step(t_z *z)
{
	if (z->raydirx < 0)
	{
		z->stepx = -1;
		z->sidedistx = (z->rayposx - z->mapx) * z->deltadistx;
	}
	else
	{
		z->stepx = 1;
		z->sidedistx = (z->mapx + 1 - z->rayposx) * z->deltadistx;
	}
	if (z->raydiry < 0)
	{
		z->stepy = -1;
		z->sidedisty = (z->rayposy - z->mapy) * z->deltadisty;
	}
	else
	{
		z->stepy = 1;
		z->sidedisty = (z->mapy + 1 - z->rayposy) * z->deltadisty;
	}
}

void	ft_dda(t_z *z)
{
	while (z->hit == 0)
	{
		if (z->sidedistx < z->sidedisty)
		{
			z->sidedistx += z->deltadistx;
			z->mapx += z->stepx;
			z->side = 0;
		}
		else
		{
			z->sidedisty += z->deltadisty;
			z->mapy += z->stepy;
			z->side = 1;
		}
		if (z->new1[z->mapx][z->mapy] > 0)
			z->hit = 1;
	}
}

void	ft_wall(t_z *z)
{
	if (z->side == 0)
		z->perpwalldist = (z->mapx - z->rayposx
					+ (1 - z->stepx) / 2) / z->raydirx;
	else
		z->perpwalldist = (z->mapy - z->rayposy
					+ (1 - z->stepy) / 2) / z->raydiry;
}

void	ft_height(t_z *z)
{
	z->h = z->WIN_Y;
	z->lineheight = (int)(z->h / z->perpwalldist);
	z->drawstart = -z->lineheight / 2 + z->h / 2;
	if (z->drawstart < 0)
		z->drawstart = 0;
	z->drawend = z->lineheight / 2 + z->h / 2;
	if (z->drawend >= z->h)
		z->drawend = z->h - 1;
}

void	ft_init(t_z *z)
{
	z->x = 0;
	while (z->x < z->w)
	{
		z->camerax = 2 * z->x / z->w - 1;
		z->rayposx = z->posx;
		z->rayposy = z->posy;
		z->raydirx = z->dirx + z->planex * z->camerax;
		z->raydiry = z->diry + z->planey * z->camerax;
		z->mapx = (int)z->rayposx;
		z->mapy = (int)z->rayposy;
		z->deltadistx = sqrt(1 + (z->raydiry * z->raydiry) /
				(z->raydirx * z->raydirx));
		z->deltadisty = sqrt(1 + (z->raydirx * z->raydirx) /
				(z->raydiry * z->raydiry));
		z->hit = 0;
		ft_step(z);
		ft_dda(z);
		ft_wall(z);
		ft_height(z);
		ft_draw(z);
		ft_frametime(z);
		z->x++;
	}
}
