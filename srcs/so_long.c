/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:33:36 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/27 14:12:34 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win		*win;

	win = NULL;
	if (ac != 2)
		error(win, ARGNB_ERR);
	win = init_win(av);
	gen_randomsprites(win->map);
	get_collectibles(win);
	get_player_pos(win);
	get_door(win);
	get_skulls_pos(win);
	event_manager(win);
	mlx_loop(win->mlx_ptr);
}