/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:05:02 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 16:20:45 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_basic_img(t_game *game)
{
    int	w = TILE_SIZE;
    int	h = TILE_SIZE;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE, &w, &h);
    ft_printf("Loaded wall image\n");
    game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE, &w, &h);
    ft_printf("Loaded floor image\n");
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_SPRITE, &w, &h);
    ft_printf("Loaded collectible image\n");
    game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE, &w, &h);
    ft_printf("Loaded exit image\n");
}

static void	load_player_img(t_game *game)
{
    int	w = TILE_SIZE;
    int	h = TILE_SIZE;

    game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE, &w, &h);
    game->img_player_moving_right = mlx_xpm_file_to_image(game->mlx, MOVING_RIGHT_SPRITE, &w, &h);
    game->img_player_moving_left = mlx_xpm_file_to_image(game->mlx, MOVING_LEFT_SPRITE, &w, &h);
	game->img_player_moving_up = mlx_xpm_file_to_image(game->mlx, MOVING_UP_SPRITE, &w, &h);
}

void	load_images(t_game *game)
{
    ft_printf("Loading basic images...\n");
    load_basic_img(game);
    load_player_img(game);
  /*  if (!game->img_wall || !game->img_floor || !game->img_collectible
        || !game->img_exit || !game->img_player
        || !game->img_player_moving_right || !game->img_player_moving_left)
    {
        exit_error("Error creating images\n");
    }
	*/
	if (!game->img_wall)
		exit_error("Error loading wall image\n");
	if (!game->img_floor)
		exit_error("Error loading floor image\n");
	if (!game->img_collectible)
		exit_error("Error loading collectible image\n");
	if (!game->img_exit)
		exit_error("Error loading exit image\n");
	if (!game->img_player)
		exit_error("Error loading player image\n");
	if (!game->img_player_moving_right)
		exit_error("Error loading player moving right image\n");
	if (!game->img_player_moving_left)
		exit_error("Error loading player moving left image\n");
	
    ft_printf("Images loaded successfully\n");
}
