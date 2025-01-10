/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:45 by obarais           #+#    #+#             */
/*   Updated: 2025/01/10 10:43:06 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*creat_stack_suporte(t_stack **a, char **av, int i)
{
	t_stack	*p;
	t_stack	*new_node;

	p = NULL;
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
		i++;
	}
	return (*a);
}

t_stack	*creat_stack(t_stack **a, char **av)
{
	int	i;

	i = 0;
	if (error_stack(av) == 1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (creat_stack_suporte(&(*a), av, i));
}
