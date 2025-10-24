/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:31:56 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/24 19:24:51 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*trim_newline_and_dup(char *s)
{
    size_t	len;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
    return (ft_strdup(s));
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
        free(line); /* liberar el buffer que get_next_line devuelve */
        count++;
    }
    close(fd);
    return (count);
}

char	**set_map(const char *map_file)
{
    int		fd;
    char	*line;
    int		lines;
    char	**map;
    int		i;

    lines = get_num_of_lines(map_file);
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        exit_error(NULL, "Malloc failed\n");
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        exit_error(NULL, "Could not open map file\n");
    i = 0;
    while (i < lines)
    {
        line = get_next_line(fd);
        map[i] = trim_newline_and_dup(line);
        free(line); /* liberar siempre la línea original */
        if (!map[i])
        {
            /* liberar lo ya asignado */
            while (--i >= 0)
                free(map[i]);
            free(map);
            close(fd);
            exit_error(NULL, "Malloc failed\n");
        }
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

