/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:23 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 16:46:59 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || x < 0 || y >= WIN_HEIGHT || x >= WIN_WIDTH)
		return ;
	dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_player(t_info *infos, int i)
{
	int	j;

	while (infos->map->map1[++i])
	{
		j = -1;
		while (infos->map->map1[i][++j])
		{
			if (infos->map->map1[i][j] == infos->mathi->playerdir)
			{
				if (!infos->y && !infos->x)
				{
					infos->y = i * 64;
					infos->x = j * 64;
				}
				infos->play = mlx_xpm_file_to_image(infos->mlx,
						"./textures/image.xpm",
						&(infos->width), &(infos->height));
				if (infos->play == NULL)
				{
					printf("There Is No Texture In This Path!!\n");
					exit(0);
				}
			}
		}
	}
}

void	draw_rays(t_info *infos)
{
	double	pa;
	int		x;
	int		d;
	double	h;

	x = -1;
	pa = infos->mathi->angle - 33;
	d = WIN_WIDTH / 60;
	h = (double)1 / d;
	while (pa < infos->mathi->angle + 33 && ++x < WIN_WIDTH)
	{
		infos->mathi->pos_x = infos->x;
		infos->mathi->pos_y = infos->y;
		infos->mathi->point_x = (infos->x + (10000000 * cos(pa * PI / 180)));
		infos->mathi->point_y = (infos->y + (10000000 * sin(pa * PI / 180)));
		infos->dda->dx = infos->mathi->point_x - infos->mathi->pos_x;
		infos->dda->dy = infos->mathi->point_y - infos->mathi->pos_y;
		dda(pa, x, -1, infos);
		pa += h;
	}
	mlx_put_image_to_window(infos->mlx, infos->win, infos->img, 0, 0);
}

int	get_addr(t_info *data, int y, int x, int flag)
{
	char	*dst;

	dst = NULL;
	x = x % 64;
	y = y % 64;
	if (flag == 4 || flag == 0)
		dst = data->addr4 + (y * data->size_l1 + x * (data->bpp1 / 8));
	else if (flag == 3)
		dst = data->addr3 + (y * data->size_l1 + x * (data->bpp1 / 8));
	else if (flag == 2)
		dst = data->addr2 + (y * data->size_l1 + x * (data->bpp1 / 8));
	else if (flag == 1)
		dst = data->addr1 + (y * data->size_l1 + x * (data->bpp1 / 8));
	return (*(unsigned int *)dst);
}
