/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:21:59 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 14:03:32 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void checkmap1(t_info *infos, int *i)
{
	int j;


	infos->map->map = ft_getmap(infos);
	while (infos->map->map[*i])
	{
		j = 3;
		ft_skipspace(infos, &j, *i);
		if (!ft_strncmp(infos->map->map[*i], "NO ", 3))
		{
			infos->map->no_text = ft_strdup(&infos->map->map[*i][j]);
			infos->map->north = 1;
		}
		if (!ft_strncmp(infos->map->map[*i], "SO ", 3))
		{
			infos->map->so_text = ft_strdup(&infos->map->map[*i][j]);
			infos->map->south = 1;
		}
		if (!ft_strncmp(infos->map->map[*i], "EA ", 3))
		{
			infos->map->ea_text = ft_strdup(&infos->map->map[*i][j]);
			infos->map->east = 1;
		}
		if (!ft_strncmp(infos->map->map[*i], "WE ", 3))
		{
			infos->map->we_text = ft_strdup(&infos->map->map[*i][j]);
			infos->map->west = 1;
		}
		if (!ft_strncmp(infos->map->map[*i], "F ", 2))
		{
			j = 2;
			ft_skipspace(infos, &j, *i);
			if (!check_comma(infos, j, *i))
				printf("Invalid color!!\n");
			infos->map->ceiling = 1;
		}
		if (!ft_strncmp(infos->map->map[*i], "C ", 2))
		{
			j = 2;
			ft_skipspace(infos, &j, *i);
			if (!check_comma1(infos, j, *i))
				printf("Invalid color11!!\n");
			infos->map->floor = 1;
			break;
		}
		(*i)++;
	}
}

int checkmap(t_info *infos)
{
	int i;
	int j;

	i = 0;
	while (infos->map->map1[i])
	{
		j = 0;
		while (infos->map->map1[i][j])
			j++;
		i++;
	}
	return (1);
}