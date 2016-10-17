/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:59:39 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/17 15:43:14 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

void		ft_tabatoi(t_z *z)
{
	int		j;
	int		a;

	j = 0;
	a = 0;
	while (z->tab[a])
	{
		z->new1[z->i][j] = ft_atoi(z->tab[a]);
		a++;
		j++;
	}
	z->new1[z->i][j] = '\0';
}

void		ft_inittab(t_z *z)
{
	int		a;

	a = 0;
	z->new1 = (int**)malloc(sizeof(int*) * 25);
	if (!z->new1)
		return ;
	while (a < 24)
	{
		z->new1[a] = (int*)malloc(sizeof(int) * 25);
		if (!z->new1[a])
			return ;
		a++;
	}
}

int			ft_putintab(t_z *z)
{
	z->posx = 17;
	z->posy = 17;
	z->dirx = -1;
	z->diry = 0;
	z->planex = 0;
	z->planey = 0.66;
	z->time = 0;
	z->oldtime = 0;
	z->i = 0;
	if ((z->fd = open("./srcs/map", O_RDONLY)))
	{
		ft_inittab(z);
		while ((get_next_line(z->fd, &z->line)) == 1)
		{
			z->tab = ft_strsplit(z->line, ',');
			ft_tabatoi(z);
			free(z->line);
			free(z->tab);
			z->i++;
		}
		if (z->ret == -1)
			return (0);
	}
	return (1);
}
