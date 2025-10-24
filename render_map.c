/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:13:03 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 18:11:38 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_floor(t_game *game, int x, int y)
{
	if (game->img_floor)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_static_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

	img = NULL;
	if (tile == '1')
		img = game->img_wall;
	else if (tile == 'C')
		img = game->img_collectible;
	else if (tile == 'E')
		img = game->img_exit;
	if (img)
		mlx_put_image_to_window(game->mlx, game->window, img,
			x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_all_tiles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_floor(game, x, y);
			if (game->map[y][x] != '0' && game->map[y][x] != 'P')
				draw_static_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *game)
{
	void	*pimg;

	if (game->player_x < 0 || game->player_y < 0)
		return ;
	pimg = game->img_player;
	if (game->player_direction == MOVING_RIGHT && game->img_player_moving_right)
		pimg = game->img_player_moving_right;
	else if (game->player_direction == MOVING_LEFT
		&& game->img_player_moving_left)
		pimg = game->img_player_moving_left;
	else if (game->player_direction == MOVING_UP && game->img_player_moving_up)
		pimg = game->img_player_moving_up;
	else if (game->player_direction == MOVING_DOWN && game->img_player)
		pimg = game->img_player;
	if (!pimg)
	{
		ft_printf("render_map: player image NULL\n");
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->window, pimg,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	if (!game || !game->mlx || !game->window || !game->map)
	{
		ft_printf("render_map: missing game/mlx/window/map\n");
		return ;
	}
	draw_all_tiles(game);
	draw_player(game);
}
