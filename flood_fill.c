/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:00:39 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 19:28:48 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
    int		rows;
    int		i;
    char	**new;

    if (!map)
        return (NULL);
    rows = 0;
    while (map[rows])
        rows++;
    new = malloc(sizeof(char *) * (rows + 1));
    if (!new)
        return (NULL);
    i = 0;
    while (i < rows)
    {
        new[i] = ft_strdup(map[i]);
        if (!new[i])
        {
            new[i] = NULL;
            free_matrix(new);
            return (NULL);
        }
        i++;
    }
    new[rows] = NULL;
    return (new);
}

static void	ff_fill(char **m, int x, int y)
{
	int	len;

	if (!m || y < 0 || x < 0)
		return ;
	if (!m[y])
		return ;
	len = (int)ft_strlen(m[y]);
	if (x >= len)
		return ;
	if (m[y][x] == '1' || m[y][x] == 'V')
		return ;
	m[y][x] = 'V';
	ff_fill(m, x + 1, y);
	ff_fill(m, x - 1, y);
	ff_fill(m, x, y + 1);
	ff_fill(m, x, y - 1);
}

static int	find_player_pos(char **map, int *px, int *py)
{
	int	y;
	int	x;

	if (!map || !px || !py)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_playable(char **map, char **cpy)
{
	int	y;
	int	x;

	if (!map || !cpy)
		return (0);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'C' || map[y][x] == 'E') && cpy[y][x] != 'V')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(t_game *game)
{
	char	**cpy;
	int		px;
	int		py;

	if (!game || !game->map)
		return ;
	if (!find_player_pos(game->map, &px, &py))
		exit_error(game, "Player position not found for flood fill\n");
	cpy = copy_map(game->map);
	if (!cpy)
		return ;
	ff_fill(cpy, px, py);
	if (!check_playable(game->map, cpy))
	{
		free_matrix(cpy);
		exit_error(game, "Map not playable\n");
	}
	free_matrix(cpy);
}
