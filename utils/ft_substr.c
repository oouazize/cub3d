/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:21:25 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/30 19:03:06 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			length;
	char			*sbstr;
	char			*str;

	i = start;
	j = 0;
	str = (char *)s;
	length = len;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		length = ft_strlen(s);
	sbstr = (char *)malloc(((length) + 1) * sizeof(char));
	if (sbstr == NULL)
		return (0);
	while (j < length)
		sbstr[j++] = str[i++];
	sbstr[j] = '\0';
	return (sbstr);
}

void	ft_perror(void)
{
	printf("Error In The File!!\n");
	exit(0);
}

void	check_beg(char *line, char **temp, int *len, int fd)
{
	if (!line)
		ft_perror();
	while (line)
	{
		temp[(*len)++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	while (*len > 0 && !ft_isdigit(temp[--(*len)][0]))
	{
		if (ft_isalpha(&temp[(*len)][0]))
			ft_perror();
		free(temp[(*len)]);
		temp[(*len)] = NULL;
	}
}

void	check(int fd, int len, int count, int flag)
{
	char	*line;
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * 10000);
	line = get_next_line(fd);
	check_beg(line, temp, &len, fd);
	if (!temp[0])
		ft_perror();
	i = -1;
	while (++i < len)
	{
		if (flag && !ft_strcmp(temp[i], "\n"))
			ft_perror();
		if (ft_strcmp(temp[i], "\n"))
			count++;
		if (count == 7)
			flag = 1;
	}
	i = -1;
	while (++i <= len)
		free(temp[i]);
	free(temp);
}
