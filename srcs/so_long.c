/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:33:36 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/12 16:18:40 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	*get_win(void)
{
	static t_win	*win;

	win = malloc(sizeof(t_win));
	if (win == NULL)
		error(MEMALLOC_ERR);
	return (win);
}

int	check_map_extension(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i < 5)
		return (0);
	if (ft_strncmp(&str[i - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_win		*win;

	win = NULL;
	if (ac != 2)
		error(ARGNB_ERR);
	else if (check_map_extension(av[1]) == 0)
		error(EXTENSION_ERR);
	win = init_win(av);
	mlx_do_key_autorepeatoff(win->mlx_ptr);
	gen_randomsprites(win->map);
	get_collectibles(win);
	get_player_pos(win);
	get_door(win);
	get_skulls_pos(win);
	event_manager(win);
	mlx_loop(win->mlx_ptr);
}
