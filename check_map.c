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

void	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (ft_strncmp(str + i - 4, ".ber", 4) != 0 || i < 4)
		exit_error("Wrong file extension\n");
}


char	**check_map(char *str)
{
	char	**map;

	check_extension(str);
	map = set_map(str);

	return (map);
}
