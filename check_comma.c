/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:19:55 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 19:57:51 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_err(t_info *infos, char ***color, int side, int k)
{
	while ((*color)[++k])
		free((*color)[k]);
	free(*color);
	if (side)
	{
		if (infos->map->red1 > 255 || infos->map->red1 < 0
			|| infos->map->green1 < 0
			|| infos->map->green1 > 255 || infos->map->blue1 < 0
			|| infos->map->blue1 > 255)
		{
			printf("Error!! You Exceeded The range [0,255]\n");
			exit(0);
		}
	}
	else
	{
		if (infos->map->red > 255 || infos->map->red < 0
			|| infos->map->green < 0
			|| infos->map->green > 255 || infos->map->blue < 0
			|| infos->map->blue > 255)
		{
			printf("Error!! You Exceeded The range [0,255]\n");
			exit(0);
		}
	}
}

int	check_char(char **color, char *str)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (ft_isalpha(color[i]) || ft_isascii(color[i]))
		{
			printf("%s\n", str);
			exit(0);
		}
		i++;
	}
	return (0);
}

int	check_comma(t_info *infos, int j, int i)
{
	int		count;
	char	**color;

	count = 0;
	color = ft_split(&infos->map->map[i][j], ',');
	while (infos->map->map[i][j])
	{
		if (infos->map->map[i][j] == ',')
			count++;
		j++;
	}
	if (count != 2)
		return (0);
	check_char(color, "Invalid Color Number In Floor!!");
	if (!ft_isdigit1(color[0]) || !ft_isdigit1(color[1])
		|| !ft_isdigit1(color[2]))
		return (0);
	infos->map->red = ft_atoi(color[0]);
	infos->map->green = ft_atoi(color[1]);
	infos->map->blue = ft_atoi(color[2]);
	free_err(infos, &color, 0, -1);
	return (1);
}

int	check_comma1(t_info *infos, int j, int i)
{
	int		count;
	char	**color;

	count = 0;
	color = ft_split(&infos->map->map[i][j], ',');
	while (infos->map->map[i][j])
	{
		if (infos->map->map[i][j] == ',')
			count++;
		j++;
	}
	if (count != 2)
		return (0);
	check_char(color, "Invalid Color Number In Ceiling!!");
	if (!ft_isdigit1(color[0]) || !ft_isdigit1(color[1])
		|| !ft_isdigit1(color[2]))
		return (0);
	infos->map->red1 = ft_atoi(color[0]);
	infos->map->green1 = ft_atoi(color[1]);
	infos->map->blue1 = ft_atoi(color[2]);
	free_err(infos, &color, 1, -1);
	return (1);
}
