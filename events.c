/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:36 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 16:04:18 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_angle(t_info *infos, int side)
{
	if (side > 0)
	{
		infos->mathi->angle += 10;
		if (infos->mathi->angle < 0)
			infos->mathi->angle += 360;
		infos->mathi->delta_x = cos(infos->mathi->angle * PI / 180) * 10;
		infos->mathi->delta_y = sin(infos->mathi->angle * PI / 180) * 10;
	}
	else
	{
		infos->mathi->angle -= 10;
		if (infos->mathi->angle > 360)
			infos->mathi->angle -= 360;
		infos->mathi->delta_x = cos(infos->mathi->angle * PI / 180) * 10;
		infos->mathi->delta_y = sin(infos->mathi->angle * PI / 180) * 10;
	}
}

void	event_right(t_info *infos, int keysym)
{
	double	x;
	double	y;

	if (keysym == 2)
	{
		infos->mathi->angle += 90;
		if (infos->mathi->angle < 0)
			infos->mathi->angle += 360;
		y = infos->y + sin(infos->mathi->angle * PI / 180) * 10;
		x = infos->x + cos(infos->mathi->angle * PI / 180) * 10;
		infos->mathi->angle -= 90;
		if (!infos->map->map1[infos->y / 64][infos->x / 64]
			|| infos->map->map1[infos->y / 64][infos->x / 64] == ' '
			|| infos->map->map1[(int)y / 64][(int)x / 64] == '1')
		{
			infos->flag1 = 1;
			return ;
		}
		infos->y = y;
		infos->x = x;
	}
	else
		rotate_angle(infos, 5);
	mlx_clear_window(infos->mlx, infos->win);
	draw_rays(infos);
}

void	event_left(t_info *infos, int keysym)
{
	double	y;
	double	x;

	if (keysym == 0)
	{
		infos->mathi->angle -= 90;
		if (infos->mathi->angle > 360)
			infos->mathi->angle -= 360;
		y = infos->y + sin(infos->mathi->angle * PI / 180) * 10;
		x = infos->x + cos(infos->mathi->angle * PI / 180) * 10;
		infos->mathi->angle += 90;
		if (!infos->map->map1[infos->y / 64][infos->x / 64]
			|| infos->map->map1[infos->y / 64][infos->x / 64] == ' '
			|| infos->map->map1[(int)y / 64][(int)x / 64] == '1')
		{
			infos->flag1 = 1;
			return ;
		}
		infos->y = y;
		infos->x = x;
	}
	else
		rotate_angle(infos, -5);
	mlx_clear_window(infos->mlx, infos->win);
	draw_rays(infos);
}

void	event_up(t_info *infos)
{
	infos->flag = 0;
	infos->flag1 = 0;
	infos->mathi->delta_x = cos(infos->mathi->angle * PI / 180) * 15;
	infos->mathi->delta_y = sin(infos->mathi->angle * PI / 180) * 15;
	infos->y += infos->mathi->delta_y;
	infos->x += infos->mathi->delta_x;
	if (!infos->map->map1[infos->y / 64][infos->x / 64]
		|| infos->map->map1[infos->y / 64][infos->x / 64] == ' '
		|| infos->map->map1[infos->y / 64][infos->x / 64] == '1')
	{
		infos->y -= infos->mathi->delta_y;
		infos->x -= infos->mathi->delta_x;
		return ;
	}
	mlx_put_image_to_window(infos->mlx, infos->win,
		infos->play, infos->x, infos->y);
	mlx_clear_window(infos->mlx, infos->win);
	draw_rays(infos);
}

void	event_down(t_info *infos)
{
	infos->flag = 0;
	infos->flag1 = 0;
	infos->mathi->delta_x = cos(infos->mathi->angle * PI / 180) * 15;
	infos->mathi->delta_y = sin(infos->mathi->angle * PI / 180) * 15;
	infos->y -= infos->mathi->delta_y;
	infos->x -= infos->mathi->delta_x;
	if (!infos->map->map1[infos->y / 64][infos->x / 64]
		|| infos->map->map1[infos->y / 64][infos->x / 64] == ' '
		|| infos->map->map1[infos->y / 64][infos->x / 64] == '1')
	{
		infos->y += infos->mathi->delta_y;
		infos->x += infos->mathi->delta_x;
		return ;
	}
	mlx_put_image_to_window(infos->mlx, infos->win,
		infos->play, infos->x, infos->y);
	mlx_clear_window(infos->mlx, infos->win);
	draw_rays(infos);
}
