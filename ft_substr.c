/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <mmounib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:09:34 by mmounib           #+#    #+#             */
/*   Updated: 2022/06/11 10:27:25 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
