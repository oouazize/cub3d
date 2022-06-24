/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:23 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/23 19:11:01 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char *dst;

	if (y > WIN_HEIGHT)
		y = WIN_HEIGHT;
	if (x > WIN_WIDTH)
		x = WIN_WIDTH;
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

void draw_map(t_info *infos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (infos->map1[i])
	{
		j = 0;
		while (infos->map1[i][j])
		{
			if (infos->map1[i][j] == '1')
				draw_map1(infos, i * 32, j * 32, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(infos->mlx, infos->win, infos->img, 0, 0);
}

void draw_player(t_info *infos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (infos->map1[i])
	{
		j = 0;
		while (infos->map1[i][j])
		{
			if (infos->map1[i][j] == 'N')
			{
				if (!infos->y && !infos->x)
				{
					infos->y = i * 32;
					infos->x = j * 32;
				}
				infos->play = mlx_xpm_file_to_image(infos->mlx, "image.xpm", &(infos->width), &(infos->height));
			}
			j++;
		}
		i++;
	}
}

void init(t_info *infos)
{
	infos->north = 0;
	infos->east = 0;
	infos->west = 0;
	infos->south = 0;
	infos->ceiling = 0;
	infos->floor = 0;
	infos->mlx = mlx_init();
	infos->win = mlx_new_window(infos->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	infos->img = mlx_new_image(infos->mlx, WIN_WIDTH, WIN_HEIGHT);
	infos->no_text = mlx_xpm_file_to_image(infos->mlx, infos->no_text, &(infos->width), &(infos->height));
	infos->so_text = mlx_xpm_file_to_image(infos->mlx, infos->so_text, &(infos->width), &(infos->height));
	infos->we_text = mlx_xpm_file_to_image(infos->mlx, infos->we_text, &(infos->width), &(infos->height));
	infos->ea_text = mlx_xpm_file_to_image(infos->mlx, infos->ea_text, &(infos->width), &(infos->height));
	infos->addr = mlx_get_data_addr(infos->img, &infos->bpp, &infos->size_l, &infos->endian);
}