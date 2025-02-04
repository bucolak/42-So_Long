/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:36:19 by bucolak           #+#    #+#             */
/*   Updated: 2025/02/03 16:50:53 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// size_t	ft_strlen(const char *x)
// {
// 	size_t	i;

// 	i = 0;
// 	while (x[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = ft_strlen(s);
// 	while (i >= 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i--;
// 	}
// 	return (0);
// }