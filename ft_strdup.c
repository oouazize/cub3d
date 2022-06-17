/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <mmounib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:02:40 by mmounib           #+#    #+#             */
/*   Updated: 2022/06/11 10:27:46 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	int		l;
	char	*s2;

	i = 0;
	j = 0;
	l = 0;
	while (s1[l])
		l++;
	s2 = (char *)malloc(l + 1 * sizeof(char));
	if (s2 == NULL)
		return (0);
	while (s1[j])
		s2[i++] = s1[j++];
	s2[i] = '\0';
	return (s2);
}
