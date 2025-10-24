/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:59:06 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 16:36:21 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
    t_game	*game;

    if (argc != 2)
        exit_error("Wrong arguments\nUsage: ./so_long.h [file_to_map]\n");
    game = calloc(1, sizeof(t_game));
    if (!game)
    {
        exit_error("Memory allocation failed\n");
    }
    game->map = check_map(argv[1]);
    if (!game->map)
    {
        free(game);
        exit_error("Error loading map\n");
    }
    prepare_game(game);
    mlx_loop(game->mlx);
    return (0);
}
