/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:18:32 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/02 19:47:30 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void win(t_play *game)
{
    mlx_destroy_window(game->mlx, game->win);
    //  mlx_loop_end(game->mlx);
    ft_printf("\033[1;34m");
    ft_printf("************************************************\n");
    ft_printf("*                                              *\n");
    ft_printf("*                                              *\n");
    ft_printf("*                🎉 YOU WIN! 🎉                *\n"); 
    ft_printf("*    Congratulations, you completed the game!  *\n");
    ft_printf("*                                              *\n");
    ft_printf("*                                              *\n");
    ft_printf("************************************************\n");
    ft_printf("\033[0m");
    exit(0);
}

void err_mess(char *mes)
{
    ft_printf("%s",mes);
    exit(0);
}