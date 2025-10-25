/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:41:30 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/25 13:35:12 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_position_and_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = '0';
			}
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
	game->total_collectibles = game->collectibles;
}

void	prepare_game(t_game *game)
{
	game->width = (int)ft_strlen(game->map[0]);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Error initializing mlx\n");
	game->window = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->window)
		exit_error(game, "Error creating window\n");
	get_position_and_count(game);
	load_images(game);
	set_hooks(game);
	render_map(game);
}
