/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:31:46 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/04 19:17:15 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include"minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"

typedef struct play
{
	char **map;
	char **new_map;
	int move;
	int coin_c;
	void *coin;
	void *wall;
	void *floor;
	int exit_c;
	void *exit;
	int coin_fake_c;
	// int exit_x;
	// int exit_y;
	void *mlx;
	void *win;
	void *player;
	int player_c;
	int map_x;
	int map_y;
	int start_loc_x;
	int start_loc_y;
}	t_play;

char *remove_newline(char *line);
void err_mess(char *mes);
void map_check(t_play *game);
int check_path(t_play *game, int x,int y,char **map);
int valid_char(t_play *game);
int count_line(char *file);
void read_file(t_play *game ,char *file_name);
void load_img(t_play *game, int x, int y);
void chck_img(t_play *game, int x, int y);
int move_mech(int key_code, t_play *game);
char	*ft_strdup(char *s1);
void print_map(t_play *game);
char **clone_map(t_play *game ,char **map);
void count(t_play *game);
void clean_map(t_play *game);
void newprint_map(t_play *game);
void turn_to_img(t_play *game);
void put_img(t_play *game);
int close_win(t_play *game);
void win(t_play *game);
char	*ft_strrchr(const char *s, int c);
//size_t	ft_strlen(const char *x);
void ber_cont(char *filename);
void cf(t_play *game, char **map);
void flood_fill1(t_play *game,int x, int y);
void flood_fill3(t_play *game,int x, int y);
#endif