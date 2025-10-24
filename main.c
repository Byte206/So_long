/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:59:06 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 18:53:16 by gamorcil         ###   ########.fr       */
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
		exit_error("Invalid number of players or exits\n");
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
		exit_error("There is no collectible\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_error("Wrong arguments\nUsage: ./so_long.h [file_to_map]\n");
	game = calloc(1, sizeof(t_game));
	if (!game)
	{
		exit_error("Malloc failed\n");
	}
	game->map = check_map(argv[1]);
	if (!game->map)
	{
		free(game);
		exit_error("Error loading map\n");
	}
	check_player_and_exit(game->map);
	check_collectibles(game->map);
	flood_fill(game->map);
	prepare_game(game);
	mlx_loop(game->mlx);
	return (0);
}
