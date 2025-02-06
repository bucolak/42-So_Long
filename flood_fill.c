/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:00:09 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/06 17:07:49 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill1(t_play *game,int x, int y)
{
	if (game->new_map[y][x] == 'C' || game->new_map[y][x] == '0' || game->new_map[y][x] == 'P')
		game->new_map[y][x] = 'F';
	if (game->new_map[y][x] == 'E')
	{
		if (find_char(game, 'C') == 0)
			game->new_map[y][x] = 'F';
		return;
	}
	if (game->new_map[y][x+1] != '1' && game->new_map[y][x+1] != 'F')
		flood_fill1(game, x+1, y);

	if (game->new_map[y][x-1] != '1' && game->new_map[y][x-1] != 'F')
		flood_fill1(game, x-1, y);

	if (game->new_map[y+1][x] != '1' && game->new_map[y+1][x] != 'F')
		flood_fill1(game, x, y+1);

	if (game->new_map[y-1][x] != '1' && game->new_map[y-1][x] != 'F')
		flood_fill1(game, x, y-1);
}

void ekcf(t_play *game, int i, int j)
{
	if (find_char(game, 'E') ==1 && find_char(game, 'C')==0)
	{
        game->new_map[find_e_x(game)][find_e_y(game)] = 'F';
        newprint_map(game);
        if (game->new_map[i][j] == '0')
	    {
		    if(find_char(game, 'C') == 0 && find_char(game, 'E')==0)
			    return ;
		    if(game->new_map[i+1][j] == '1' && game->new_map[i-1][j] == '1' && game->new_map[i][j+1] == '1' && game->new_map[i][j-1] == '1')
			    return ;
	    }
        if(game->new_map[i+1][j] == '1' && game->new_map[i-1][j] == '1' && game->new_map[i][j+1] == '1' && game->new_map[i][j-1] == '1')
        {
			exit_2(game);
			handle_free(game);
            // ft_printf("\n%c\n",game->new_map[i][j]);
             err_mess(game,"hatali map\n");	
        }
        if(find_char(game, '0') ==1)
        {
			exit_2(game);
			handle_free(game);
            // ft_printf("\n%c\n",game->new_map[i][j]);
            err_mess(game,"hatali map\n");
        }
		return ;
	}
	if (game->new_map[i][j] == '0')
	{
		if(find_char(game, 'C') == 0 && find_char(game, 'E')==0)
			return ;
		if(game->new_map[i+1][j] == '1' && game->new_map[i-1][j] == '1' && game->new_map[i][j+1] == '1' && game->new_map[i][j-1] == '1')
			return ;
	}	
	exit_2(game);
	handle_free(game);	
	err_mess(game,"hatali map\n");
}

void cf(t_play *game, char **map)
{
    int i;
	int j;

	i = 0;
	while(i < game->map_y)
	{
		j = 0;
		while(j < game->map_x)
		{
			if(map[i][j] != 'F' && map[i][j] != '1')
			{		
				ekcf(game,i,j);
			}
			j++;
		}
		i++;
	}
}