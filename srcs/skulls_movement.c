/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skulls_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:07:33 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/27 14:57:46 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	skull_overlap(int k, t_win *win, int vx, int vy)
{
	int		i;

	i = 0;
	while (i < win->nb_skulls)
	{
		if (i != k && win->skulls[k].x + vx == win->skulls[i].x && 
			win->skulls[k].y+ vy == win->skulls[i].y)
			return (1);
		i++;
	}
	return (0);
}

static int	try_move(int k, t_win *win, int vx, int vy)
{
	if (win->map->map[win->skulls[k].y + vy][win->skulls[k].x + vx] != '1' && 
		!skull_overlap(k, win, vx, vy))
		return (absol((win->skulls[k].x + vx) - win->player->x) +\
			 absol((win->skulls[k].y + vy) - win->player->y));
	return (9999);
}

int	*distances(int k, t_win *win)
{
	int		*rt;

	rt = malloc(sizeof(int) * 4);
	if (rt == NULL)
		return (NULL);
	rt[0] = try_move(k, win, 0, -1);
	rt[1] = try_move(k, win, 0, 1);
	rt[2] = try_move(k, win, -1, 0);
	rt[3] = try_move(k, win, 1, 0);
	return (rt);
}

int	get_smallest_dist(int *distances)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (distances[i] >=0 && distances[i] <= distances[(i + 1) % 4] && 
			distances[i] <= distances[(i + 2) % 4] && 
			distances[i] <= distances[(i + 3) % 4])
		{
			free(distances);
			return (i);
		}
		i++;
	}
	free(distances);
	return (-1);
}

void	move_skull(int k, t_win *win)
{
	int		rt;

	rt = get_smallest_dist(distances(k, win));
	if (rt == 0)
		win->skulls[k].y += -1;
	else if (rt == 1)
		win->skulls[k].y += 1;
	else if (rt == 2)
		win->skulls[k].x += -1;
	else if (rt == 3)
		win->skulls[k].x += 1;
}

int	is_in_aggro_range(int k, t_win *win)
{
	int		*rt;
	int		i;

	rt = distances(k, win);
	i = 0;
	while (i < 4)
	{
		if (rt[i] <= AGGRO_RANGE)
		{
			free(rt);
			return (1);
		}
		i++;
	}
	free(rt);
	return (0);
}