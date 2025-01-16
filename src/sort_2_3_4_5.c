/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_4_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:33:40 by obarais           #+#    #+#             */
/*   Updated: 2025/01/16 20:00:11 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_big_top(t_stack **a, int i, int size)
{
	int	j;

	j = 0;
	if (i <= size / 2)
	{
		while (j < i - 1)
		{
			rotate_ab(&(*a));
			write(1, "ra\n", 3);
			j++;
		}
	}
	else if (i > size / 2)
	{
		i = size - i + 1;
		while (j < i)
		{
			reverse_r_ab(&(*a));
			write(1, "rra\n", 4);
			j++;
		}
	}
}

void	sort_2(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		swap_a_b(&(*a));
		write(1, "sa\n", 3);
	}
}

void	sort_3(t_stack **a)
{
	int	i;

	while (check_sort(*a) == 1)
	{
		i = position_big_int(&(*a));
		if (i == 1)
		{
			rotate_ab(&(*a));
			write(1, "ra\n", 3);
		}
		if (i == 2)
		{
			reverse_r_ab(&(*a));
			write(1, "rra\n", 4);
		}
		if ((*a)->content > (*a)->next->content)
		{
			swap_a_b(&(*a));
			write(1, "sa\n", 3);
		}
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	i;

	i = position_big_int(&(*a));
	a_big_top(&(*a), i, ft_size_a(&(*a)));
	push_ab_choose(&(*a), &(*b));
	write(1, "pb\n", 3);
	sort_3(&(*a));
	push_ab_choose(&(*b), &(*a));
	rotate_ab(&(*a));
	write(1, "pa\nra\n", 6);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	i;

	i = position_big_int(&(*a));
	a_big_top(&(*a), i, ft_size_a(&(*a)));
	push_ab_choose(&(*a), &(*b));
	write(1, "pb\n", 3);
	sort_4(&(*a), &(*b));
	push_ab_choose(&(*b), &(*a));
	rotate_ab(&(*a));
	write(1, "pa\nra\n", 6);
}
