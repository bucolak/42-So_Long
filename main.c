/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:34:00 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/05 20:28:13 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void inital(t_play *game)
{
	game->move = 0;
	game->coin_c = 0;
	game->exit_c = 0;
	game->start_loc_x = 0;
	game->start_loc_y = 0;
	game->player_c = 0;
	game->map_x = 0;
	game->map_y = 0;
}
int close_win(t_play *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(0);
	return 0;
}
void	free_map(t_play *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}
void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
		return 0;
	t_play game;
	inital(&game);
	read_file(&game, argv[1]);
	count(&game);
	if (game.player_c != 1)
	{
		free_split(game.map);
		free_split(game.new_map);
		err_mess(&game,"İnvalid number of player!\n");
	}
	map_check(&game);
	find_player(&game);
	ber_cont(&game,argv[1]);
	free_split(game.new_map);
	game.mlx=mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_x*32, game. map_y*32, "so_long");
	turn_to_img(&game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_hook(game.win, 2, 1L << 0, move_mech, &game);
	mlx_loop_hook(game.mlx, (void *)put_img, &game);
	mlx_loop(game.mlx);
	return 0;
}
