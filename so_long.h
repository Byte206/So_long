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
  void  *mlx;
  void  *window;
  char  **map;
  int   width;
  int   weight;
  int   player_x;
  int   player_y;
  int	move_count;
  int	collectibles;
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
void	check_extension(char *map_file);
void	exit_error(char *str);
	
#endif
