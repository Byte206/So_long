/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:31:56 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/25 13:26:45 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*trim_newline_and_dup(char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		len--;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

static void	cleanup_on_fail(char **map, int filled, int fd)
{
	while (--filled >= 0)
		free(map[filled]);
	free(map);
	if (fd >= 0)
		close(fd);
	exit_error(NULL, "Malloc failed\n");
}

int	get_num_of_lines(const char *path)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, "Could not open map file\n");
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**set_map(const char *map_file)
{
	int		fd;
	int		lines;
	int		i;
	char	*line;
	char	**map;

	lines = get_num_of_lines(map_file);
	map = malloc(sizeof(*map) * (lines + 1));
	fd = open(map_file, O_RDONLY);
	if (fd < 0 || !map)
		exit_error(NULL, "Error\n");
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		map[i] = trim_newline_and_dup(line);
		free(line);
		if (!map[i])
			cleanup_on_fail(map, i, fd);
		i++;
	}
	map[lines] = NULL;
	close(fd);
	return (map);
}

void	exit_error(t_game *game, char *str)
{
	ft_printf("%s", str);
	if (game)
		free_game(game);
	exit(1);
}
