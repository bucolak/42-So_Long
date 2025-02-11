/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:18:32 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/09 14:11:25 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(void)
{
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

void	err_mess(t_play *game, char *mes)
{
	ft_printf("\033[0;31m%s\033[0m\n", mes);
	if (game->map || game->new_map)
		handle_free(game);
	exit(0);
}
