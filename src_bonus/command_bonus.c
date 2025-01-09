/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:42:46 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 11:29:51 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a_b(t_stack **ab)
{
	int	tmp_content;

	if (ab && *ab && (*ab)->next)
	{
		tmp_content = (*ab)->content;
		(*ab)->content = (*ab)->next->content;
		(*ab)->next->content = tmp_content;
	}
}

void	swap_a_and_b(t_stack **a, t_stack **b)
{
	int	tmp_content;

	if (a && *a && (*a)->next)
	{
		tmp_content = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp_content;
	}
	if (b && *b && (*b)->next)
	{
		tmp_content = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp_content;
	}
}

void	push_ab_choose(t_stack **ab1, t_stack **ab2)
{
	t_stack	*tmp;

	if (ab1 && *ab1)
	{
		tmp = *ab1;
		*ab1 = (*ab1)->next;
		tmp->next = NULL;
		if (ab2)
		{
			tmp->next = *ab2;
		}
		*ab2 = tmp;
	}
}

void	rotate_ab(t_stack **ab)
{
	t_stack	*tmp;

	if (ab && *ab)
	{
		tmp = *ab;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = *ab;
		*ab = (*ab)->next;
		tmp->next->next = NULL;
	}
}
