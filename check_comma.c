/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:19:55 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/25 19:21:38 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_char(char **color)
{
	int i = 0;
	while (color[i])
	{
		if (ft_isalpha(color[i]) || ft_isascii(color[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_comma(t_info *infos, int j, int i)
{
	int count;
	char **color;

	count = 0;
	color = ft_split(&infos->map->map[i][j], ',');
	if (check_char(color))
	{
		printf("Invalid Color Number!!\n");
	}
	infos->map->red = ft_atoi(color[0]);
	infos->map->green = ft_atoi(color[1]);
	infos->map->blue = ft_atoi(color[2]);
	while (infos->map->map[i][j])
	{
		if (infos->map->map[i][j] == ',')
			count++;
		j++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int check_comma1(t_info *infos, int j, int i)
{
	int count;
	char **color;

	count = 0;
	color = ft_split(&infos->map->map[i][j], ',');
	if (check_char(color))
	{
		printf("Invalid Color Number!!\n");
	}
	infos->map->red1 = ft_atoi(color[0]);
	infos->map->green1 = ft_atoi(color[1]);
	infos->map->blue1 = ft_atoi(color[2]);
	while (infos->map->map[i][j])
	{
		if (infos->map->map[i][j] == ',')
			count++;
		j++;
	}
	if (count == 2)
		return (1);
	return (0);
}