/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:27:00 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/19 15:48:27 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

# define WIN_X 1200
# define WIN_Y 700

typedef struct	s_z
{
	int			lineheight;
	int			h;
	int			drawstart;
	int			drawend;
	int			mapwidth;
	int			mapheight;
	int			mapx;
	int			mapy;
	int			x;
	int			y;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		sidedistx;
	double		sidedisty;
	double		posx;
	double		posy;
	double		tmpdirx;
	double		tmpplanex;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		w;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		time;
	double		oldtime;
	double		ftime;
	double		ms;
	double		rs;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			s_line;
	int			ed;
	int			color;
	int			fd;
	int			ret;
	int			**new1;
	int			i;
	char		**tab;
	char		*line;
}				t_z;

int				ft_exitcross(t_z *z);
void			ft_frametime(t_z *z);
int				ft_core(t_z *z);
int				ft_keyhook(int keycode, t_z *z);
void			ft_init_var(t_z *z);
void			ft_draw(t_z *z);
void			ft_exit(t_z *z);
void			ft_wall(t_z *z);
int				ft_do(t_z *z);
int				ft_putintab(t_z *z);
void			put_pixel_to_image(t_z *z, int x, int y, int color);
void			ft_height(t_z *z);
void			ft_dda(t_z *z);
void			ft_step(t_z *z);
void			ft_init(t_z *z);
#endif
