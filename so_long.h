/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:59:53 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/21 13:51:41 by gamorcil         ###   ########.fr       */
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


# define TILE_SIZE 64
# define KEY_ESC 53
# define KEY_W 119
# define KEY_UP 126
# define KEY_A 0
# define KEY_LEFT 123
# define KEY_S 1
# define KEY_DOWN 125 
# define KEY_D 2
# define KEY_RIGHT 124 
# define MOVING_RIGHT 1
# define MOVING_LEFT 2



typedef struct s_counts
{
  int player_count;
  int exit_count;
  int collect_count;

} t_counts;

typedef struct s_flood_data
{
  int width;
  int height;
  int c_found;
  int e_found;
} t_flood_data;

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
	void	*img_collectible;
  void	*img_exit;
}	t_game;


char	**set_map(char *map_file);
char	**check_map(char *map_file);
void	exit_error(char *str);


//render_map.c
void	render_map(t_game *game);

//check_map.c
char	**check_map(char *map_file);


//prepare_game.c
void	prepare_game(t_game *game);

//set_hooks.c
void	set_hooks(t_game *game);
int	expose_hook(t_game *game);
int	handle_keypress(int key, t_game *game);
int	close_window(t_game *game);

//set_map.c
char	**set_map(char *map_file);

//images.c
void	load_images(t_game *game);

// move.c
void	move_player(t_game *game, int x, int y);



#endif
