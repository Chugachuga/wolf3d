/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:00:03 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/17 15:42:38 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	mlx_pixel_to_image(t_z *z, int x, int y, int color)
{
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;

	color1 = color >> 0;
	color2 = color >> 8;
	color3 = color >> 16;
	z->img_data[y * z->s_line + x * z->bpp / 8] = color1;
	z->img_data[y * z->s_line + x * z->bpp / 8 + 1] = color2;
	z->img_data[y * z->s_line + x * z->bpp / 8 + 2] = color3;
}

void	ft_draw_all(t_z *z)
{
	if (z->drawend < 0)
		z->drawend = z->h;
	z->y = z->drawend;
	while (z->y < z->h)
	{
		mlx_pixel_to_image(z, z->x, z->y, 0x25B700);
		mlx_pixel_to_image(z, z->x, z->h - z->y - 1, 0x101B0F0);
		z->y++;
	}
}

void	ft_draw(t_z *z)
{
	z->y = z->drawstart;
	while (z->y < z->drawend)
	{
		if (z->side == 1)
		{
			if (z->stepy > 0)
				mlx_pixel_to_image(z, z->x, z->y, 0xFFCC00);
			else
				mlx_pixel_to_image(z, z->x, z->y, 0x00FFFF);
		}
		else
		{
			if (z->stepx > 0)
				mlx_pixel_to_image(z, z->x, z->y, 0x990000);
			else
				mlx_pixel_to_image(z, z->x, z->y, 0x99FF33);
		}
		z->y++;
	}
	ft_draw_all(z);
}

int		ft_do(t_z *z)
{
	z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
	z->img_data = mlx_get_data_addr(z->img, &(z->bpp), &(z->s_line),
				&(z->ed));
	ft_init(z);
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
	return (1);
}
