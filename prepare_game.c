/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:41:30 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 14:32:18 by gamorcil         ###   ########.fr       */
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

static void	set_size(t_game *game)
{
	int	i;

	i = 0;
	game->width = ft_strlen(game->map[0]) - 1;
	while (game->map[i])
		i++;
	game->height = i;
}

void	prepare_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Mlx error\n");
	ft_printf("MLX initialized successfully\n");
	set_size(game);
	ft_printf("Window size: %d x %d\n", game->width * 64, game->height * 64);
	game->window_width = game->width * 64;
	game->window_height = game->height * 64;
	game->window = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "So Long");
	if (!game->window)
		exit_error("Error creating window\n");
	get_position_and_count(game);
	ft_printf("Loading images...\n");
	load_images(game);
	ft_printf("Setting hooks...\n");
	set_hooks(game);
	render_map(game);
}
