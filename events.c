/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:36 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/23 18:49:29 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void event_right(t_info **infos, int keysym)
{
	int i;
	int j;
	i = -1;
	if (keysym == 2)
	{
		(*infos)->angle += 90;
		if ((*infos)->angle < 0)
			(*infos)->angle += 360;
		(*infos)->y += sin((*infos)->angle * PI / 180) * 10;
		(*infos)->x += cos((*infos)->angle * PI / 180) * 10;
		if ((*infos)->map1[(*infos)->y / 32][(*infos)->x / 32] == '1')
		{
			(*infos)->y -= sin((*infos)->angle * PI / 180) * 10;
			(*infos)->x -= cos((*infos)->angle * PI / 180) * 10;
			(*infos)->angle -= 90;
			return ;
		}
		(*infos)->angle -= 90;
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

	i = -1;
	if (keysym == 0)
	{
		(*infos)->angle -= 90;
		if ((*infos)->angle > 360)
			(*infos)->angle -= 360;
		(*infos)->y += sin((*infos)->angle * PI / 180) * 10;
		(*infos)->x += cos((*infos)->angle * PI / 180) * 10;
		if ((*infos)->map1[(*infos)->y / 32][(*infos)->x / 32] == '1')
		{
			(*infos)->y -= sin((*infos)->angle * PI / 180) * 10;
			(*infos)->x -= cos((*infos)->angle * PI / 180) * 10;
			(*infos)->angle += 90;
			return ;
		}
		(*infos)->angle += 90;
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