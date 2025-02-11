/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:43:47 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/11 18:39:09 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_play *game)
{
	if (game->map[game->start_loc_y - 1][game->start_loc_x] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y - 1][game->start_loc_x] = '0';
	}
	else if (game->map[game->start_loc_y - 1][game->start_loc_x] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			exit_2(game);
			handle_free(game);
			win();
		}
	}
	if ((game->map[game->start_loc_y - 1][game->start_loc_x] != '1'
		&& game->map[game->start_loc_y - 1][game->start_loc_x] != 'E'))
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_y--;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

void	move_a(t_play *game)
{
	if (game->map[game->start_loc_y][game->start_loc_x - 1] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y][game->start_loc_x - 1] = '0';
	}
	else if (game->map[game->start_loc_y][game->start_loc_x - 1] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			exit_2(game);
			handle_free(game);
			win();
		}
	}
	if (game->map[game->start_loc_y][game->start_loc_x - 1] != '1'
		&& game->map[game->start_loc_y][game->start_loc_x - 1] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_x--;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

void	move_s(t_play *game)
{
	if (game->map[game->start_loc_y + 1][game->start_loc_x] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y + 1][game->start_loc_x] = '0';
	}
	else if (game->map[game->start_loc_y + 1][game->start_loc_x] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			exit_2(game);
			handle_free(game);
			win();
		}
	}
	if (game->map[game->start_loc_y + 1][game->start_loc_x] != '1'
		&& game->map[game->start_loc_y + 1][game->start_loc_x] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_y++;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

void	move_d(t_play *game)
{
	if (game->map[game->start_loc_y][game->start_loc_x + 1] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y][game->start_loc_x + 1] = '0';
	}
	else if (game->map[game->start_loc_y][game->start_loc_x + 1] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			exit_2(game);
			handle_free(game);
			win();
		}
	}
	if (game->map[game->start_loc_y][game->start_loc_x + 1] != '1'
		&& game->map[game->start_loc_y][game->start_loc_x + 1] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_x++;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

int	move_mech(int key_code, t_play *game)
{
	if (key_code == 119 || key_code == 65362)
		move_w(game);
	else if (key_code == 97 || key_code == 65361)
		move_a(game);
	else if (key_code == 115 || key_code == 65364)
		move_s(game);
	else if (key_code == 100 || key_code == 65363)
		move_d(game);
	else if (key_code == 65307)
		exit_program(game);
	else
		return (0);
	ft_printf("\033[32mMOVE %d  COIN %d\n", game->move, game->coin_c);
	return (1);
}
