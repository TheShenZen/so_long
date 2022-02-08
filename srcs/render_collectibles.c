/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:11:00 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/11 18:31:45 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collectibles(char **map)
{
	int		i;
	int		j;
	int		cnt;

	j = 0;
	cnt = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				cnt++;
			i++;
		}
		j++;
	}
	return (cnt);
}

static void	set_collectible(t_collectible *clb, int i, int j)
{
	clb->x = i;
	clb->y = j;
	clb->picked = 0;
	if (BONUS)
		clb->index = rdm(12, 15);
	else
		clb->index = 12;
}

void	get_collectibles(t_win *win)
{
	int		i;
	int		j;
	int		k;

	win->nb_collectibles = count_collectibles(win->map->map);
	win->collectibles = malloc(sizeof(t_collectible) * \
		(win->nb_collectibles + 1));
	if (win->collectibles == NULL)
		error(MEMALLOC_ERR);
	j = -1;
	k = 0;
	while (win->map->map[++j] != NULL)
	{
		i = -1;
		while (win->map->map[j][++i])
		{
			if (win->map->map[j][i] == 'C')
			{
				set_collectible(&(win->collectibles[k]), i, j);
				k++;
			}
		}
	}
	win->collectibles[k].index = 9000;
}

int	render_collectibles(t_win *win)
{
	int				i;
	static char		time;

	i = 0;
	time += 1;
	while (win->collectibles[i].index < 9000)
	{
		if (win->collectibles[i].picked == 0)
		{
			draw_sprite(win, win->collectibles[i].x * SPT_SIZE,
				win->collectibles[i].y * SPT_SIZE,
				win->collectibles[i].index);
			if (time % ANIM_SPEED == 0 && BONUS)
			{
				win->collectibles[i].index = \
				((win->collectibles[i].index + 1) % 15);
				if (win->collectibles[i].index < 12)
					win->collectibles[i].index += 12;
			}
		}
		i++;
	}
	return (0);
}
