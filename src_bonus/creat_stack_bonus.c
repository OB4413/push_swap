/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:42:38 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 11:32:48 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*creat_stack_suporte(t_stack **a, char **av)
{
	t_stack	*p;
	t_stack	*new_node;
	int		i;

	p = NULL;
	i = 0;
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
	if (error_stack(av) == 1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (creat_stack_suporte(&(*a), av));
}
