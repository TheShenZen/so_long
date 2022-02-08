/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:27:03 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/12 14:14:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_closed(t_win *win)
{
	int		i;

	i = -1;
	while (win->map->map[0][++i])
		if (win->map->map[0][i] != '1')
			error(PARSE_ERR);
	i = -1;
	while (win->map->map[win->map->map_size[1] - 1][++i])
		if (win->map->map[win->map->map_size[1] - 1][i] != '1')
			error(PARSE_ERR);
	i = -1;
	while (win->map->map[++i])
		if (win->map->map[i][0] != '1' ||
			win->map->map[i][win->map->map_size[0] - 1] != '1')
			error(PARSE_ERR);
}

int	count_requir(char c, int check)
{
	static int	flags[3];

	if (c == 'P')
		flags[0]++;
	else if (c == 'C')
		flags[1]++;
	else if (c == 'E')
		flags[2]++;
	if (check == 1)
		if (flags[0] != 1 || flags[1] == 0 || flags[2] == 0)
			return (1);
	return (0);
}

void	check_requir(t_win *win)
{
	int				i;
	int				j;

	j = 0;
	while (win->map->map[j])
	{
		i = 0;
		while (win->map->map[j][i])
		{
			count_requir(win->map->map[j][i], 0);
			i++;
		}
		j++;
	}
	if (count_requir(0, 1))
		error(PARSE_ERR);
}

void	check_map_content(char **map)
{
	int		i;
	int		j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!BONUS)
			{
				if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'P'
					&& map[j][i] != 'C' && map[j][i] != 'E')
					error(PARSE_ERR);
			}
			else
			{
				if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'P'
					&& map[j][i] != 'C' && map[j][i] != 'E' && map[j][i] != 'S')
					error(PARSE_ERR);
			}
			i++;
		}
		j++;
	}
}
