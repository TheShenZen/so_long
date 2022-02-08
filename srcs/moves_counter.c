/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:12:45 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/10 15:49:10 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(t_win *win)
{
	ft_putstr_fd("\rNumber of moves : ", 1);
	ft_putnbr_fd(win->nb_moves, 1);
}
