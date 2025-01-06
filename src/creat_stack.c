/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:45 by obarais           #+#    #+#             */
/*   Updated: 2025/01/04 21:15:53 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *creat_stack(t_stack **a, char **av)
{
    t_stack *p = NULL;
    t_stack *new_node;
    int i;

    i = 0;
    if(error_stack(av) == 1)
    {
        write(1, "Error\n", 6);
        return (NULL);
    }
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