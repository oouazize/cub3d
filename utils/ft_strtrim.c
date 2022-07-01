/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:21:20 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/28 21:58:39 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find(char const str, char const *s)
{
	while (*s)
	{
		if (str == *s)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	char	*cpy;
	int		length;
	int		l;

	i = 0;
	l = 0;
	if (!s1)
		return (0);
	length = ft_strlen(s1) - 1;
	while (i < length && find(s1[i], set))
		i++;
	while (length >= 0 && find(s1[length], set))
		length--;
	if (length < i)
		cpy = (char *)malloc(sizeof(char));
	else
		cpy = (char *)malloc((length - i + 2) * sizeof(char));
	if (cpy == NULL)
		return (0);
	while (i <= length)
		cpy[l++] = s1[i++];
	cpy[l] = '\0';
	free(s1);
	return (cpy);
}

void	add_map(t_info *infos, int x)
{
	int	c;
	int	j;

	c = 0;
	while (infos->map->map[++x])
	{
		j = -1;
		while (infos->map->map[x][++j])
			infos->map->map1[c][j] = infos->map->map[x][j];
		c++;
	}
}
