
#include "cub3d.h"

int	check_line1(t_info *info)
{
	int i;

	i = 0;
	while(info->map1[0][i])
	{
		//printf("---%c----\n", info->map1[0][i]);
		if (info->map1[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}


char **ft_getmap(t_info *infos)
{
	char *line;
	char *temp;
	char **map;

	temp = ft_strdup("");
	line = get_next_line(infos->fd);
	while(line)
	{
		temp = ft_strjoin(temp, line);
		free(line);
		line = get_next_line(infos->fd);
	}
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

void ft_skipspace(t_info *infos, int *j, int i)
{
	while(infos->map[i][*j] == 32)
		(*j)++;
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
	infos->win = mlx_new_window(infos->mlx, 1920, 1080, "CUB3D");
	infos->img = mlx_new_image(infos->mlx, 1920 ,1080);
}

void	draw_map1(t_info *infos, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while(j < 32)
		{
			mlx_pixel_put(infos->mlx, infos->win, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_info *infos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(infos->map1[i])
	{
		j = 0;
		while (infos->map1[i][j])
		{
			if (infos->map1[i][j] == '1')
			{
				draw_map1(infos, i * 32, j * 32, 0xFFFFFF);
			}
			else if (infos->map1[i][j] == 'N')
			{
				draw_map1(infos, i * 32, j * 32, 0x00FFFF);
			}
			j++;
		}
		i++;
	}
}

void replace_map(t_info *infos, int i)
{
	int x;
	int count;
	int c;

	x = i;
	count = 0;
	while (infos->map[++i])
	{
		infos->map[i] = ft_strtrim(infos->map[i], " ");
		count++;
	}
	infos->map1 = malloc(sizeof(char *) * (count + 1));
	c = 0;
	while (infos->map[++x])
	{
		infos->map1[c] = infos->map[x];
		c++;
	}
	infos->map1[c] = NULL;
}

int main(int argc, char **argv)
{
	t_info info;
	int i;
	int rgb;

	if (argc > 2)
		return (0);
	init(&info);
	info.fd = open(argv[1], O_RDONLY, 0777);
	if (info.fd < 0 || !ft_strstr(argv[1], ".cub"))
		printf("error in the extension!!\n");
	i = 0;
	rgb = (info.red << 16) | (info.green << 8) | (info.blue << 0);
	checkmap1(&info, &i);
	replace_map(&info, i);
	if (!checkmap(&info))
		return(0);
	if (!info.south && !info.east && !info.west && !info.north && !info.ceiling && !info.floor)
		printf("Wrong element!!\n");
	draw_map(&info);
	mlx_loop(info.mlx);
}