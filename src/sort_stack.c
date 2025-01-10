/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:38:43 by obarais           #+#    #+#             */
/*   Updated: 2025/01/10 11:29:40 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_1(t_stack **a, t_stack **b, int *start, int *end)
{
	push_ab_choose(&(*a), &(*b));
	rotate_ab(&(*b));
	write(1, "pb\nrb\n", 6);
	if (*start != *end)
		*start += 1;
	if (*end != ft_size_a(&(*a)))
		*end += 1;
}

static void	else_if_1(t_stack **a, t_stack **b, int *start, int *end)
{
	push_ab_choose(&(*a), &(*b));
	swap_a_b(&(*b));
	write(1, "pb\nsb\n", 6);
	if (*start != *end)
		*start += 1;
	if (*end != ft_size_a(&(*a)))
		*end += 1;
}

static void	ft_sort_1(t_stack **a, t_stack **b, int size, int *s)
{
	int		start;
	int		end;
	t_stack	*tmp;

	start = 0;
	end = ft_calcul_end(size);
	while (size != 0)
	{
		tmp = *a;
		if (tmp->content <= s[start])
		{
			if_1(&(*a), &(*b), &start, &end);
			size--;
		}
		else if (tmp->content <= s[end])
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
