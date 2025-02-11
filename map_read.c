/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:32:33 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/07 17:27:56 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_map(t_play *game, char **map)
{
	char	**nmap;
	int		i;

	i = 0;
	nmap = malloc((game->map_y + 1) * sizeof(char *));
	if (!nmap)
	{
		exit_2(game);
		handle_free(game);
		err_mess(game, "wrong place!\n");
	}
	while (map[i])
	{
		nmap[i] = ft_strdup(map[i]);
		if (!nmap[i])
		{
			exit_2(game);
			handle_free(game);
			err_mess(game, "wrong place!\n");
		}
		i++;
	}
	nmap[i] = NULL;
	return (nmap);
}

int	count_line(t_play *game, char *file)
{
	int		fd;
	char	*line;
	int		c;

	c = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		err_mess(game, "wrong fd\n");
	}
	line = get_next_line(fd);
	while (line)
	{
		c++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (c);
}

void	aplly_malloc(t_play *game, int fd)
{
	if (fd < 0)
	{
		exit_2(game);
		err_mess(game, "wrong fd\n");
	}
	game->map = malloc(sizeof(char *) * (game->map_y + 1));
	if (!game->map)
	{
		free_map(game);
		exit_2(game);
		err_mess(game, "wrong place!\n");
	}
}

void	read_file(t_play *game, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	game->map_y = count_line(game, file_name);
	fd = open(file_name, O_RDONLY);
	aplly_malloc(game, fd);
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	if (i == 0)
	{
		err_mess(game, "no map\n");
	}
	game->new_map = clone_map(game, game->map);
	game->map_x = ft_strlen(game->map[0]) - 1;
	close(fd);
}
