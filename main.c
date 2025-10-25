/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:59:06 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/25 13:31:14 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_player_moving_right)
		mlx_destroy_image(game->mlx, game->img_player_moving_right);
	if (game->img_player_moving_left)
		mlx_destroy_image(game->mlx, game->img_player_moving_left);
	if (game->img_player_moving_up)
		mlx_destroy_image(game->mlx, game->img_player_moving_up);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free_matrix(game->map);
	free(game);
}

static void	check_player_and_exit(char **map)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			else if (map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1)
		exit_error(NULL, "Invalid number of players or exits\n");
}

static void	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectible_count;

	collectible_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	if (collectible_count < 1)
		exit_error(NULL, "There is no collectible\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_error(NULL, "Wrong arguments\nUsage: ./so_long.h [file_to_map]\n");
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		exit_error(NULL, "Malloc failed\n");
	}
	game->map = check_map(argv[1]);
	if (!game->map)
	{
		free(game);
		exit_error(NULL, "Error loading map\n");
	}
	check_player_and_exit(game->map);
	check_collectibles(game->map);
	flood_fill(game);
	prepare_game(game);
	mlx_loop(game->mlx);
	return (0);
}
