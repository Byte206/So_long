/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:18:47 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 15:08:49 by gamorcil         ###   ########.fr       */
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
	while (map[i + 2])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
		{
			exit_error("Map lines dosent have same width\n");
		}
		i++;
	}
	if ((ft_strlen(map[i])) != ft_strlen(map[i + 1]))
	{
		exit_error("Map lines dosent have same width\n");
	}
}

static void	check_repeated(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				count++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				exit_error("Invalid character in map\n");
			j++;
		}
		i++;
	}
	if (count < 2)
		exit_error("Wrong number of exits or players in map\n");
}

char	**check_map(char *map_file)
{
	char	**map;

	check_extension(map_file);
	map = set_map(map_file);
	check_width(map);
	check_repeated(map);
	ft_printf("Map checks passed successfully\n");
	return (map);
}
