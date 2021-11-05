/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:42:39 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/23 19:07:22 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_win *win)
{
	int		i;
	int		j;

	j = 0;
	while (win->map->map[j])
	{
		i = 0;
		while (win->map->map[j][i])
		{
			if (win->map->map[j][i] == 'P')
			{
				win->player->x = i;
				win->player->y = j;
				win->player->index = 16;
				win->player->coins = 0;
			}
			i++;
		}
		j++;
	}
}

void	render_player(t_win *win)
{
	static char		time;

	time += 1;
	if (win->key->pressed && win->key->delay == 0)
	{
		move_player(win->key->key, win);
		win->key->delay = PLAYER_SPEED;
	}
	if (win->key->pressed)
		win->key->delay--;
	draw_sprite(win, win->player->x * SPT_SIZE, win->player->y * SPT_SIZE, win->player->index);
	if (time % ANIM_SPEED == 0)
	{
		win->player->index = ((win->player->index + 1) % 19);
		if (win->player->index < 16)
			win->player->index += 16;
	}
}