/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:59:53 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 19:29:14 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define PLAYER 'P'
# define WALL_SPRITE "textures/WALL.xpm"
# define FLOOR_SPRITE "textures/FLOOR.xpm"
# define EXIT_SPRITE  "textures/EXIT.xpm"
# define PLAYER_SPRITE	"textures/PLAYER.xpm"
# define COLLECTIBLE_SPRITE	"textures/COLLECTIBLE.xpm"
# define MOVING_RIGHT_SPRITE "textures/MOVING_RIGHT.xpm"
# define MOVING_LEFT_SPRITE "textures/MOVING_LEFT.xpm"
# define MOVING_UP_SPRITE "textures/MOVING_UP.xpm"
# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_UP 65362
# define KEY_A 97
# define KEY_LEFT 65361
# define KEY_S 115
# define KEY_DOWN 65364
# define KEY_D 100
# define KEY_RIGHT 65363
# define MOVING_RIGHT 1
# define MOVING_LEFT 2
# define MOVING_UP 3
# define MOVING_DOWN 4

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		width;
	int		height;
	int		window_width;
	int		window_height;
	int		player_x;
	int		player_y;
	int		move_count;
	int		collectibles;
	int		total_collectibles;
	int		player_direction;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_player_moving_right;
	void	*img_player_moving_left;
	void	*img_player_moving_up;
	void	*img_collectible;
	void	*img_exit;
}	t_game;


void	free_game(t_game *game);
char	**check_map(char *map_file);
void	exit_error(t_game *game, char *str);
//render_map.c
void	render_map(t_game *game);
//check_map.c
char	**check_map(char *map_file);
//prepare_game.c
void	prepare_game(t_game *game);
//set_hooks.c
void	set_hooks(t_game *game);
int		expose_hook(t_game *game);
int		handle_keypress(int key, t_game *game);
int		close_window(t_game *game);
void	exit_game(t_game *game);
//set_map.c
char	**set_map(const char *map_file);
//images.c
void	load_images(t_game *game);
// move.c
void	move_player(t_game *game, int x, int y);
//flood_fill.c
void	flood_fill(t_game *game);
void	free_matrix(char **m);

#endif
