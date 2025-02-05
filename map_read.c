/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:32:33 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/05 14:21:24 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_play *game)
{
    int i = 0;
    while (i < game->map_y)
    {
        ft_printf("%s", game->map[i]);
        i++;
    }
}
void newprint_map(t_play *game)
{
    int i = 0;
    while (i < game->map_y)
    {
        ft_printf("%s", game->new_map[i]);
        i++;
    }
}
char **clone_map(t_play *game ,char **map)
{
	char **nmap;
	int i;

	i = 0;
	nmap = malloc((game->map_y + 1) * sizeof(char *));;
	if(!nmap)
		err_mess("hatali yer!\n");
	while(map[i])
	{
		nmap[i] = ft_strdup(map[i]);
		i++;
	}
	//nmap[i] = NULL;
	return nmap;
}

char *remove_newline(char *line)
{
    // char *new_line;
    int len;

    len = ft_strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';  // Newline karakterini sonlandırıcı null karakter ile değiştir
    return (line);
}

int count_line(char *file)
{
	int fd;
	char *line;
	int c;
	
	c = 0;
	fd = open(file, O_RDONLY);
	if(fd<0)
		err_mess("hatali fd\n");
	line=get_next_line(fd);
	while(line)
	{
		c++;
		line=get_next_line(fd);
	}
	close(fd);
	return c;
}
#include <string.h>
void read_file(t_play *game ,char *file_name)
{
	int i;
	int fd;
	char *line;
	i = 0;
	game->map_y = count_line(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd<0)
		err_mess("hatali\n");
	game->map = malloc(sizeof(char *)*(game->map_y+1));
	if (!game->map)
		err_mess("yer açilamadı!\n");
	line = get_next_line(fd);
	while(line)
	{
		game->map[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	game->new_map = clone_map(game, game->map);
	game->map_x = ft_strlen(game->map[0])-1;
	close(fd);
}


