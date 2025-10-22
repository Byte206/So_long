/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:13:03 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/22 18:31:57 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;
	
	if (tile == '1')
		img = game->img_wall;
	if (tile == '0')
		img = game->img_floor;
	if (tile == 'C')
		img = game->img_collectible;
	if (tile == 'E')
		img = game->img_exit;
	if (tile == 'P')
	{
		if (game->player_direction == MOVING_RIGHT)
			img = game->img_player_moving_right;
		if (game->player_direction == MOVING_LEFT)
			img = game->img_player_moving_left;
	}
}


static void	render_one_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game-> window, game->img_floor,
				x * TILE_SIZE, y * TILE_SIZE);
	if (game->player_x == x && game->player_y == y)
		render_tile(game, x, y, 'P');
	else
	{
		if (game->map[y][x] != '0')
			render_tile(game, x, y, game->map[y][x]);
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_one_tile(game, x, y);
			x++;
		}
		y++;
	}
}
