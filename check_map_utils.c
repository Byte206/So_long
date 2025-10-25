/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:22:50 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/25 13:22:51 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	check_first_last_row(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			exit_error(NULL, "Map is not surrounded by walls\n");
		i++;
	}
}

void	check_wall(char **map)
{
	int	i;
	int	rows;

	if (!map || !map[0])
		exit_error(NULL, "Invalid map\n");
	rows = count_rows(map);
	check_first_last_row(map[0]);
	check_first_last_row(map[rows - 1]);
	i = 1;
	while (i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			exit_error(NULL, "Map is not surrounded by walls\n");
		i++;
	}
}
