/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:25 by obarais           #+#    #+#             */
/*   Updated: 2024/12/23 10:44:54 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
        return (1);
    if (ac == 2)
        av = ft_split(av[1], ' ');
    if((creat_stack(&a, av) == NULL))
    {
        write(1, "error\n", 6);
        return (1);
    }
    push_ab_choose(&a, &b);
    push_ab_choose(&a, &b);
    push_ab_choose(&a, &b);
    rrr_ab(&a, &b);
    while (a)
    {
        printf("%d\n", a->content);
        a = a->next;
    }
    while (b)
    {
        printf("%d\n", b->content);
        b = b->next;
    }

    return (0);
}