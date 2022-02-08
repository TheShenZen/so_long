/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:12:45 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 15:49:07 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_move_counter(t_win *win)
{
	char			*str_moves;
	char			*tmp;

	str_moves = NULL;
	tmp = NULL;
	tmp = ft_itoa(win->nb_moves);
	if (tmp == NULL)
		error(MEMALLOC_ERR);
	str_moves = ft_strjoin("Number of moves : ", tmp);
	if (str_moves == NULL)
	{
		free(tmp);
		error(MEMALLOC_ERR);
	}
	free(tmp);
	mlx_string_put(win->mlx_ptr, win->mlx_win, SPT_SIZE, SPT_SIZE,
		trgb(255, 255, 255, 255), str_moves);
	free(str_moves);
}
