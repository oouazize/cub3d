/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:20:06 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 18:31:12 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ret(int keysym, t_info *infos)
{
	if (keysym == 2)
	{
		if (infos->flag1)
			return (1);
	}
	if (keysym == 0)
	{
		if (infos->flag)
			return (1);
	}
	return (0);
}

int	handle_input(int keysym, t_info *infos)
{
	if (keysym == 53)
	{
		printf("Game Over\n");
		exit(0);
	}
	if (keysym == 2 || keysym == 124)
	{
		infos->flag1 = 0;
		if (check_ret(keysym, infos))
			return (0);
		event_right(infos, keysym);
	}
	else if (keysym == 0 || keysym == 123)
	{
		infos->flag = 0;
		if (check_ret(keysym, infos))
			return (0);
		event_left(infos, keysym);
	}
	else if (keysym == 1 || keysym == 125)
		event_down(infos);
	else if (keysym == 13 || keysym == 126)
		event_up(infos);
	return (0);
}

int	closed(void)
{
	printf("Game Over\n");
	exit(0);
}

void	put_hook(t_info *infos, char *argv)
{
	mlx_hook(infos->win, 17, 1L << 17, &closed, infos);
	mlx_hook(infos->win, 2, 1L << 0, &handle_input, infos);
	if (infos->map->fd < 0 || !ft_strstr(argv, ".cub"))
	{
		printf("Error in the extension!!\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (argc != 2)
		return (0);
	info.map = malloc(sizeof(t_map));
	info.dda = malloc(sizeof(t_dda));
	init(&info, argv);
	put_hook(&info, argv[1]);
	i = -1;
	checkmap1(&info, &i, 0, argv[1]);
	replace_map(&info, i);
	checkallmap(&info, 0);
	check_player(&info, 0);
	if (info.mathi->playerdir == 'N')
		info.mathi->angle = -90;
	else if (info.mathi->playerdir == 'S')
		info.mathi->angle = 90;
	else if (info.mathi->playerdir == 'W')
		info.mathi->angle = 180;
	else if (info.mathi->playerdir == 'E')
		info.mathi->angle = 0;
	draw_player(&info, -1);
	draw_rays(&info);
	mlx_loop(info.mlx);
}
