/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:06:59 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/12 15:58:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_win *win)
{
	int		i;

	if (win->map == NULL || win->map->map == NULL)
		return ;
	i = -1;
	while (win->map->map[++i])
	{
		free(win->map->map[i]);
		win->map->map[i] = NULL;
	}
	free(win->map->map);
	win->map->map = NULL;
	if (win->map->sprites_map == NULL)
		return ;
	i = -1;
	while (++i < win->map->map_size[1])
	{
		free(win->map->sprites_map[i]);
		win->map->map = NULL;
	}
	free(win->map->sprites_map);
	win->map->sprites_map = NULL;
	free(win->map);
	win->map = NULL;
}

static void	free_frame(t_win *win)
{
	if (win->frame == NULL)
		return ;
	mlx_destroy_image(win->mlx_ptr, win->frame->img);
	win->frame->img = NULL;
	free(win->frame);
	win->frame = NULL;
}

static void	free_sprite(t_win *win)
{
	int		i;

	if (win->collectibles == NULL)
		return ;
	i = 0;
	while (win->sprites[i])
	{
		mlx_destroy_image(win->mlx_ptr, win->sprites[i]->img);
		free(win->sprites[i]);
		win->sprites[i] = NULL;
		i++;
	}
	free(win->sprites);
}

void	free_win(t_win *win)
{
	free(win->key);
	free_map(win);
	free_frame(win);
	free_sprite(win);
	free(win->collectibles);
	free(win->player);
	free(win->exit);
	free(win->skulls);
	if (win->fd > 0)
		close(win->fd);
	mlx_destroy_window(win->mlx_ptr, win->mlx_win);
	win->mlx_win = NULL;
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	win->mlx_ptr = NULL;
	free(win);
	win = NULL;
}
