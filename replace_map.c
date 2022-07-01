/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:11:08 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 19:11:02 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_first_line(t_info *infos)
{
	int	j;

	j = -1;
	while (infos->map->map1[0][++j])
	{
		if (infos->map->map1[0][j] != '1' && infos->map->map1[0][j] != ' ')
			ft_perror();
	}
}

void	check_middle_map(t_info *infos, int i)
{
	int	j;

	j = -1;
	while (infos->map->map1[i][++j])
	{
		if ((ft_strchr1("0NWES", infos->map->map1[i][j]))
			&& ((infos->map->map1[i][0] != '1' && infos->map->map1[i][0] != ' ')
			| (infos->map->map1[i][ft_strlen(infos->map->map1[i]) - 1] != '1'
			&& infos->map->map1[i][ft_strlen(infos->map->map1[i]) - 1] != ' ')))
			ft_perror();
		if ((ft_strchr1("0NWES", infos->map->map1[i][j]))
			&& (!infos->map->map1[i - 1][j] || !infos->map->map1[i + 1][j]
			|| infos->map->map1[i - 1][j] == ' '
			|| infos->map->map1[i][j + 1] == ' '
			|| infos->map->map1[i][j - 1] == ' '
			|| infos->map->map1[i + 1][j] == ' '))
			ft_perror();
	}
}

void	check_last_line(t_info *infos, int i)
{
	int	j;

	j = -1;
	while (infos->map->map1[i][++j])
	{
		if (infos->map->map1[i][j] != '1' && infos->map->map1[i][j] != ' ')
			ft_perror();
	}
}

void	checkallmap(t_info *infos, int i)
{
	check_first_line(infos);
	while (infos->map->map1[i + 1])
	{
		check_middle_map(infos, i);
		i++;
	}
	check_last_line(infos, i);
}

void	replace_map(t_info *infos, int i)
{
	int	x;
	int	c;
	int	j;

	x = i;
	j = -1;
	infos->map->maplen = 0;
	while (infos->map->map[++i])
		infos->map->maplen++;
	infos->map->map1 = malloc(sizeof(char *) * (infos->map->maplen + 1));
	if (!infos->map->map1)
		exit(0);
	while (++j < infos->map->maplen)
		infos->map->map1[j] = malloc(sizeof(char)
				* (infos->map->map_length + 1));
	c = -1;
	while (++c < infos->map->maplen)
	{
		j = -1;
		while (++j <= infos->map->map_length)
			infos->map->map1[c][j] = 0;
	}
	infos->map->map1[c] = 0;
	add_map(infos, x);
}
