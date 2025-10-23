/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:51:37 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/22 18:54:39 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	make_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		return (0);
	if (game->map[y][x] == EXIT && game->collectibles > 0)
		return (0);
	if ((x < 0 || x >= game->width) || (y < 0 || y >= game->height))
		return (0);
	return (1);
}


void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (x > 0)
		game->player_direction = MOVING_RIGHT;
	else
		game->player_direction = MOVING_LEFT;
	if (move_is_valid(game, new_x, new_y))
		make_move(game, new_x, new_y);
}
