/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:51:37 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 16:35:09 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	make_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = FLOOR;
		game->collectibles--;
	}
	if (game->map[y][x] == EXIT && game->collectibles == 0)
	{
		ft_printf("Game finished!\n");
		exit_game(game);
	}
	game->player_x = x;
	game->player_y = y;
	game->move_count++;
}

static int	move_is_valid(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
	{
		return (0);
	}
	if (game->map[y][x] == EXIT && game->collectibles > 0)
	{
		return (0);
	}
	if ((x < 0 || x >= game->width) || (y < 0 || y >= game->height))
	{
		return (0);
	}
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
	else if (x < 0)
		game->player_direction = MOVING_LEFT;
	else if (y < 0)
		game->player_direction = MOVING_UP;
	else if (y > 0)
		game->player_direction = MOVING_DOWN;
	if (move_is_valid(game, new_x, new_y))
	{
		make_move(game, new_x, new_y);
		ft_printf("Movement count: %d\n", game->move_count);
	}
}
