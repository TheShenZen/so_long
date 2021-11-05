/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ennemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:26:58 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/23 18:52:10 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_nb_skulls(t_win *win)
{
	int		i;
	int		j;

	j = 0;
	win->nb_skulls = 0;
	while (win->map->map[j])
	{
		i = 0;
		while (win->map->map[j][i])
		{
			if (win->map->map[j][i] == 'S')
				win->nb_skulls++;
			i++;
		}
		j++;
	}
	win->skulls = malloc(sizeof(t_player) * win->nb_skulls);
	if (win->skulls == NULL)
		return ;
}

void	get_skulls_pos(t_win *win)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	get_nb_skulls(win);
	while (win->map->map[j])
	{
		i = 0;
		while (win->map->map[j][i])
		{
			if (win->map->map[j][i] == 'S')
			{
				win->skulls[k].x = i;
				win->skulls[k].y = j;
				win->skulls[k].index = 22;
				win->skulls[k].coins = 0;
				k++;
			}
			i++;
		}
		j++;
	}
}

void	render_skulls(t_win *win)
{
	int				i;

	i = 0;
	while (i < win->nb_skulls)
	{
		win->skulls[i].coins += 1;
		draw_sprite(win, win->skulls[i].x * SPT_SIZE, win->skulls[i].y * SPT_SIZE, win->skulls[i].index);
		if (win->skulls[i].coins % ANIM_SPEED == 0)
		{
			win->skulls[i].index = ((win->skulls[i].index + 1) % 25);
			if (win->skulls[i].index < 22)
				win->skulls[i].index += 22;
		}
		if (win->skulls[i].coins % SKULLS_SPEED == 0 && is_in_aggro_range(i, win))
			move_skull(i, win);
		i++;
	}
}