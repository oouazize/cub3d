/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:20:53 by oouazize          #+#    #+#             */
/*   Updated: 2022/06/20 15:07:06 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	int len;
	int len1;
	char *string;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	len1 = ft_strlen(s2);
	string = (char *)malloc((len + len1 + 1) * sizeof(char));
	if (string == NULL)
		return (0);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	return (string);
}
