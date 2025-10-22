/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:18:47 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/21 19:31:50 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(char *map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (ft_strncmp(map_file + i - 4, ".ber", 4) != 0 || i < 4)
		exit_error("Wrong file extension\n");
}

static void	check_width(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			exit_error("Map lines dosent have same width\n");
		i++;
	}
}

static void	check_repeated(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 2)
		exit_error("Wrong number of exits or players in map\n");
}

char	**check_map(char *map_file)
{
	char	**map;

	check_extension(map_file);
	map = set_map(map_file);
	check_width(map);
	check_repeated(map);

	return (map);
}
