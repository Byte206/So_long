/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:31:56 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/21 19:38:13 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*get_map_line(char *map_file)
{
	int		fd;
	t_list	*lines;
	t_list	*new;
	t_list	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening map file\n");
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			exit_error("Error opening map file\n");
		ft_lstadd_back(&lines, new);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines)
}

char	**set_map(char *map_file)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(map_file, O_RDONLY)
	if (fd < 0)
		exit_error("Error opening map file\n");
	str = get_next_line(fd)
	while (str)
	{
		i++;
		str = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (i + 1);
	map[i] = '\0';
	i = 0;
	while (map[i])
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}
