/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:59:06 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/21 11:59:45 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	if (argc != 2)
		exit_error("Wrong arguments\nUsage: ./so_long.h [file_to_map]\n");
	map = check_map(argv[1]);
	prepare_game(&game, map);
}
