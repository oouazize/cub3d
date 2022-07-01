/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:11:18 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/29 11:57:44 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_player(void)
{
	printf("Error In Map Variables!!\n");
	exit(0);
}

void	check_player2(t_info *infos, int *flag, int i, int j)
{
	if (*flag)
	{
		printf("Error In Map Variables!!\n");
		exit (0);
	}
	*flag = 1;
	infos->mathi->playerdir = infos->map->map1[i][j];
}

void	check_player(t_info *infos, int flag)
{
	int	i;
	int	j;

	i = -1;
	while (infos->map->map1[++i])
	{
		j = -1;
		while (infos->map->map1[i][++j])
		{
			if (infos->map->map1[i][j] == 'N')
				check_player2(infos, &flag, i, j);
			else if (infos->map->map1[i][j] == 'S')
				check_player2(infos, &flag, i, j);
			else if (infos->map->map1[i][j] == 'W')
				check_player2(infos, &flag, i, j);
			else if (infos->map->map1[i][j] == 'E')
				check_player2(infos, &flag, i, j);
			else if (infos->map->map1[i][j] != 48
					&& infos->map->map1[i][j] != 49
					&& infos->map->map1[i][j] != 32)
				error_player();
		}
	}
	if (!flag)
		error_player();
}
