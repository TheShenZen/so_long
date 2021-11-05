/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:53:46 by seciurte          #+#    #+#             */
/*   Updated: 2021/10/27 17:53:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	if (win->map == NULL)
		error(win, MEMALLOC_ERR);
	win->map->map = NULL;
	win->map->sprites_map = NULL;
	win->map->map_size[0] = 0;
	win->map->map_size[1] = 0;
}

static void	init_frame(t_win *win)
{
	win->frame = malloc(sizeof(t_frame));
	if (win->frame == NULL)
		error(win, MEMALLOC_ERR);
	win->frame->img = mlx_new_image(win->mlx_ptr,
			win->map->map_size[0] * SPT_SIZE,
			win->map->map_size[1] * SPT_SIZE);
	win->frame->addr = mlx_get_data_addr(win->frame->img, &win->frame->bpp,
			&win->frame->ll, &win->frame->endian);
}

static void	vive_la_norme(t_win *win)
{
	win->sprites[20] = import_sprite(win, "game_assets/door_closed.xpm");
	win->sprites[21] = import_sprite(win, "game_assets/door_open.xpm");
	win->sprites[22] = import_sprite(win, "game_assets/skull1.xpm");
	win->sprites[23] = import_sprite(win, "game_assets/skull2.xpm");
	win->sprites[24] = import_sprite(win, "game_assets/skull3.xpm");
	win->sprites[25] = import_sprite(win, "game_assets/skull4.xpm");
	win->sprites[26] = NULL;
}

void	init_sprites(t_win *win)
{
	win->sprites = malloc(sizeof(t_sprite *) * 27);
	if (win->sprites == NULL)
		error(win, MEMALLOC_ERR);
	win->sprites[0] = import_sprite(win, "game_assets/top_wall1.xpm");
	win->sprites[1] = import_sprite(win, "game_assets/top_wall2.xpm");
	win->sprites[2] = import_sprite(win, "game_assets/right_wall1.xpm");
	win->sprites[3] = import_sprite(win, "game_assets/right_wall2.xpm");
	win->sprites[4] = import_sprite(win, "game_assets/left_wall1.xpm");
	win->sprites[5] = import_sprite(win, "game_assets/left_wall2.xpm");
	win->sprites[6] = import_sprite(win, "game_assets/bot_wall1.xpm");
	win->sprites[7] = import_sprite(win, "game_assets/bot_wall2.xpm");
	win->sprites[8] = import_sprite(win, "game_assets/floor1.xpm");
	win->sprites[9] = import_sprite(win, "game_assets/floor2.xpm");
	win->sprites[10] = import_sprite(win, "game_assets/bot_right_corner.xpm");
	win->sprites[11] = import_sprite(win, "game_assets/bot_left_corner.xpm");
	win->sprites[12] = import_sprite(win, "game_assets/coin1.xpm");
	win->sprites[13] = import_sprite(win, "game_assets/coin2.xpm");
	win->sprites[14] = import_sprite(win, "game_assets/coin3.xpm");
	win->sprites[15] = import_sprite(win, "game_assets/coin4.xpm");
	win->sprites[16] = import_sprite(win, "game_assets/priest1.xpm");
	win->sprites[17] = import_sprite(win, "game_assets/priest2.xpm");
	win->sprites[18] = import_sprite(win, "game_assets/priest3.xpm");
	win->sprites[19] = import_sprite(win, "game_assets/priest4.xpm");
	vive_la_norme(win);
}

t_win	*init_win(char **av)
{
	t_win		*win;

	win = malloc(sizeof(t_win));
	if (win == NULL)
		error(win, MEMALLOC_ERR);
	set_win_to_zero(win);
	init_map(win);
	get_map_info(av[1], win);
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		error(win, MEMALLOC_ERR);
	win->mlx_win = mlx_new_window(win->mlx_ptr,
			win->map->map_size[0] * SPT_SIZE,
			win->map->map_size[1] * SPT_SIZE, "so_long");
	if (win->mlx_win == NULL)
		error(win, MEMALLOC_ERR);
	init_sprites(win);
	init_frame(win);
	init_player(win);
	init_exit(win);
	init_key(win);
	return (win);
}
