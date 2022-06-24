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

	infos->map = ft_getmap(infos);
	while (infos->map[*i])
	{
		// infos->map[*i] = ft_strtrim(infos->map[*i], " ");
		j = 3;
		ft_skipspace(infos, &j, *i);
		if (!ft_strncmp(infos->map[*i], "NO ", 3))
		{
			infos->no_text = ft_strdup(&infos->map[*i][j]);
			infos->north = 1;
		}
		if (!ft_strncmp(infos->map[*i], "SO ", 3))
		{
			infos->so_text = ft_strdup(&infos->map[*i][j]);
			infos->south = 1;
		}
		if (!ft_strncmp(infos->map[*i], "EA ", 3))
		{
			infos->ea_text = ft_strdup(&infos->map[*i][j]);
			infos->east = 1;
		}
		if (!ft_strncmp(infos->map[*i], "WE ", 3))
		{
			infos->we_text = ft_strdup(&infos->map[*i][j]);
			infos->west = 1;
		}
		if (!ft_strncmp(infos->map[*i], "F ", 2))
		{
			j = 2;
			ft_skipspace(infos, &j, *i);
			if (!check_comma(infos, j, *i))
				printf("Invalid color!!\n");
			infos->ceiling = 1;
		}
		if (!ft_strncmp(infos->map[*i], "C ", 2))
		{
			j = 2;
			ft_skipspace(infos, &j, *i);
			if (!check_comma(infos, j, *i))
				printf("Invalid color11!!\n");
			infos->floor = 1;
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
	while (infos->map1[i])
	{
		j = 0;
		while (infos->map1[i][j])
		{
			// if (infos->map1[i][j] == '0' && (infos->map1[i - 1][j] == ' '|| infos->map1[i + 1][j] == '\0'))
			// {
			// 	printf("error11!!\n");
			// 	return (0);
			// }
			// if (infos->map1[i][j] == '0' && (infos->map1[i][j - 1] == ' ' || infos->map1[i][j + 1] == ' '))
			// {

			// 	printf("error!!\n");
			// 	return (0);
			// }
			// if (infos->map1[i][j] == 'N' && (infos->map1[i - 1][j] == ' '|| infos->map1[i + 1][j] == '\0'))
			// {
			// 	printf("error22!!\n");
			// 	return (0);
			// }
			j++;
		}
		i++;
	}
	return (1);
}