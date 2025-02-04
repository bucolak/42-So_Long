/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:34:00 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/04 19:34:08 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void inital(t_play *game)
{
	game->move = 0;
	game->coin_c = 0;
	game->exit_c = 0;
	// game->exit_x = 0;
	// game->exit_y = 0;
	game->start_loc_x = 0;
	game->start_loc_y = 0;
	game->player_c = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->coin_fake_c=0;
}
int close_win(t_play *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return 0;
}

void find_player(t_play *game)
{
    int i;
	int j;

	i = 0;
	j = 0;
	while(i < game->map_y)
	{
		j = 0;
		while(j < game->map_x)
		{
			if(game->map[i][j] == 'P')
			{
				// ft_printf("%d %d\n", i, j);
				game->start_loc_x = j;
				game->start_loc_y = i;
			}
			j++;
		}
		i++;
	}
	flood_fill1(game, game->start_loc_x, game->start_loc_y);
	flood_fill3(game, game->start_loc_x, game->start_loc_y);
	newprint_map(game);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
		return 0;
	t_play game;
	inital(&game);
	read_file(&game, argv[1]);
	//print_map(&game);
// 	ft_printf("\n");
	count(&game);
	game.coin_fake_c=game.coin_c; //.........
	find_player(&game);
	cf(&game, game.new_map);
	//ft_printf("%d %d\n", game.start_loc_x, game.start_loc_y);
	map_check(&game);
	ber_cont(argv[1]);
	game.mlx=mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_x*32, game. map_y*32, "so_long");
	turn_to_img(&game);
	
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_hook(game.win, 2, 1L << 0, move_mech, &game);
	mlx_loop_hook(game.mlx, (void *)put_img, &game);
	mlx_loop(game.mlx);
	return 0;
}


















// void clean_map(t_play *game)
// {
//     int i, j;

//     i = 0;
//     while (i < game->map_y)
//     {
//         j = 0;
//         while (j < game->map_x)
//         {
//             if (game->new_map[i][j] == '\n')
//                 game->new_map[i][j] = '\0';
//             j++;
//         }
//         i++;
//     }
// }