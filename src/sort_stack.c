/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:38:43 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 12:34:05 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// khasna n9smo 25 layn
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
			push_ab_choose(&(*a), &(*b));
			ft_printf("pb\n");
			rotate_ab(&(*b));
			ft_printf("rb\n");
			if (start != end)
				start++;
			size--;
			if (end != size)
				end++;
		}
		else if (tmp->content <= s[end])
		{
			push_ab_choose(&(*a), &(*b));
			ft_printf("pb\n");
			swap_a_b(&(*b));
			ft_printf("sb\n");
			if (start != end)
				start++;
			size--;
			if (end != size)
				end++;
		}
		else
		{
			rotate_ab(&(*a));
			ft_printf("ra\n");
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
