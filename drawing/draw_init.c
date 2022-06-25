/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:23 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/25 20:00:34 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char *dst;

	if (y < 0 || x < 0 || y >= WIN_HEIGHT || x >= WIN_WIDTH)
		return;
	dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_map1(t_info *infos, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			my_mlx_pixel_put(infos, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

void draw_player(t_info *infos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (infos->map->map1[i])
	{
		j = 0;
		while (infos->map->map1[i][j])
		{
			if (infos->map->map1[i][j] == 'N')
			{
				if (!infos->y && !infos->x)
				{
					infos->y = i * 32;
					infos->x = j * 32;
				}
				infos->play = mlx_xpm_file_to_image(infos->mlx, "./textures/image.xpm", &(infos->width), &(infos->height));
			}
			j++;
		}
		i++;
	}
}

void init(t_info *infos)
{
	infos->map = malloc(sizeof(t_map));
	infos->mathi = malloc(sizeof(t_mathi));
	infos->map->north = 0;
	infos->map->east = 0;
	infos->map->west = 0;
	infos->map->south = 0;
	infos->map->ceiling = 0;
	infos->map->floor = 0;
	infos->flag = 0;
	infos->flag1 = 0;
	infos->map->rgb = 0;
	infos->mlx = mlx_init();
	infos->win = mlx_new_window(infos->mlx, WIN_WIDTH, WIN_HEIGHT, "OZ Game");
	infos->img = mlx_new_image(infos->mlx, WIN_WIDTH, WIN_HEIGHT);
	infos->addr = mlx_get_data_addr(infos->img, &infos->bpp,
									&infos->size_l, &infos->endian);
}

void init2(t_info *infos)
{
	infos->map->no_text = mlx_xpm_file_to_image(infos->mlx, infos->map->no_text,
												&(infos->width), &(infos->height));
	infos->map->so_text = mlx_xpm_file_to_image(infos->mlx, infos->map->so_text,
												&(infos->width), &(infos->height));
	infos->map->we_text = mlx_xpm_file_to_image(infos->mlx, infos->map->we_text,
												&(infos->width), &(infos->height));
	infos->map->ea_text = mlx_xpm_file_to_image(infos->mlx, infos->map->ea_text,
												&(infos->width), &(infos->height));
	infos->addr1 = mlx_get_data_addr(infos->map->no_text, &infos->bpp1,
									 &infos->size_l1, &infos->endian1);
	infos->addr2 = mlx_get_data_addr(infos->map->so_text, &infos->bpp1,
									 &infos->size_l1, &infos->endian1);
	infos->addr3 = mlx_get_data_addr(infos->map->we_text, &infos->bpp1,
									 &infos->size_l1, &infos->endian1);
	infos->addr4 = mlx_get_data_addr(infos->map->ea_text, &infos->bpp1,
									 &infos->size_l1, &infos->endian1);
}