/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:41:30 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/21 21:47:32 by gamorcil         ###   ########.fr       */
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
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Mlx error\n");
	game->window_width = game->width * 64;
	game->window_height = game->height * 64 + 30;
	game->window = mlx_new_window(game->mlx, game->window_width,
							   game->window_height, "So Long");
	if (!game->window)
		exit_error("Error creating window\n");
	get_position_and_count(game);
	load_images(game);
	set_hooks(game);
	render_map(game);
}
