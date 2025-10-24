/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:05:02 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 19:25:15 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_basic_img(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE, &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE, &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_SPRITE,
			&w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE, &w, &h);
}

static void	load_player_img(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE, &w, &h);
	game->img_player_moving_right = mlx_xpm_file_to_image(game->mlx,
			MOVING_RIGHT_SPRITE, &w, &h);
	game->img_player_moving_left = mlx_xpm_file_to_image(game->mlx,
			MOVING_LEFT_SPRITE, &w, &h);
	game->img_player_moving_up = mlx_xpm_file_to_image(game->mlx,
			MOVING_UP_SPRITE, &w, &h);
}

void	load_images(t_game *game)
{
	load_basic_img(game);
	load_player_img(game);
	if (!game->img_wall || !game->img_floor || !game->img_collectible
		|| !game->img_exit || !game->img_player
		|| !game->img_player_moving_right || !game->img_player_moving_left
		|| !game->img_player_moving_up)
	{
		exit_error(game, "Error creating images\n");
	}
}
