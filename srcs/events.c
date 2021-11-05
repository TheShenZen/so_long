/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:27:57 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/22 16:26:08 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int quit_app(int key, t_win *win)
{
	(void)key;
	(void)win;
	exit(EXIT_SUCCESS);
}

static int	key_press(int key, t_win *win)
{
		printf("++%d\n", key);
	if (is_movement_key(key) && key != ESC && win->key->pressed == 0)
	{
		win->key->key = key;
		win->key->pressed = 1;
	}
	else if (key == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

static int	key_release(int key, t_win *win)
{
		printf("--%d\n", key);
	if (is_movement_key(key) && key != ESC && win->key->pressed == 1)
	{
		win->key->pressed = 0;
		win->key->delay = 0;
	}
	return (0);
}

void	event_manager(t_win *win)
{
	mlx_hook(win->mlx_win, 3, 1L<<1, key_release, win);
	mlx_hook(win->mlx_win, 2, 1L<<0, key_press, win);
	mlx_hook(win->mlx_win, 17, 1L<<0, quit_app, win);
	mlx_loop_hook(win->mlx_ptr, render_all, win);
}
