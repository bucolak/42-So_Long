/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:40:42 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/05 20:27:21 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void turn_to_img(t_play *game)
{
    int width;
    int height;
    
    game->player = mlx_xpm_file_to_image(game->mlx, "img/character.xpm", &width, &height);
    if (!game->player)
        err_mess(game,"No player img!\n");
    game->coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm", &width, &height);
    if (!game->coin)
        err_mess(game,"No coin img!\n");
    game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &width, &height);
    if (!game->wall)
        err_mess(game,"No wall img!\n");
    game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &width, &height);
    if (!game->floor)
        err_mess(game,"No floor img!\n");
    game->exit = mlx_xpm_file_to_image(game->mlx, "img/door.xpm", &width, &height);
    if (!game->exit)
        err_mess(game,"No exit door img!\n");
}

void put_img(t_play *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < game->map_y)
    {
        j = 0;
        while(j < game->map_x)
        {
            if(game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, j*32, i*32);
            else if(game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->floor, j*32, i*32);
            else if(game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player, j*32, i*32);
            else if(game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit, j*32, i*32);
            else if(game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->coin, j*32, i*32);
            j++;
        }
        i++;
    }
}

void ber_cont(t_play *game,char *filename)
{
    int s = ft_strlen(filename);
    if(!filename || s <4)
    {
        free_split(game->map);
        free_split(game->new_map);
        err_mess(game,"map name is wrong!\n");
    }
        
    if(filename[s-1] != 'r' || filename[s-2] != 'e' || filename[s-3] != 'b' || filename[s-4] != '.')
    {
        free_split(game->new_map);
        free_split(game->map);
        err_mess(game,"map name is wrong!\n");
    }
        
}
