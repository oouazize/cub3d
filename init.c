/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:28:52 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 18:31:29 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_info *infos, char **argv)
{
	infos->mathi = malloc(sizeof(t_mathi));
	infos->map->north = 0;
	infos->map->east = 0;
	infos->map->west = 0;
	infos->map->south = 0;
	infos->map->ceiling = 0;
	infos->map->floor = 0;
	infos->flag = 0;
	infos->flag1 = 0;
	infos->map->map_length = 0;
	infos->map->rgb = 0;
	infos->mlx = mlx_init();
	infos->win = mlx_new_window(infos->mlx, WIN_WIDTH, WIN_HEIGHT, "OZ Game");
	infos->img = mlx_new_image(infos->mlx, WIN_WIDTH, WIN_HEIGHT);
	infos->addr = mlx_get_data_addr(infos->img, &infos->bpp,
			&infos->size_l, &infos->endian);
	infos->map->fd = open(argv[1], O_RDONLY, 0777);
	infos->i = 0;
	infos->j = 0;
	infos->x = 0;
	infos->y = 0;
	infos->mathi->delta_x = 5;
	infos->mathi->delta_y = 0;
	infos->mathi->angle = 0;
	infos->dda->flag = 0;
}

void	path_error(t_info *infos, char *str, char **tmp, int key)
{
	free(*tmp);
	if (!str)
	{
		printf("There Is No Texture In This Path!!\n");
		exit(0);
	}
	if (infos->width != 64 || infos->height != 64)
	{
		printf("Error!!\n");
		exit(0);
	}
	if (key == 2)
		*tmp = infos->map->so_text;
	else if (key == 3)
		*tmp = infos->map->we_text;
	else if (key == 4)
		*tmp = infos->map->ea_text;
}

void	init2(t_info *infos)
{
	char	*tmp;

	infos->map->rgb1 = (infos->map->red1 << 16) | (infos->map->green1 << 8)
		| (infos->map->blue1 << 0);
	tmp = infos->map->no_text;
	infos->map->no_text = mlx_xpm_file_to_image(infos->mlx, infos->map->no_text,
			&(infos->width), &(infos->height));
	path_error(infos, infos->map->no_text, &tmp, 2);
	infos->map->so_text = mlx_xpm_file_to_image(infos->mlx, infos->map->so_text,
			&(infos->width), &(infos->height));
	path_error(infos, infos->map->so_text, &tmp, 3);
	infos->map->we_text = mlx_xpm_file_to_image(infos->mlx, infos->map->we_text,
			&(infos->width), &(infos->height));
	path_error(infos, infos->map->we_text, &tmp, 4);
	infos->map->ea_text = mlx_xpm_file_to_image(infos->mlx, infos->map->ea_text,
			&(infos->width), &(infos->height));
	path_error(infos, infos->map->ea_text, &tmp, 0);
	infos->addr1 = mlx_get_data_addr(infos->map->no_text, &infos->bpp1,
			&infos->size_l1, &infos->endian1);
	infos->addr2 = mlx_get_data_addr(infos->map->so_text, &infos->bpp1,
			&infos->size_l1, &infos->endian1);
	infos->addr3 = mlx_get_data_addr(infos->map->we_text, &infos->bpp1,
			&infos->size_l1, &infos->endian1);
	infos->addr4 = mlx_get_data_addr(infos->map->ea_text, &infos->bpp1,
			&infos->size_l1, &infos->endian1);
}
