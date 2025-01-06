/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:38:43 by obarais           #+#    #+#             */
/*   Updated: 2025/01/06 16:18:33 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_sort_1(t_stack **a, t_stack **b, int size, int *s)
{
    int start;
    int end;
    t_stack *tmp;

    start = 0;
    end = ft_calcul_end(size);
    while (size != 0)
    {
        tmp = *a;
        if (tmp->content <= s[start])
        {
            push_ab_choose(&(*a), &(*b));
            write(1, "pb\n", 3);
            rotate_ab(&(*b));
            write(1, "rb\n", 3);
            if (start != end)
                start++;
            size--;
            if (end != size)
                end++;
        }
        else if (tmp->content <= s[end])
        {
            push_ab_choose(&(*a), &(*b));
            write(1, "pb\n", 3);
            swap_a_b(&(*b));
            write(1, "sb\n", 3);
            if (start != end)
                start++;
            size--;
            if (end != size)
                end++;
        }
        else
        {
            rotate_ab(&(*a));
            write(1, "ra\n", 3);
        }
    }
}

void	sort_stack(t_stack **a, t_stack **b)
{
    int size;
    int *s;
    int i;

    i = 0;
    size = ft_size_a(a);
    s = ft_sort_arr(*a, size);
    ft_sort_1(&(*a), &(*b), size, s);
    while (i < size)
    {
        algorithm_sort_1(&(*a), &(*b));
        i++;
    }
}