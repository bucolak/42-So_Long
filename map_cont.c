/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:37:32 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/06 17:09:24 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_walls2(t_play *game)
{
	int i;

	i = 0;
	while(i < game->map_x)
	{
		if(game->map[game->map_y-1][i] == '\n')
		{
			if (game->map[0][i] != '1' || game->map[game->map_y-2][i] != '1')
				return 0;
		}
		i++;
	}
	return 1;
}
int check_walls(t_play *game)
{
	int i;

	i = 0;
	while(i < game->map_x-1)
	{
		if(game->map[0][i] != '1' || game->map[game->map_y-1][i] != '1')
			return 0;
		i++;
	}
	if(check_walls2(game)==0)
		return 0;
	i = 0;
	while (i < game->map_y)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_x-1] != '1')
			return 0;
		i++;
	}
	return 1;
}

int valid_char(t_play *game)
{
    int i;
    int j;
    i = 0;
    while (i < game->map_y)
    {
        j = 0;
        while (j < game->map_x)
        {
            if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'E' &&
                game->map[i][j] != 'P' && game->map[i][j] != 'C')
				{
					return 0;
				}
            j++;
        }
        i++;
    }
    return 1;
}

int check_map_shape(t_play *game)
{
    int i = 0;
    int width = ft_strlen(game->map[0]);

    while (i < game->map_y-1)
    {
        if ((int)ft_strlen(game->map[i]) != width)
            return (0);
        i++;
    }
	if((int)ft_strlen(game->map[game->map_y-1]) != (width-1))
		return 0;
    return (1);
}

void map_check(t_play *game)
{
	if(game->coin_c<1)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game,"There is less than one coin!\n");
	}
	if (game->exit_c != 1)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game,"İnvalid number of exit door!\n");
	}
	if (game->map_x == game->map_y || check_map_shape(game) == 0)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game,"Map is not rectangular!\n");
	}
	if (check_walls(game) == 0)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game,"İnvalid walls!\n");
	}
	if (valid_char(game) == 0)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game,"Invalid char!\n");
	}
}


















// void flood_fill3(t_play *game,int x, int y)
// {
// 	if(game->new_map[y][x+1] == 'E')
// 	{
// 		if(game->coin_c == 0)
// 		{
// 			game->new_map[y][x+1] = 'F';
// 			flood_fill1(game,x+1, y);
// 		}	
// 	}
// 	if(game->new_map[y][x-1] == 'E')
// 	{
// 		if(game->coin_c == 0)
// 		{
// 			game->new_map[y][x-1] = 'F';
// 			flood_fill1(game,x-1, y);
// 		}	
// 	}
// 	if(game->new_map[y+1][x] == 'E')
// 	{
// 		if(game->coin_c == 0)
// 		{
// 			game->new_map[y+1][x] = 'F';
// 			flood_fill1(game,x, y+1);
// 		}	
// 	}
// 	if(game->new_map[y-1][x] == 'E')
// 	{
// 		if(game->coin_c == 0)
// 		{
// 			game->new_map[y-1][x] = 'F';
// 			flood_fill1(game,x, y-1);
// 		}	
// 	}
// }

// void flood_fill1(t_play *game,int x, int y)
// {	
// 	if((game->new_map[y][x+1] == 'C' || game->new_map[y][x+1] == '0'
// 	   || game->new_map[y][x+1] == 'P'))
// 	{
// 		game->new_map[y][x+1] = 'F';
// 		flood_fill1(game,x+1, y);
// 	}
// 	if((game->new_map[y][x-1] == 'C' || game->new_map[y][x-1] == '0'
// 	   || game->new_map[y][x-1] == 'P'))
// 	{
// 		game->new_map[y][x-1] = 'F';
// 		flood_fill1(game,x-1, y);
// 	}
// 	if((game->new_map[y+1][x] == 'C' || game->new_map[y+1][x] == '0'
// 	   || game->new_map[y+1][x] == 'P'))
// 	{
// 		game->new_map[y+1][x] = 'F';
// 		flood_fill1(game,x, y+1);
// 	}
// 	if((game->new_map[y-1][x] == 'C' || game->new_map[y-1][x] == '0'
// 	   || game->new_map[y-1][x] == 'P'))
// 	{
// 		game->new_map[y-1][x] = 'F';
// 		flood_fill1(game,x, y-1);
// 	}
// }
// void flood_fill1(t_play *game,int x, int y)
// {
// 	if((game->new_map[y][x+1] == 'C' || game->new_map[y][x+1] == '0'
// 	   || game->new_map[y][x+1] == 'E' || game->new_map[y][x+1] == 'P'))
// 	{
// 		if (game->new_map[y][x+1] == 'E')
// 		{
// 			if (find_char(game, 'C') == 0)
// 				game->new_map[y][x+1] = 'F';
// 		}
// 		else
// 			game->new_map[y][x+1] = 'F';
// 		flood_fill1(game,x+1, y);
// 	}
// 	if((game->new_map[y][x-1] == 'C' || game->new_map[y][x-1] == '0'
// 	   || game->new_map[y][x-1] == 'E' || game->new_map[y][x-1] == 'P'))
// 	{
// 		if (game->new_map[y][x-1] == 'E')
// 		{
// 			if (find_char(game, 'C') == 0)
// 				game->new_map[y][x-1] = 'F';
// 		}
// 		else
// 			game->new_map[y][x-1] = 'F';
// 		flood_fill1(game,x-1, y);
// 	}
// 	if((game->new_map[y+1][x] == 'C' || game->new_map[y+1][x] == '0'
// 	   || game->new_map[y+1][x] == 'E' || game->new_map[y+1][x] == 'P'))
// 	{
// 		if (game->new_map[y+1][x] == 'E')
// 		{
// 			if (find_char(game, 'C') == 0)
// 				game->new_map[y+1][x] = 'F';
// 		}
// 		else
// 			game->new_map[y+1][x] = 'F';
// 		flood_fill1(game,x, y+1);
// 	}
// 	if((game->new_map[y-1][x] == 'C' || game->new_map[y-1][x] == '0'
// 	   || game->new_map[y-1][x] == 'E' || game->new_map[y-1][x] == 'P'))
// 	{
// 		if (game->new_map[y-1][x] == 'E')
// 		{
// 			if (find_char(game, 'C') == 0)
// 				game->new_map[y-1][x] = 'F';
// 		}
// 		else
// 			game->new_map[y-1][x] = 'F';
// 		flood_fill1(game,x, y-1);
// 	}
// }