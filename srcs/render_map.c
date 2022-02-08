/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:13:52 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 15:58:34 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gen_randomsprites(t_map *map)
{
	int		i;
	int		j;

	map->sprites_map = malloc(sizeof(int *) * map->map_size[1]);
	if (map->sprites_map == NULL)
		error(MEMALLOC_ERR);
	i = 0;
	while (i < map->map_size[1])
	{
		j = 0;
		map->sprites_map[i] = malloc(sizeof(int) * map->map_size[0]);
		if (map->sprites_map[i] == NULL)
			error(MEMALLOC_ERR);
		while (j < map->map_size[0])
		{
			map->sprites_map[i][j] = get_range(map->map, i, j);
			j++;
		}
		i++;
	}
}

int	render_map(t_win *win)
{
	int		i;
	int		j;

	i = 0;
	while (i < win->map->map_size[1])
	{
		j = 0;
		while (j < win->map->map_size[0])
		{
			draw_sprite(win, j * SPT_SIZE, i * SPT_SIZE,
				win->map->sprites_map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
