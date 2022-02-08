/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:04 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 16:03:07 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	absol(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	is_movement_key(int key)
{
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		return (1);
	return (0);
}

void	bonus(t_win *win)
{
	int		i;

	i = 0;
	render_skulls(win);
	i = 0;
	while (i < win->nb_skulls)
	{
		if (win->skulls[i].x == win->player->x
			&& win->skulls[i].y == win->player->y)
			exit(EXIT_SUCCESS);
		i++;
	}
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

int	render_all(t_win *win)
{
	int			i;

	i = 0;
	render_map(win);
	render_collectibles(win);
	render_exit(win);
	render_player(win);
	if (BONUS)
		bonus(win);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->frame->img, 0, 0);
	if (BONUS)
		render_move_counter(win);
	while (i < win->nb_exits)
	{
		if (win->exit[i].x == win->player->x && win->exit[i].y == win->player->y
			&& win->nb_collectibles == 0)
		{
			free_win(win);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (0);
}
