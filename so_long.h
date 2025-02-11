/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:31:46 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/09 13:59:32 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct play
{
	char	**map;
	char	**new_map;
	int		move;
	int		coin_c;
	void	*coin;
	void	*wall;
	void	*floor;
	int		exit_c;
	void	*exit;
	void	*mlx;
	void	*win;
	void	*player;
	int		player_c;
	int		map_x;
	int		map_y;
	int		start_loc_x;
	int		start_loc_y;
}			t_play;

int			find_e_x(t_play *game);
int			find_e_y(t_play *game);
void		find_player(t_play *game);
int			find_char(t_play *game, char c);
void		err_mess(t_play *game, char *mes);
void		map_check(t_play *game);
void		read_file(t_play *game, char *file_name);
int			move_mech(int key_code, t_play *game);
char		*ft_strdup(char *s1);
void		turn_to_img(t_play *game);
int			put_img(t_play *game);
int			close_win(t_play *game);
void		win(void);
void		ber_cont(t_play *game, char *filename);
void		cf(t_play *game, char **map);
void		flood_fill1(t_play *game, int x, int y);
void		free_map(t_play *game);
int			exit_program(t_play *game);
void		exit_2(t_play *game);
void		handle_free(t_play *game);
void		free_newmap(t_play *game);

#endif