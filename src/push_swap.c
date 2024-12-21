/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:25 by obarais           #+#    #+#             */
/*   Updated: 2024/12/20 09:29:11 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int tmp;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
        return (1);
    if (ac == 2)
        av = ft_split(av[1], ' ');
    creat_stack(&a, av);
    b = a;

    while (b && b->next)
    {
        if (b->next->content < b->content)
        {
            tmp = b->content;
            b->content = b->next->content;
            b->next->content = tmp;
        }
        b = b->next; 
    }

    while (a)
    {
        printf("%d\n", a->content);
        a = a->next;
    }

    return (0);
}