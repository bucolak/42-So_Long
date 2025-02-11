/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:40:42 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/09 13:41:20 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	turn_to_img(t_play *game)
{
	int	width;
	int	height;

	game->player = mlx_xpm_file_to_image(game->mlx, "img/character.xpm", &width,
			&height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/door.xpm", &width,
			&height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &width,
			&height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &width,
			&height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm", &width,
			&height);
	if (!game->player || !game->exit || !game->floor || !game->wall
		|| !game->coin)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game, "Image loading failed!\n");
	}
}

void	put_single_img(t_play *game, int i, int j, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 32, i
			* 32);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, j * 32, i
			* 32);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, j * 32, i
			* 32);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 32, i
			* 32);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin, j * 32, i
			* 32);
}

int	put_img(t_play *game)
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
			put_single_img(game, i, j, game->map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

void	ber_cont(t_play *game, char *filename)
{
	int	s;

	s = ft_strlen(filename);
	if (!filename || s < 4)
	{
		handle_free(game);
		err_mess(game, "map name is wrong!\n");
	}
	if (filename[s - 1] != 'r' || filename[s - 2] != 'e'
		|| filename[s - 3] != 'b' || filename[s - 4] != '.')
	{
		handle_free(game);
		err_mess(game, "map name is wrong!\n");
	}
}
