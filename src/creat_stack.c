/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:45 by obarais           #+#    #+#             */
/*   Updated: 2025/01/12 17:29:02 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*creat_stack_suporte(t_stack **a, char **av, int i, t_stack *p)
{
	t_stack	*new_node;

	while (av[i])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->content = ft_atoi(av[i]);
		new_node->next = NULL;
		if (!p)
		{
			*a = new_node;
			p = *a;
		}
		else
		{
			p->next = new_node;
			p = p->next;
		}
		if (new_node->content > INT_MAX || new_node->content < INT_MIN)
			return (write(2, "Error\n", 6), NULL);
		i++;
	}
	return (*a);
}

t_stack	*creat_stack(t_stack **a, char **av)
{
	int		i;
	t_stack	*p;

	i = 0;
	p = NULL;
	if (error_stack(av) == 1)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (creat_stack_suporte(&(*a), av, i, p));
}
