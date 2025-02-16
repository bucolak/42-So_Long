/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:37:32 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/16 13:47:21 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_play *game)
{
	int	i;

	i = 0;
	while (i < game->map_x - 1)
	{
		if (game->map[0][i] != '1' || game->map[game->map_y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_y)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_char(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x - 1)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'E' &&
				game->map[i][j] != 'P' && game->map[i][j] != 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_shape(t_play *game)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(game->map[0]);
	while (i < game->map_y - 1)
	{
		if ((int)ft_strlen(game->map[i]) != width)
			return (0);
		i++;
	}
	if ((int)ft_strlen(game->map[game->map_y - 1]) != (width - 1))
		return (0);
	return (1);
}

void	map_check(t_play *game)
{
	if (game->map_x == game->map_y || check_map_shape(game) == 0)
	{
		err_mess(game, "Map is not rectangular!\n");
	}
	if (check_walls(game) == 0)
	{
		err_mess(game, "İnvalid walls!\n");
	}
	if (valid_char(game) == 0)
	{
		err_mess(game, "Invalid char!\n");
	}
}
