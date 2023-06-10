/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:50:41 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/10 14:19:11 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t ft_strlen(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		p++;
	}
	return (p - s);
}
void put_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
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
	if (result > 2147483647 && signe == 1)
		put_error("Error\n");
	if (result > 2147483648 && signe == -1)
		put_error("Error\n");
	return (signe * result);
}
