/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:31:56 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 09:39:58 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static  int	get_num_of_lines(char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}


char	**set_map(char *map_file)
{
	int		i;
	int		fd;
	int		len;
	char	**map;

	fd = open(map_file, O_RDONLY);
	i = 0;
	len = get_num_of_lines(map_file);
	map = malloc(sizeof(char *) * (len + 1));
	map[len] = '\0';
	while (i < len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
