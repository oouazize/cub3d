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

char	**ft_getmap(t_info *infos, char *argv)
{
	char	*line;
	char	*temp;
	char	**map;

	check(infos->map->fd, 0, 0, 0);
	temp = ft_strdup("");
	infos->map->fd = open(argv, O_RDONLY, 0777);
	line = get_next_line(infos->map->fd);
	while (line)
	{
		temp = ft_strjoin(temp, line);
		free(line);
		line = get_next_line(infos->map->fd);
	}
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

void	checkmap2(t_info *infos, int *i, int *count, int j)
{
	if (!ft_strncmp(infos->map->map[*i], "SO ", 3))
	{
		j = 3;
		ft_skipspace(infos, &j, *i);
		(*count)++;
		infos->map->so_text = ft_strdup(&infos->map->map[*i][j]);
		infos->map->south = 1;
	}
	if (!ft_strncmp(infos->map->map[*i], "EA ", 3))
	{
		j = 3;
		ft_skipspace(infos, &j, *i);
		(*count)++;
		infos->map->ea_text = ft_strdup(&infos->map->map[*i][j]);
		infos->map->east = 1;
	}
	if (!ft_strncmp(infos->map->map[*i], "WE ", 3))
	{
		j = 3;
		ft_skipspace(infos, &j, *i);
		(*count)++;
		infos->map->we_text = ft_strdup(&infos->map->map[*i][j]);
		infos->map->west = 1;
	}
}

void	checkmap3(t_info *infos, int *i, int *count, int j)
{
	if (!ft_strncmp(infos->map->map[*i], "F ", 2))
	{
		(*count)++;
		j = 2;
		ft_skipspace(infos, &j, *i);
		if (!check_comma(infos, j, *i))
			ft_perror();
		infos->map->ceiling = 1;
	}
	if (!ft_strncmp(infos->map->map[*i], "C ", 2))
	{
		(*count)++;
		j = 2;
		ft_skipspace(infos, &j, *i);
		if (!check_comma1(infos, j, *i))
			ft_perror();
		infos->map->floor = 1;
	}
}

void	calc_length(t_info *infos, int *count, char *argv)
{
	int	i;

	(*count) = 0;
	infos->map->map = ft_getmap(infos, argv);
	infos->map->map_length = (int)ft_strlen(infos->map->map[0]);
	i = 1;
	while (infos->map->map[i])
	{
		if (infos->map->map_length < (int)ft_strlen(infos->map->map[i]))
			infos->map->map_length = (int)ft_strlen(infos->map->map[i]);
		i++;
	}
}

void	checkmap1(t_info *infos, int *i, int j, char *argv)
{
	int	count;

	calc_length(infos, &count, argv);
	while (infos->map->map[++(*i)])
	{
		infos->map->map[*i] = ft_strtrim(infos->map->map[*i], " ");
		if (!ft_strncmp(infos->map->map[*i], "NO ", 3))
		{
			j = 3;
			ft_skipspace(infos, &j, *i);
			count++;
			infos->map->no_text = ft_strdup(&infos->map->map[*i][j]);
			infos->map->north = 1;
		}
		checkmap2(infos, i, &count, j);
		checkmap3(infos, i, &count, j);
		if (count == 6)
			break ;
	}
	if (!infos->map->south || !infos->map->east || !infos->map->west
		|| !infos->map->north || !infos->map->ceiling || !infos->map->floor)
		ft_perror();
	infos->map->rgb = (infos->map->red << 16) | (infos->map->green << 8)
		| (infos->map->blue << 0);
	init2(infos);
}
