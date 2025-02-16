/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:36:19 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/16 13:59:34 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	find_player(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x)
		{
			if (game->map[i][j] == 'P')
			{
				game->start_loc_x = j;
				game->start_loc_y = i;
			}
			j++;
		}
		i++;
	}
	flood_fill1(game, game->start_loc_x, game->start_loc_y);
	cf(game, game->new_map);
}

int	find_e_x(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x)
		{
			if (game->map[i][j] == 'E')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_e_y(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x)
		{
			if (game->map[i][j] == 'E')
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_char(t_play *game, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x)
		{
			if (game->new_map[i][j] == c)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
