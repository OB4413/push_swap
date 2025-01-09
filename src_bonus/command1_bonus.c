/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:28:57 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 11:29:42 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a && *a)
	{
		tmp = *a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *a;
		*a = (*a)->next;
		tmp->next->next = NULL;
	}
	if (b && *b)
	{
		tmp = *b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *b;
		*b = (*b)->next;
		tmp->next->next = NULL;
	}
}

void	reverse_r_ab(t_stack **ab)
{
	t_stack	*tmp;
	t_stack	*p;

	if (ab && *ab)
	{
		tmp = *ab;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		p = tmp->next;
		tmp->next = NULL;
		p->next = *ab;
		*ab = p;
	}
}

void	rrr_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*p;

	if (a && *a)
	{
		tmp = *a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		p = tmp->next;
		tmp->next = NULL;
		p->next = *a;
		*a = p;
	}
	if (b && *b)
	{
		tmp = *b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		p = tmp->next;
		tmp->next = NULL;
		p->next = *b;
		*b = p;
	}
}
