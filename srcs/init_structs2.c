/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:47:28 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/01 17:11:31 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_win *win)
{
	win->player = malloc(sizeof(t_player));
	if (win->player == NULL)
		error(win, MEMALLOC_ERR);
	win->player->coins = 0;
	win->player->index = 0;
	win->player->x = 0;
	win->player->y = 0;
}

void	init_exit(t_win *win)
{
	win->exit = malloc(sizeof(t_exit));
	if (win->exit == NULL)
		error(win, MEMALLOC_ERR);
	win->exit->open = 0;
	win->exit->x = 0;
	win->exit->y = 0;
}

void	init_key(t_win *win)
{
	win->key = malloc(sizeof(t_key));
	if (win->key == NULL)
		error(win, MEMALLOC_ERR);
	win->key->key = 0;
	win->key->pressed = 0;
	win->key->delay = 0;
}

void	set_win_to_zero(t_win *win)
{
	win->map = NULL;
	win->mlx_ptr = NULL;
	win->mlx_win = NULL;
	win->sprites = NULL;
	win->frame = NULL;
	win->player = NULL;
	win->exit = NULL;
	win->key = NULL;
	win->nb_collectibles = 0;
	win->nb_exits = 0;
	win->nb_moves = 0;
	win->nb_skulls = 0;
}