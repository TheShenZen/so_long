/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:15:28 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/12 15:52:23 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "keys.h"
# include "error_msg.h"

# ifndef BONUS
#  define BONUS 0
# endif
# define TITLE "so_long"
# define SPT_SIZE 16
# define PLAYER_SPEED 10
# define SKULLS_SPEED 15
# define AGGRO_RANGE 20
# define ANIM_SPEED 8

typedef struct s_frame
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_frame;

typedef struct s_map
{
	char		**map;
	int			**sprites_map;
	int			map_size[2];
}				t_map;

typedef struct s_sprite
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
	int			iw;
	int			ih;
}				t_sprite;

typedef struct s_collectible
{
	int			x;
	int			y;
	int			index;
	int			picked;
}				t_collectible;

typedef struct s_player
{
	int			x;
	int			y;
	int			index;
	int			coins;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
	int			open;
}				t_exit;

typedef struct s_key
{
	int			key;
	int			pressed;
	char		delay;
}				t_key;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				nb_moves;
	int				nb_collectibles;
	int				nb_exits;
	int				nb_skulls;
	int				fd;
	t_key			*key;
	t_map			*map;
	t_frame			*frame;
	t_sprite		**sprites;
	t_collectible	*collectibles;
	t_player		*player;
	t_exit			*exit;
	t_player		*skulls;
}				t_win;

t_win		*get_win(void);
void		set_win_to_zero(t_win *win);
void		move_counter(t_win *win);
void		render_move_counter(t_win *win);
void		event_manager(t_win *win);
void		init_player(t_win *win);
void		init_exit(t_win *win);
void		init_key(t_win *win);
t_win		*init_win(char **av);
void		get_map_info(char *file, t_win *win);
void		check_if_closed(t_win *win);
int			count_requir(char c, int check);
void		check_requir(t_win *win);
int			trgb(int t, int r, int g, int b);
void		draw_pixel(t_win *win, int x, int y, int color);
void		draw_sprite(t_win *win, int x, int y, int spt);
t_sprite	*import_sprite(t_win *win, char *path);
int			render_map(t_win *win);
int			get_pixel(t_sprite *sprite, int x, int y);
int			rdm(int min, int max);
int			get_range(char **map, int x, int y);
char		**get_sprites(void);
void		init_sprites(t_win *win);
void		gen_randomsprites(t_map *map);
void		get_collectibles(t_win *win);
int			render_collectibles(t_win *win);
int			render_all(t_win *win);
void		get_player_pos(t_win *win);
void		render_player(t_win *win);
int			is_movement_key(int key);
void		move_player(int key, t_win *win);
void		pick_collectible(t_win *win);
void		get_door(t_win *win);
void		render_exit(t_win *win);
void		get_nb_skulls(t_win *win);
void		get_skulls_pos(t_win *win);
void		render_skulls(t_win *win);
int			absol(int n);
int			*distances(int k, t_win *win);
int			get_smallest_dist(int *distances);
void		move_skull(int k, t_win *win);
int			is_in_aggro_range(int k, t_win *win);
void		error(char *msg);
void		free_win(t_win *win);
void		bonus(t_win *win);
void		check_map_content(char **map);

#endif