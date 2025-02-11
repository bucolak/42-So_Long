/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:34:00 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/11 18:40:20 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inital(t_play *game)
{
	game->move = 0;
	game->coin_c = 0;
	game->exit_c = 0;
	game->start_loc_x = 0;
	game->start_loc_y = 0;
	game->player_c = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->map = NULL;
	game->new_map = NULL;
}

void	count(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player_c++;
			if (game->map[i][j] == 'C')
				game->coin_c++;
			if (game->map[i][j] == 'E')
				game->exit_c++;
			j++;
		}
		i++;
	}
	if (game->player_c != 1 || game->exit_c != 1 || game->coin_c < 1)
	{
		err_mess(game, "Map does not have the required elements!\n");
	}
}

int	close_win(t_play *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	handle_free(game);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_play	game;

	if (argc != 2)
		return (0);
	inital(&game);
	read_file(&game, argv[1]);
	count(&game);
	map_check(&game);
	find_player(&game);
	ber_cont(&game, argv[1]);
	free_newmap(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_x * 32, game.map_y * 32,
			"so_long");
	turn_to_img(&game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_hook(game.win, 2, 1L << 0, move_mech, &game);
	mlx_loop_hook(game.mlx, put_img, &game);
	mlx_loop(game.mlx);
	return (0);
}
