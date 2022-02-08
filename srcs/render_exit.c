/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:02:17 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 15:58:14 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_nbr_of_doors(t_win *win)
{
	int		i;
	int		j;

	j = 0;
	while (win->map->map[j])
	{
		i = 0;
		while (win->map->map[j][i])
		{
			if (win->map->map[j][i] == 'E')
				win->nb_exits++;
			i++;
		}
		j++;
	}
	win->exit = malloc(sizeof(t_exit) * win->nb_exits);
	if (win->exit == NULL)
		error(MEMALLOC_ERR);
}

void	get_door(t_win *win)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	get_nbr_of_doors(win);
	while (win->map->map[j])
	{
		i = 0;
		while (win->map->map[j][i])
		{
			if (win->map->map[j][i] == 'E')
			{
				win->exit[k].x = i;
				win->exit[k].y = j;
				win->exit[k].open = 20;
				k++;
			}
			i++;
		}
		j++;
	}
}

void	render_exit(t_win *win)
{
	int		i;

	i = 0;
	if (win->nb_collectibles == 0)
	{
		while (i < win->nb_exits)
		{
			win->exit[i].open = 21;
			i++;
		}
	}
	i = 0;
	while (i < win->nb_exits)
	{
		draw_sprite(win, win->exit[i].x * SPT_SIZE,
			win->exit[i].y * SPT_SIZE, win->exit[i].open);
		i++;
	}
}
