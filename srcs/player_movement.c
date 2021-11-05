/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:06:37 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/29 01:46:40 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pick_collectible(t_win *win)
{
	int		x;
	int		y;
	int		i;

	x = win->player->x;
	y = win->player->y;
	i = 0;
	if (win->map->map[y][x] == 'C')
		while (win->collectibles[i].index < 9000)
		{
			if (win->collectibles[i].x == x && win->collectibles[i].y == y && 
				win->collectibles[i].picked == 0)
			{
				win->collectibles[i].picked = 1;
				win->nb_collectibles -= 1;
			}
			i++;
		}
}

void	move_player(int key, t_win *win)
{
	int		x;
	int		y;

	x = win->player->x;
	y = win->player->y;
	if (key == K_W && win->map->map[y - 1][x] != '1')
	{
		win->player->y--;
		win->nb_moves++;
	}
	else if (key == K_A && win->map->map[y][x - 1] != '1')
	{
		win->player->x--;
		win->nb_moves++;
	}
	else if (key == K_S && win->map->map[y + 1][x] != '1')
	{
		win->player->y++;
		win->nb_moves++;
	}
	else if(key == K_D && win->map->map[y][x + 1] != '1')
	{
		win->player->x++;
		win->nb_moves++;
	}
	pick_collectible(win);
}