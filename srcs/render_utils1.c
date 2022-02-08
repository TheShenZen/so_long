/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:15:35 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 15:59:34 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->frame->addr + (y * win->frame->ll + x * (win->frame->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_sprite *sprite, int x, int y)
{
	char	*pixel;

	pixel = sprite->addr + (y * sprite->ll + x * (sprite->bpp / 8));
	return (*(int *)pixel);
}

t_sprite	*import_sprite(t_win *win, char	*path)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (sprite == NULL)
		error(MEMALLOC_ERR);
	sprite->img = mlx_xpm_file_to_image(win->mlx_ptr, path,
			&sprite->iw, &sprite->ih);
	if (sprite->img == NULL)
		error(MEMALLOC_ERR);
	if (sprite->iw != 16 || sprite->ih != 16)
		error(SPRITE_ERR);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp, &sprite->ll,
			&sprite->endian);
	if (sprite->addr == NULL)
		error(MEMALLOC_ERR);
	return (sprite);
}

int	rdm(int min, int max)
{
	static char				buff[252];
	static unsigned char	index;
	static int				opened;
	int						nbr;
	int						fd;

	if (opened == 0)
	{
		fd = open("/dev/random", O_RDONLY);
		if (fd < 0)
			return (-1);
		read(fd, buff, 252);
		close(fd);
		opened = 1;
	}
	nbr = *(int *)&buff[index];
	index += 4;
	if (index == 252)
		index = 0;
	if (nbr < 0)
		nbr *= -1;
	return (min + nbr % (max + 1 - min));
}
