/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:04 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/01 15:55:14 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_size(int fd, t_win *win)
{
	int			rt;
	char		*line;

	rt = 1;
	while (rt > 0)
	{
		rt = get_next_line(fd, &line);
		if (rt < 0)
			error(win, MEMALLOC_ERR) ;
		win->map->map_size[0] = ft_strlen(line);
		win->map->map_size[1]++;
		free(line);
		line = NULL;
	}
}

static void	get_map(int fd, t_win *win)
{
	int			rt;
	int			i;
	char		*line;

	rt = 1;
	i = 0;
	win->map->map = malloc(sizeof(char *) * (win->map->map_size[1] + 1));
	if (win->map->map == NULL)
		error(win, MEMALLOC_ERR);
	while (rt > 0)
	{
		rt = get_next_line(fd, &line);
		if (rt < 0 || (int)ft_strlen(line) != win->map->map_size[0])
			error(win, PARSE_ERR);
		win->map->map[i] = line;
		++i;
	}
	win->map->map_size[0] = ft_strlen(win->map->map[0]);
	win->map->map[i] = NULL;
}

static void	check_if_closed(t_win *win)
{
	int		i;
	
	i = -1;
	while (win->map->map[0][++i])
		if (win->map->map[0][i] != '1')
			error(win, PARSE_ERR);
	i = -1;
	while (win->map->map[win->map->map_size[1] - 1][++i])
		if (win->map->map[win->map->map_size[1] - 1][i] != '1')
			error(win, PARSE_ERR);
	i = -1;
	while (win->map->map[++i])
		if (win->map->map[i][0] != '1' ||
			win->map->map[i][win->map->map_size[0] - 1] != '1')
			error(win, PARSE_ERR);
}

static int	count_requir(char c, int check)
{
	static int flags[4];

	if (c == 'P')
		flags[0]++;
	else if (c == 'C')
		flags[1]++;
	else if (c == 'E')
		flags[2]++;
	else if (c == 'S')
		flags[3]++;
	if (check == 1)
		if (flags[0] != 1 || flags[1] == 0 || flags[2] == 0 ||
			flags[3] == 0)
			return (1);
	return (0);
}

static void	check_requir(t_win *win)
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
		error(win, PARSE_ERR);
}

void	get_map_info(char *file, t_win *win)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(win, OPEN_ERR);
	get_map_size(fd, win);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(win, OPEN_ERR);
	get_map(fd, win);
	check_if_closed(win);
	check_requir(win);
}