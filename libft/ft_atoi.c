/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:27:40 by obarais           #+#    #+#             */
/*   Updated: 2025/01/16 17:30:07 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	size_t	i;
	int		a;
	long	num;

	i = 0;
	a = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = a * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num * a) > INT_MAX || (num *a) < INT_MIN)
			return (num * a);
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * a);
}
