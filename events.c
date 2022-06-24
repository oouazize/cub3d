/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:36 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/24 11:06:43 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_angle(t_info **infos, int side)
{
	if (side > 0)
	{
		(*infos)->angle += 5;
		if ((*infos)->angle < 0)
			(*infos)->angle += 360;
		(*infos)->delta_x = cos((*infos)->angle * PI / 180) * 10;
		(*infos)->delta_y = sin((*infos)->angle * PI / 180) * 10;
	}
	else
	{
		(*infos)->angle -= 5;
		if ((*infos)->angle > 360)
			(*infos)->angle -= 360;
		(*infos)->delta_x = cos((*infos)->angle * PI / 180) * 10;
		(*infos)->delta_y = sin((*infos)->angle * PI / 180) * 10;
	}
}

void	event_right(t_info **infos, int keysym)
{
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
		rotate_angle(infos, 5);
	black_window(infos);
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}

void	event_left(t_info **infos, int keysym)
{
	(*infos)->flag = 0;
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
		rotate_angle(infos, -5);
	black_window(infos);
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}

void	event_up(t_info **infos)
{
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
	black_window(infos);
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}

void	event_down(t_info **infos)
{
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
	mlx_put_image_to_window((*infos)->mlx, (*infos)->win, (*infos)->play, (*infos)->x, (*infos)->y);
	black_window(infos);
	mlx_clear_window((*infos)->mlx, (*infos)->win);
	draw_map(*infos);
	draw_rays(*infos);
}
