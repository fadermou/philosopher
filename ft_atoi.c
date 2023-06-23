/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:50:41 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/23 16:17:00 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
	{
		p++;
	}
	return (p - s);
}

int	ft_atoi(char *str)
{
	int				i;
	int				signe;
	unsigned long	result;

	result = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (result >= 9223372036854775807 && signe == 1)
		return (-1);
	if (result > 9223372036854775807 && signe == -1)
		return (0);
	return (signe * result);
}
