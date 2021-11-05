/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:12:45 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/26 15:15:40 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	del_char(int n)
{
	while (n > 0)
	{
		ft_putchar_fd('\b', 1);
		--n;
	}
}

static int	nbrlen(int n)
{
	int		i;

	i = 1;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	move_counter(t_win *win)
{
	del_char(nbrlen(win->nb_moves));
	printf("Number of moves : %d", win->nb_moves);
}

void	render_move_counter(t_win *win)
{
	char			*str_moves;
	char			*tmp;

	tmp =  ft_itoa(win->nb_moves);
	str_moves =  ft_strjoin("Number of moves : ", tmp);
	free(tmp);
	mlx_string_put(win->mlx_ptr, win->mlx_win, SPT_SIZE, SPT_SIZE, 
	trgb(255, 255, 255, 255), str_moves);
	free(str_moves);
}
