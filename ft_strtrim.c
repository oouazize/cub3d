/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <mmounib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:41:34 by mmounib           #+#    #+#             */
/*   Updated: 2022/06/13 12:38:43 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	find(char const str, char const *s)
{
	while (*s)
	{
		if (str == *s)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*cpy;
	int		length;
	int		l;

	i = 0;
	l = 0;
	if (!s1)
		return (0);
	length = ft_strlen(s1) - 1;
	while (i < length && find(s1[i], set))
		i++;
	while (length >= 0 && find(s1[length], set))
		length--;
	if (length < i)
		cpy = (char *)malloc (sizeof(char));
	else
		cpy = (char *)malloc((length - i + 2) * sizeof(char));
	if (cpy == NULL)
		return (0);
	while (i <= length)
		cpy[l++] = s1[i++];
	cpy[l] = '\0';
	return (cpy);
}
