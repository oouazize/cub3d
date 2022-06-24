/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:36 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/24 10:49:00 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void event_right(t_info **infos, int keysym)
{
	int i;
	int j;
	i = -1;
	(*infos)->flag1 = 0;
	if (keysym == 2)
	{
		if ((*infos)->flag)
			return ;
		(*infos)->angle += 90;
		if ((*infos)->angle < 0)
			(*infos)->angle += 360;
		(*infos)->y += sin((*infos)->angle * PI / 180) * 10;
		(*infos)->x += cos((*infos)->angle * PI / 180) * 10;
		(*infos)->angle -= 90;
		if ((*infos)->map1[(*infos)->y / 32][(*infos)->x / 32] == '1')
		{
			(*infos)->y -= sin(((*infos)->angle + 90) * PI / 180) * 10;
			(*infos)->x -= cos(((*infos)->angle + 90) * PI / 180) * 10;
			(*infos)->flag = 1;
			return ;
		}
	}
	else
	{
		(*infos)->angle += 5;
		if ((*infos)->angle < 0)
			(*infos)->angle += 360;
		(*infos)->delta_x = cos((*infos)->angle * PI / 180) * 10;
		(*infos)->delta_y = sin((*infos)->angle * PI / 180) * 10;
	}
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			my_mlx_pixel_put(*infos, j, i, 0x000000);
	}
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}

void event_left(t_info **infos, int keysym)
{
	int i;
	int j;

	(*infos)->flag = 0;
	i = -1;
	if (keysym == 0)
	{
		if ((*infos)->flag1)
			return ;
		(*infos)->angle -= 90;
		if ((*infos)->angle > 360)
			(*infos)->angle -= 360;
		(*infos)->y += sin((*infos)->angle * PI / 180) * 10;
		(*infos)->x += cos((*infos)->angle * PI / 180) * 10;
		(*infos)->angle += 90;
		if ((*infos)->map1[(*infos)->y / 32][(*infos)->x / 32] == '1')
		{
			(*infos)->y -= sin(((*infos)->angle - 90) * PI / 180) * 10;
			(*infos)->x -= cos(((*infos)->angle - 90) * PI / 180) * 10;
			(*infos)->flag1 = 1;
			return ;
		}
	}
	else
	{
		(*infos)->angle -= 5;
		if ((*infos)->angle > 360)
			(*infos)->angle -= 360;
		(*infos)->delta_x = cos((*infos)->angle * PI / 180) * 10;
		(*infos)->delta_y = sin((*infos)->angle * PI / 180) * 10;
	}
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			my_mlx_pixel_put(*infos, j, i, 0x000000);
	}
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}

void event_up(t_info **infos)
{
	int i;
	int j;

	i = -1;
	(*infos)->flag = 0;
	(*infos)->flag1 = 0;
	(*infos)->delta_x = cos((*infos)->angle * PI / 180) * 10;
	(*infos)->delta_y = sin((*infos)->angle * PI / 180) * 10;
	(*infos)->y += (*infos)->delta_y;
	(*infos)->x += (*infos)->delta_x;
	if ((*infos)->map1[(*infos)->y / 32][(*infos)->x / 32] == '1')
	{
		(*infos)->y -= (*infos)->delta_y;
		(*infos)->x -= (*infos)->delta_x;
		return ;
	}
	mlx_put_image_to_window((*infos)->mlx, (*infos)->win, (*infos)->play, (*infos)->x, (*infos)->y);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			my_mlx_pixel_put(*infos, j, i, 0x000000);
	}
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}

void event_down(t_info **infos)
{
	int i;
	int j;

	(*infos)->flag = 0;
	(*infos)->flag1 = 0;
	(*infos)->delta_x = cos((*infos)->angle * PI / 180) * 10;
	(*infos)->delta_y = sin((*infos)->angle * PI / 180) * 10;
	(*infos)->y -= (*infos)->delta_y;
	(*infos)->x -= (*infos)->delta_x;
	if ((*infos)->map1[(*infos)->y / 32][(*infos)->x / 32] == '1')
	{
		(*infos)->y += (*infos)->delta_y;
		(*infos)->x += (*infos)->delta_x;
		return ;
	}
	i = -1;
	mlx_put_image_to_window((*infos)->mlx, (*infos)->win, (*infos)->play, (*infos)->x, (*infos)->y);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			my_mlx_pixel_put(*infos, j, i, 0x000000);
	}
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}