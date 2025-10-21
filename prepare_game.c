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

void	prepare_game(t_game *game, char **map)
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
	game->moves = 0;
	game->
}
