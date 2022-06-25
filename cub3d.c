/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <mmounib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:20:06 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/25 14:56:54 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line1(t_info *info)
{
	int i;

	i = -1;
	while (info->map1[0][++i])
		if (info->map1[0][i] != '1')
			return (0);
	return (1);
}

int	get_addr(t_info *data, int y, int x)
{
	char	*dst = NULL;
	
	x = x % 64;
	y = y % 64;
	dst = data->addr1 + (y * data->size_l1 + x * (data->bpp1 / 8));
	return (*(unsigned int *)dst);
}

void	dda(double pa, int x, int X0, int Y0, int X1, int Y1, t_info *infos)
{
	int y = 0;
	int color;
	//int *col = NULL;
	int flag = 0;
	// x = 0;
	int dx = X1 - X0;
	int dy = Y1 - Y0;
	int steps;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		if (infos->map1[(int)round(Y) / 32][(int)round(X) / 32] == '1')
		{
			if (infos->map1[(int)round(Y) / 32][(int)(round(X - Xinc) / 32)] != '1')
			{
				if (Xinc > 0)
				{
					flag = 1;
					//color = 0x000000;
					//color = get_addr(infos, fmod(round(Y) / 32, 1), fmod(round(X) / 32, 1));
					// exit(0);
				}
				else
					color = 0x0000FF;
			}
			else if (infos->map1[(int)round(Y - Yinc) / 32][(int)(round(X) / 32)] != '1')
			{
				if (Yinc > 0)
					color = 0x00FF00;
				else
					color = 0xFF0000;
			}
			double X1 = (infos->x) - ((int)round(X));
			double Y1 = (infos->y) - ((int)round(Y));
			infos->distance_plane = (WIN_WIDTH / 2) / tan(33 * PI / 180);
			infos->distance_wall = cos((pa - infos->angle) * PI / 180) * sqrt(pow(X1, 2) + pow(Y1, 2));
			infos->wall_h = 32 / (cos((pa - infos->angle) * PI / 180) * sqrt(pow(X1, 2) + pow(Y1, 2))) * fabs(infos->distance_plane);
			infos->floor1 = (WIN_HEIGHT / 2) - (infos->wall_h / 2);
			infos->wall_h = infos->floor1 + infos->wall_h;
			while (y <= infos->floor1)
			{
				my_mlx_pixel_put(infos, x, y, 0xCCFFFF);
				y++;
			}
			if (infos->wall_h > WIN_HEIGHT)
				infos->wall_h = WIN_HEIGHT;
			while (y < infos->wall_h)
			{
				float a = ((y - (infos->floor1)) / (infos->wall_h - infos->floor1));
				float b = fmod(Y / 32, 1);
				// if (y % 2)
				// 	printf ("i : %f\n", b);
				color = get_addr(infos, a * 64,b * 64);
				my_mlx_pixel_put(infos, x, y, color);
				y++;
			}
			while (y < WIN_HEIGHT)
			{
				my_mlx_pixel_put(infos, x, y, 0xE6ECF3);
				y++;
			}
			break;
		}
		// my_mlx_pixel_put(infos, round(X), round(Y), 0xFFFF00);
		X += Xinc;
		Y += Yinc;
	}
}

char	 **ft_getmap(t_info *infos)
{
	char	*line;
	char	*temp;
	char	**map;

	temp = ft_strdup("");
	line = get_next_line(infos->fd);
	while (line)
	{
		temp = ft_strjoin(temp, line);
		free(line);
		line = get_next_line(infos->fd);
	}
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

void	ft_skipspace(t_info *infos, int *j, int i)
{
	while (infos->map[i][*j] == 32)
		(*j)++;
}

void	draw_rays(t_info *infos)
{
	double	pa;
	int		x;

	x = -1;
	pa = infos->angle - 33;

	while (pa < infos->angle + 33 && ++x < WIN_WIDTH)
	{
		dda(pa, x, infos->x, infos->y, (infos->x + (100000 * cos(pa * PI / 180))),
			(infos->y + (100000 * sin(pa * PI / 180))), infos);
		pa += 0.0416666667;
	}
	mlx_put_image_to_window(infos->mlx, infos->win, infos->img, 0, 0);
	// mlx_put_image_to_window(infos->mlx, infos->win, infos->play, infos->x - 17, infos->y - 17);
}

void	replace_map(t_info *infos, int i)
{
	int x;
	int c;

	x = i;
	infos->maplen = 0;
	while (infos->map[++i])
	{
		// infos->map[i] = ft_strtrim(infos->map[i], " ");
		infos->maplen++;
	}
	infos->map1 = malloc(sizeof(char *) * (infos->maplen + 1));
	c = 0;
	while (infos->map[++x])
	{
		infos->map1[c] = infos->map[x];
		c++;
	}
	infos->map1[c] = NULL;
}

int	handle_input(int keysym, t_info *infos)
{
	if (keysym == 53)
	{
		printf("Game Over\n");
		exit(0);
	}
	if (keysym == 2 || keysym == 124)
		event_right(&infos, keysym);
	else if (keysym == 0 || keysym == 123)
		event_left(&infos, keysym);
	else if (keysym == 1 || keysym == 125)
		event_down(&infos);
	else if (keysym == 13 || keysym == 126)
		event_up(&infos);
	return (0);
}

int	closed(void)
{
	printf("Game Over\n");
	exit(0);
}

void	intt(t_info *infos)
{
	mlx_hook(infos->win, 17, 1L << 17, &closed, infos);
	mlx_hook(infos->win, 2, 1L << 0, &handle_input, infos);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;
	int		rgb;

	if (argc > 2)
		return (0);
	init(&info);
	intt(&info);
	info.fd = open(argv[1], O_RDONLY, 0777);
	info.i = 0;
	info.j = 0;
	info.delta_x = 5;
	info.delta_y = 0;
	info.angle = 0;
	if (info.fd < 0 || !ft_strstr(argv[1], ".cub"))
		printf("error in the extension!!\n");
	i = 0;
	rgb = (info.red << 16) | (info.green << 8) | (info.blue << 0);
	checkmap1(&info, &i);
	init2(&info);
	replace_map(&info, i);
	if (!checkmap(&info))
		return (0);
	if (!info.south && !info.east && !info.west && !info.north && !info.ceiling && !info.floor)
		printf("Wrong element!!\n");
	draw_map(&info);
	draw_player(&info);
	draw_rays(&info);
	mlx_loop(info.mlx);
}