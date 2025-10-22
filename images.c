/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:05:02 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/22 17:28:52 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_basic_img(t_game *game, int width, int height)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE,
			width, height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE,
			width, height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_SPRITE,
			width, height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE,
			width, height);
}

static void	load_player_img(t_game *game, int width, int height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE,
			width, height);
	game->img_player_moving_right = mlx_xpm_file_to_image(game->mlx,
			MOVING_RIGHT, width, height);
	game->img_player_moving_left = mlx_xpm_file_to_image(game->mlx, MOVING_LEFT,
			width, height);
}

void	load_images(t_game *game)
{
	load_basic_img(game, TILE_SIZE, TILE_SIZE);
	load_player_img(game, TILE_SIZE, TILE_SIZE);
	if (!game->img_wall || !game->img_floor || !game->img_collectible
		|| !game->img_exit || !game->img_player
		|| !game->img_player_moving_right || !game->img_player_moving_left)
	{
		exit_error("Error creating images\n");
	}
}
