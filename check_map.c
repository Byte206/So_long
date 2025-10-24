/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:18:47 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 19:21:14 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(char *map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (ft_strncmp(map_file + i - 4, ".ber", 4) != 0 || i < 4)
		exit_error(NULL, "Wrong file extension\n");
}

static size_t	line_len(const char *s)
{
    size_t len;

    if (!s)
        return (0);
    len = ft_strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        return (len - 1);
    return (len);
}

static void	check_width(char **map)
{
    size_t	expected;
    int		i;

    if (!map || !map[0])
        exit_error(NULL, "Empty map\n");
    expected = line_len(map[0]);
    i = 0;
    while (map[i])
    {
        if (line_len(map[i]) != expected)
            exit_error(NULL, "Map lines don't have same width\n");
        i++;
    }
}

static void	check_invalid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				exit_error(NULL, "Invalid character in map\n");
			j++;
		}
		i++;
	}
}

char	**check_map(char *map_file)
{
	char	**map;

	check_extension(map_file);
	map = set_map(map_file);
	check_width(map);
	check_invalid(map);
	return (map);
}
