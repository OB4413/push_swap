/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:33:40 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 11:23:08 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		swap_a_b(&(*a));
		ft_printf("sa\n");
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
			ft_printf("ra\n");
		}
		if (i == 2)
		{
			reverse_r_ab(&(*a));
			ft_printf("rra\n");
		}
		if ((*a)->content > (*a)->next->content)
		{
			swap_a_b(&(*a));
			ft_printf("sa\n");
		}
	}
}
