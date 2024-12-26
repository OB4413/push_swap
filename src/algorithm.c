/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:19:49 by obarais           #+#    #+#             */
/*   Updated: 2024/12/26 14:43:04 by obarais          ###   ########.fr       */
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

int    position_big_int(t_stack **a)
{
    t_stack *tmp;
    int     temp;
    int     i = 0;

    tmp = *a;
    temp = tmp->content;
    while (tmp->next)
    {
        tmp = tmp->next;
        if(temp < tmp->content)
            temp = tmp->content;
    }
    tmp = *a;
    while (tmp)
    {
        i++;
        if (temp == tmp->content)
            break;
        tmp = tmp->next;
    }
    return (i);
}

void    put_big_in_the_top(t_stack **a, t_stack **b)
{
    int i;
    int j = 0;
    int size;
    
    size = ft_size_a(&(*a));
    i = position_big_int(&(*a));
    if (i == size && i > 2)
    {
        reverse_r_ab(&(*a));
        write(1, "rra\n", 4);
    }
    else if (i == 1)
    {
        (void)b;
        return ;
    }
    else if (i == 2)
    {
        swap_a_b(&(*a));
        write(1, "sa\n", 3);
    }
    else if (i <= size / 2)
    {
        while(j < i - 1)
        {
            rotate_ab(&(*a));
            write(1, "ra\n", 4);
            j++;
        }
    }
    else if (i > size / 2)
    {
        i = size - i + 1;
        while(j < i)
        {
            reverse_r_ab(&(*a));
            write(1, "rra\n", 4);
            j++;
        }
    }
}

void    algorithm_sort(t_stack **a, t_stack **b)
{
    if(a && *a)
    {
        put_big_in_the_top(&(*a), &(*b));
        push_ab_choose(&(*a), &(*b));
        write(1, "pb\n", 4);
    }
}