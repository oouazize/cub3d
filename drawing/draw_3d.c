/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:52:36 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 20:04:48 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_3d(int x, int y, t_info *infos)
{
	infos->mathi->wall_h = infos->mathi->ceilling1 + infos->mathi->wall_h;
	while (y <= infos->mathi->ceilling1)
	{
		my_mlx_pixel_put(infos, x, y, infos->map->rgb1);
		y++;
	}
	while (y < infos->mathi->wall_h && y < WIN_HEIGHT)
	{
		if (infos->dda->flag == 3 || infos->dda->flag == 4)
			infos->dda->b = fmod(infos->dda->ypos / 64, 1);
		else
			infos->dda->b = fmod(infos->dda->xpos / 64, 1);
		infos->dda->color = get_addr(infos, ((y - (infos->mathi->ceilling1))
					/ (infos->mathi->wall_h - infos->mathi->ceilling1))
				* 64, infos->dda->b * 64, infos->dda->flag);
		my_mlx_pixel_put(infos, x, y, infos->dda->color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(infos, x, y, infos->map->rgb);
		y++;
	}
}

void	calculate_dist(double pa, t_info *infos)
{
	if (infos->map->map1[(int)round(infos->dda->ypos) / 64]
		[(int)(round(infos->dda->xpos - infos->dda->xinc) / 64)] != '1')
	{
		if (infos->dda->xinc > 0)
			infos->dda->flag = 4;
		else
			infos->dda->flag = 3;
	}
	else if (infos->map->map1[(int)round
			(infos->dda->ypos - infos->dda->yinc) / 64]
		[(int)(round(infos->dda->xpos) / 64)] != '1')
	{
		if (infos->dda->yinc > 0)
			infos->dda->flag = 2;
		else
			infos->dda->flag = 1;
	}
	infos->dda->x1 = (infos->x) - ((int)round(infos->dda->xpos));
	infos->dda->y1 = (infos->y) - ((int)round(infos->dda->ypos));
	infos->mathi->distance_plane = (WIN_WIDTH / 2) / tan(33 * PI / 180);
	infos->mathi->distance_wall = cos((pa - infos->mathi->angle) * PI / 180)
		* sqrt(pow(infos->dda->x1, 2) + pow(infos->dda->y1, 2));
	infos->mathi->wall_h = 64 / infos->mathi->distance_wall
		* fabs(infos->mathi->distance_plane);
	infos->mathi->ceilling1 = (WIN_HEIGHT / 2) - (infos->mathi->wall_h / 2);
}

void	dda(double pa, int x, int i, t_info *infos)
{
	if (abs(infos->dda->dx) > abs(infos->dda->dy))
		infos->dda->steps = abs(infos->dda->dx);
	else
		infos->dda->steps = abs(infos->dda->dy);
	infos->dda->xinc = infos->dda->dx / (float)(infos->dda->steps);
	infos->dda->yinc = infos->dda->dy / (float)(infos->dda->steps);
	infos->dda->xpos = infos->mathi->pos_x;
	infos->dda->ypos = infos->mathi->pos_y;
	while (++i <= infos->dda->steps)
	{
		if (!infos->map->map1[(int)round(infos->dda->ypos) / 64]
			[(int)round(infos->dda->xpos) / 64]
			|| infos->map->map1[(int)round(infos->dda->ypos)
				/ 64][(int)round(infos->dda->xpos) / 64] == '1'
			|| infos->map->map1[(int)round(infos->dda->ypos)
				/ 64][(int)round(infos->dda->xpos) / 64] == ' ')
		{
			calculate_dist(pa, infos);
			draw_3d(x, 0, infos);
			break ;
		}
		infos->dda->xpos += infos->dda->xinc;
		infos->dda->ypos += infos->dda->yinc;
	}
}
