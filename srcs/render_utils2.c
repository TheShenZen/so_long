/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:40:16 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 15:59:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_range(char **map, int x, int y)
{
	if (map[x][y] == '1')
	{
		if (y == 0 && map[x + 1] != NULL)
			return (rdm(4, 5));
		else if (map[x][y + 1] == '\0' && map[x + 1] != NULL)
			return (rdm(2, 3));
		else if (y == 0)
			return (rdm(11, 11));
		else if (map[x][y + 1] == '\0')
			return (rdm(10, 10));
		else if (map[x + 1] == NULL)
			return (rdm(6, 7));
		else
			return (rdm(0, 1));
	}
	else
		return (rdm(8, 9));
}

void	draw_sprite(t_win *win, int x, int y, int spt)
{
	int		i;
	int		j;
	int		clr;

	j = 0;
	while (j < win->sprites[spt]->ih)
	{
		i = 0;
		while (i < win->sprites[spt]->iw)
		{
			clr = get_pixel(win->sprites[spt], i, j);
			draw_pixel(win, x + i, y + j, clr);
			i++;
		}
		j++;
	}
}
