/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:43:47 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/04 13:31:50 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void move_w(t_play *game)
{
	if (game->map[game->start_loc_y-1][game->start_loc_x] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y-1][game->start_loc_x] = '0';
	}	
	else if (game->map[game->start_loc_y-1][game->start_loc_x] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			win(game);
		}

	}
	if (game->map[game->start_loc_y-1][game->start_loc_x] != '1' && game->map[game->start_loc_y-1][game->start_loc_x] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_y--;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

void move_a(t_play *game)
{
	if (game->map[game->start_loc_y][game->start_loc_x-1] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y][game->start_loc_x-1] = '0';
	}
	else if (game->map[game->start_loc_y][game->start_loc_x-1] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			win(game);
		}
	}
	if (game->map[game->start_loc_y][game->start_loc_x-1] != '1' && game->map[game->start_loc_y][game->start_loc_x-1] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_x--;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

void move_s(t_play *game)
{
	if (game->map[game->start_loc_y+1][game->start_loc_x] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y+1][game->start_loc_x] = '0';
	}
	else if (game->map[game->start_loc_y+1][game->start_loc_x] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			win(game);
		}
	}
	if (game->map[game->start_loc_y+1][game->start_loc_x] != '1' && game->map[game->start_loc_y+1][game->start_loc_x] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_y++;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

void move_d(t_play *game)
{
	if (game->map[game->start_loc_y][game->start_loc_x+1] == 'C')
	{
		game->coin_c--;
		game->map[game->start_loc_y][game->start_loc_x+1] = '0';
	}
	else if (game->map[game->start_loc_y][game->start_loc_x+1] == 'E')
	{
		if (game->coin_c == 0)
		{
			game->map[game->start_loc_y][game->start_loc_x] = '0';
			win(game);
		}
	}
		if (game->map[game->start_loc_y][game->start_loc_x+1] != '1' && game->map[game->start_loc_y][game->start_loc_x+1] != 'E')
	{
		game->map[game->start_loc_y][game->start_loc_x] = '0';
		game->start_loc_x++;
		game->map[game->start_loc_y][game->start_loc_x] = 'P';
		game->move++;
	}
}

int move_mech(int key_code, t_play *game)
{
	if (key_code == 119 || key_code == 65362)
	{
		ft_printf("\033[1;32mMOVE %d  COIN %d\n", game->move, game->coin_c);
		move_w(game);
		return 1;
	}
	else if (key_code == 97 || key_code == 65361)
	{
		ft_printf("\033[1;32mMOVE %d  COIN %d\n", game->move, game->coin_c);
		move_a(game);
		return 1;
	}
	else if (key_code == 115 || key_code == 65364)
	{
		ft_printf("\033[1;32mMOVE %d  COIN %d\n", game->move, game->coin_c);
		move_s(game);
		return 1;
	}
	else if (key_code == 100 || key_code == 65363)
	{
		ft_printf("\033[1;32mMOVE %d  COIN %d\n", game->move, game->coin_c);
		move_d(game);
		return 1;
	}
	else if (key_code == 65307)
	{
		close_win(game);
		return 1;
	}
	return 0;
}