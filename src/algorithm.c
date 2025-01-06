/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:19:49 by obarais           #+#    #+#             */
/*   Updated: 2025/01/06 11:34:58 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    position_big_int(t_stack **a)
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

static void    put_big_in_the_top(t_stack **b, t_stack **a)
{
    int i;
    int j = 0;
    int size;
    
    size = ft_size_a(&(*b));
    i = position_big_int(&(*b));
    if (i == size && i > 2)
    {
        reverse_r_ab(&(*b));
        write(1, "rrb\n", 4);
    }
    else if (i == 1)
    {
        (void)a;
        return ;
    }
    else if (i == 2)
    {
        swap_a_b(&(*b));
        write(1, "sb\n", 3);
    }
    else if (i <= size / 2)
    {
        while(j < i - 1)
        {
            rotate_ab(&(*b));
            write(1, "rb\n", 3);
            j++;
        }
    }
    else if (i > size / 2)
    {
        i = size - i + 1;
        while(j < i)
        {
            reverse_r_ab(&(*b));
            write(1, "rrb\n", 4);
            j++;
        }
    }
}

void    algorithm_sort_1(t_stack **a, t_stack **b)
{
    put_big_in_the_top(&(*b), &(*a));
    push_ab_choose(&(*b), &(*a));
    write(1, "pa\n", 3);
}