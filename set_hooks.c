/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:46:23 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/22 18:11:53 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit (0);
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}

int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0 , -1);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game,  0, 1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0);
	render_map(game);
	return (0);
}

int	expose_hook(t_game *game)
{
	render_map(game);
	return (0);
}

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_expose_hook(game->window, expose_hook, game);
//	mlx_loop_hook(game->mlx, animation_loop, game);
}
