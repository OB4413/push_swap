/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:38:43 by obarais           #+#    #+#             */
/*   Updated: 2025/01/13 18:10:16 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_1(t_stack **a, t_stack **b, int *start, int *end)
{
	int	j;

	j = ft_size_a(&(*a)) + ft_size_a(&(*b));
	push_ab_choose(&(*a), &(*b));
	rotate_ab(&(*b));
	write(1, "pb\nrb\n", 6);
	if (*start < *end)
		*start += 1;
	if (*end < j - 1)
		*end += 1;
}

static void	else_if_1(t_stack **a, t_stack **b, int *start, int *end)
{
	int	j;

	j = ft_size_a(&(*a)) + ft_size_a(&(*b));
	push_ab_choose(&(*a), &(*b));
	write(1, "pb\n", 3);
	if (*start < *end)
		*start += 1;
	if (*end < j - 1)
		*end += 1;
}

static void	ft_sort_1(t_stack **a, t_stack **b, int size, int *s)
{
	int		start;
	int		end;

	start = 0;
	end = ft_calcul_end(size);
	while (size != 0)
	{
		if ((*a)->content <= s[start])
		{
			if_1(&(*a), &(*b), &start, &end);
			size--;
		}
		else if ((*a)->content <= s[end])
		{
			else_if_1(&(*a), &(*b), &start, &end);
			size--;
		}
		else
		{
			rotate_ab(&(*a));
			write(1, "ra\n", 3);
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	*s;
	int	i;

	i = 0;
	size = ft_size_a(a);
	s = ft_sort_arr(*a, size);
	ft_sort_1(&(*a), &(*b), size, s);
	while (i < size)
	{
		algorithm_sort(&(*a), &(*b));
		i++;
	}
	free(s);
}
