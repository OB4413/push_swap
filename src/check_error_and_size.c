/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_and_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:36:25 by obarais           #+#    #+#             */
/*   Updated: 2025/01/05 09:36:28 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_size_a(t_stack **a)
{
    t_stack *tmp;
    int     i;
    
    i = 0;
    tmp = *a;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

int     check_sort(t_stack *a)
{
    if (a == NULL)
        return (1);
    while (a->next)
    {
        if (a->content > a->next->content)
            return (0);
        a = a->next;
    }
    return (1);
}

int    error_stack(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == '-' && av[i][j + 1] == '\0')
                return (1);
            if (av[i][j] == '-' && av[i][j + 1] != '\0')
                j++;
            if (av[i][j] < '0' || av[i][j] > '9')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
