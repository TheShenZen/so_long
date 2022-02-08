/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:04 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/12 16:28:37 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_gnl_null(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		map[i] = NULL;
		i++;
	}
}

static void	get_map_size(int fd, t_win *win)
{
	int			rt;
	char		*line;

	rt = 1;
	while (rt > 0)
	{
		rt = get_next_line(fd, &line);
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			error(PARSE_ERR);
		if (rt < 0)
			error(MEMALLOC_ERR);
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
		error(MEMALLOC_ERR);
	set_gnl_null(win->map->map, win->map->map_size[1] + 1);
	while (rt > 0)
	{
		rt = get_next_line(fd, &line);
		if (rt < 0 || (int)ft_strlen(line) != win->map->map_size[0])
			error(PARSE_ERR);
		win->map->map[i] = line;
		++i;
	}
	win->map->map_size[0] = ft_strlen(win->map->map[0]);
	win->map->map[i] = NULL;
}

void	get_map_info(char *file, t_win *win)
{
	win->fd = open(file, O_RDONLY | __O_NOFOLLOW);
	if (win->fd < 0)
		error(OPEN_ERR);
	get_map_size(win->fd, win);
	close(win->fd);
	win->fd = open(file, O_RDONLY | __O_NOFOLLOW);
	if (win->fd < 0)
		error(OPEN_ERR);
	get_map(win->fd, win);
	check_if_closed(win);
	check_map_content(win->map->map);
	check_requir(win);
}
