/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <mmounib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:50:51 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/11 12:42:28 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(char *arv, t_data *data)
{
	int		fd;
	int		ret;
	int		check;
	char	**spl;
	char	*save;

	fd = open(arv, O_RDONLY);
	//invalidpath(fd, arv);
	save = ft_strdup("", data);
	data->buff = (char *)malloc(sizeof(char) * 1000001);
	if (data->buff == NULL)
		return (0);
	ret = read(fd, data->buff, 1000000);
	if (ret == -1)
		return (0);
	save = ft_strjoin(save, data->buff, data);
	spl = ft_split(save, '\n', data);
	check = check_map(spl);
	if (check)
	{
		printf("Hint: The map is invalid!\n");
		exit (0);
	}
	return (spl);
}
