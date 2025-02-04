/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:37:32 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/04 19:40:38 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_walls(t_play *game)
{
	int i;

	i = 0;
	while(i < game->map_x-1)
	{
		if(game->map[0][i] != '1')
			return 0;
		if (game->map[game->map_y-1][i] != '1')
			return 0;
		i++;
	}
	i = 0;
	while(i < game->map_x)
	{
		if(game->map[game->map_y-1][i] == '\n')
		{
			if (game->map[0][i] != '1' || game->map[game->map_y-2][i] != '1')
			{
				return 0;
			}
		}
		i++;
	}
	i = 0;
	while (i < game->map_y)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_x-1] != '1')
			return 0;
		i++;
	}
	return 1;
}

void count(t_play *game)
{
	int i,j;
	i = 0;

	while (i < game->map_y)
    {
        j = 0;
        while (j < game->map_x)
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
	//game->coin_fake_c=game->coin_c;
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

void flood_fill3(t_play *game,int x, int y)
{
	if(game->new_map[y][x+1] == 'E')
	{
		if(game->coin_c == 0)
		{
			game->new_map[y][x+1] = 'F';
			flood_fill1(game,x+1, y);
		}	
	}
	if(game->new_map[y][x-1] == 'E')
	{
		if(game->coin_c == 0)
		{
			game->new_map[y][x-1] = 'F';
			flood_fill1(game,x-1, y);
		}	
	}
	if(game->new_map[y+1][x] == 'E')
	{
		if(game->coin_c == 0)
		{
			game->new_map[y+1][x] = 'F';
			flood_fill1(game,x, y+1);
		}	
	}
	if(game->new_map[y-1][x] == 'E')
	{
		if(game->coin_c == 0)
		{
			game->new_map[y-1][x] = 'F';
			flood_fill1(game,x, y-1);
		}	
	}
}
void flood_fill1(t_play *game,int x, int y)
{
	if((game->new_map[y][x+1] == 'C' || game->new_map[y][x+1] == '0'
	   || game->new_map[y][x+1] == 'P'))
	{
		if(game->new_map[y][x+1] == 'C')
			game->coin_fake_c--;
		game->new_map[y][x+1] = 'F';
		flood_fill1(game,x+1, y);
	}
	if((game->new_map[y][x-1] == 'C' || game->new_map[y][x-1] == '0'
	   || game->new_map[y][x-1] == 'P'))
	{
		if(game->new_map[y][x+1] == 'C')
			game->coin_fake_c--;
		game->new_map[y][x-1] = 'F';
		flood_fill1(game,x-1, y);
	}
	if((game->new_map[y+1][x] == 'C' || game->new_map[y+1][x] == '0'
	   || game->new_map[y+1][x] == 'P'))
	{
		if(game->new_map[y][x+1] == 'C')
			game->coin_fake_c--;
		game->new_map[y+1][x] = 'F';
		flood_fill1(game,x, y+1);
	}
	if((game->new_map[y-1][x] == 'C' || game->new_map[y-1][x] == '0'
	   || game->new_map[y-1][x] == 'P'))
	{
		if(game->new_map[y][x+1] == 'C')
			game->coin_fake_c--;
		game->new_map[y-1][x] = 'F';
		flood_fill1(game,x, y-1);
	}
}
// void flood_fill1(t_play *game,int x, int y)
// {
// 	if((game->new_map[y][x+1] == 'C' || game->new_map[y][x+1] == '0'
// 	   || game->new_map[y][x+1] == 'E' || game->new_map[y][x+1] == 'P'))
// 	{
// 		game->new_map[y][x+1] = 'F';
// 		flood_fill1(game,x+1, y);
// 	}
// 	if((game->new_map[y][x-1] == 'C' || game->new_map[y][x-1] == '0'
// 	   || game->new_map[y][x-1] == 'E' || game->new_map[y][x-1] == 'P'))
// 	{
// 		game->new_map[y][x-1] = 'F';
// 		flood_fill1(game,x-1, y);
// 	}
// 	if((game->new_map[y+1][x] == 'C' || game->new_map[y+1][x] == '0'
// 	   || game->new_map[y+1][x] == 'E' || game->new_map[y+1][x] == 'P'))
// 	{
// 		game->new_map[y+1][x] = 'F';
// 		flood_fill1(game,x, y+1);
// 	}
// 	if((game->new_map[y-1][x] == 'C' || game->new_map[y-1][x] == '0'
// 	   || game->new_map[y-1][x] == 'E' || game->new_map[y-1][x] == 'P'))
// 	{
// 		game->new_map[y-1][x] = 'F';
// 		flood_fill1(game,x, y-1);
// 	}
// }

void map_check(t_play *game)
{
	if(game->coin_c<1)
		err_mess("There is less than one coin!\n");
	if (game->exit_c != 1)
		err_mess("İnvalid number of exit door!\n");
	if (game->player_c != 1)
		err_mess("İnvalid number of player!\n");
	if (game->map_x == game->map_y)
		err_mess("Map is not rectangular!\n");
	if (check_walls(game) == 0)
		err_mess("İnvalid walls!\n");
	if (valid_char(game) == 0)
		err_mess("Invalid char!\n");
}

void cf(t_play *game, char **map)
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
			// if(game->coin_fake_c==0 && map[i][j] == 'E')
			// 	return ;
			if(map[i][j] != 'E' && map[i][j] != 'F' && map[i][j] != '1')
			{	
				if (map[i][j] == '0')
				{
					if(map[i+1][j] == '1' && map[i-1][j] == '1' && map[i][j+1] == '1' && map[i][j-1] == '1')
						return ;
					
				}
				ft_printf("\n\n%c\n\n", map[i][j]);
				ft_printf("%d\n",i);
				ft_printf("%d\n",j);
				err_mess("hatali map\n");
			}
		//	ft_printf("%d\n",game->coin_fake_c);
			if(game->coin_fake_c==0)
				return ;
			j++;
		}
		i++;
	}
}
