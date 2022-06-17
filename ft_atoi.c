/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <mmounib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:25:34 by mmounib           #+#    #+#             */
/*   Updated: 2022/06/15 18:34:24 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	value;
	int					s;

	i = 0;
	value = 0;
	s = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13)
		|| str[i] == 32)
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s *= -1;
		if (str[i + 1] == '-' || str[i + 1] == '+')
			s = 0;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		value = (value * 10) + str[i++] - '0';
	return (s * value);
}
