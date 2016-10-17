/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:24:27 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/17 15:23:58 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_pixel_to_image(int x, int y, int color, t_z *z)
{
	*(int*)(z->img_data + ((int)((z->bpp / 8) *
			(x)) + z->s_line * (y))) = color;
}

void	ft_init_var(t_z *z)
{
	z->x = 0;
	z->w = WIN_X;
	z->mapwidth = 24;
	z->mapheight = 24;
}
