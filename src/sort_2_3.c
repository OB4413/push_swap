/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:33:40 by obarais           #+#    #+#             */
/*   Updated: 2025/01/05 09:34:12 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_stack **a)
{
    if ((*a)->content > (*a)->next->content)
    {
        swap_a_b(&(*a));
        write(1, "sa\n", 3);
    }
}

void    sort_3(t_stack **a)
{
    if ((*a)->content > (*a)->next->content)
    {
        swap_a_b(&(*a));
        write(1, "sa\n", 3);
    }
    if ((*a)->content > (*a)->next->next->content)
    {
        reverse_r_ab(&(*a));
        write(1, "rra\n", 4);
    }
    if ((*a)->next->content > (*a)->next->next->content)
    {
        reverse_r_ab(&(*a));
        swap_a_b(&(*a));
        write(1, "ra\nsa\n", 3);
    }
}