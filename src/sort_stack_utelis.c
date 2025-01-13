/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utelis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:43:33 by obarais           #+#    #+#             */
/*   Updated: 2025/01/13 15:49:20 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_smol_big(int size, int *arr)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*ft_sort_arr(t_stack *a, int size)
{
	int	*arr;
	int	*b;
	int	i;

	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = a->content;
		a = a->next;
		i++;
	}
	b = ft_smol_big(size, arr);
	return (b);
}

// calcul the end
int	ft_calcul_end(int size)
{
	if (size <= 16)
		return (3);
	else if (size <= 100)
		return (16);
	else if (size <= 500)
		return (35);
	else
		return (50);
}
